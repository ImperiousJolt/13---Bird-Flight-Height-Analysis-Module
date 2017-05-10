function varargout = GetSettings(varargin)
%% Returns setting values from predefined string names.
%   e.g. \\HDFS01\Templates\ = GetSettings('Templates')

%   ALWAYS UPDATE MODULE FILE FROM MASTER FILE - don't want multiple
%   versions.

%   Directory settings will always be returned as \dir\ rather than \dir.

%   If a setting cannot be retreived an error is thrown. It's assumed that
%   a missing setting means the module won't work.

%   To change a setting, GetSettings('Change','Templates'); This is the
%   same function the ShowSettings GUI calls when the user selects a
%   setting. GUI is just a tool for showing and selecting a setting, all
%   the settings are set from this file.

% Settings file in same location as [module].exe will be used over AppData
settingsFile = 'module_settings.mat';
settingsExist = exist(settingsFile,'file');
appDataSettings = false;
try
    allAppDir = winqueryreg('HKEY_CURRENT_USER',...
                ['Software\Microsoft\Windows\CurrentVersion\' ...
                'Explorer\Shell Folders'],'Local AppData');
    saveLoc = [allAppDir '\HiDefModules\'];
catch %#ok<CTCH>
    % Old way of getting appdata - above is more elegant
    username = getenv('USERNAME');
    saveLoc = ['C:\Users\' username '\AppData\Local\HiDefModules\'];
end
if ~settingsExist,
    % If not, try %AppData\Local%
    appDataSettings = true;
    settingsFile = [saveLoc settingsFile];
    settingsExist = exist(settingsFile,'file');
end

updateSettings = false;
reShow = false;
broken = false;
varsIn = nargin;

% Load module, check it has settings stored
if settingsExist
    load(settingsFile,'moduleSettings');
    [~,warnID] = lastwarn;
    if strcmp(warnID,'MATLAB:load:variableNotFound')
        disp('No settings found in file.')
        lastwarn(''); % Reset last warn if used multiple times
        settingsExist = false;
    end
end

% Go to different function if 
if strcmpi(varargin{1},'Show') && settingsExist
    if varsIn == 2
        modNumb = varargin{2};
        filter = FilterList(modNumb,moduleSettings);
        % filter list should be a separate list for showing 
        ShowSettings(moduleSettings,filter);
    else
        ShowSettings(moduleSettings);
    end
    return
elseif strcmpi(varargin{1},'Show')
    choice = questdlg('No settings file found to change. Use defaults?',...
        'No settings found','Yes','Cancel','Yes');
    if strcmp(choice,'Yes')
        moduleSettings = {};
        [moduleSettings,broken] = UseDefaults(moduleSettings);
        if broken
            return
        end
        updateSettings = true;
        reShow = true;
    else
        return
    end
end

if (strcmpi(varargin{1},'Change')) && settingsExist
    [moduleSettings,broken] = ChangeSetting(moduleSettings,varargin{2});
    updateSettings = true;
    changeSet = true;
elseif strcmpi(varargin{1},'Change')
    warning('GetSet:NoSet',['No settings file found to change.'...
        ' Run module to populate settings.'])
    return
else
    changeSet = false;
end
    
% Match setting inputs to those in file
if settingsExist && ~changeSet
    varargout = cell(varsIn);
    notFound = zeros(varsIn,1); % List of all missing settings
    CheckSettings
    
    % Check if any settings were missing
    if updateSettings
        MissingSettings
    end
elseif ~changeSet && ~reShow
    % No settings file exists, populate all settings
    notFound = ones(varsIn,1);
    updateSettings = true;
    moduleSettings = {};
    MissingSettings
end

% Update settings file if settings were changed
if updateSettings && ~broken
    if appDataSettings && ~exist(allAppDir,'dir')
        msgbox('Could not find \AppData\Local\, saving to current directory instead',...
            'No Local Directory','warn');
        appDataSettings = false;
    end
    try
        if appDataSettings
            if ~exist(saveLoc,'dir')
                mkdir(saveLoc);
            end
            save([saveLoc 'module_settings.mat'],'moduleSettings');
        else
            save('module_settings.mat','moduleSettings');
        end
    catch err
        if strcmp(err.identifier,'MATLAB:save:permissionDenied')
            if ~exist(saveLoc,'dir')
                mkdir(saveLoc);
            end
            save([saveLoc 'module_settings.mat'],'moduleSettings');
            msgbox(['Settings saved to ' saveLoc 10 'Note: settings files'...
                ' in the module directory will take precedence over those in'...
                ' \AppData\'],'Settings saved','help');
        else
            throw(err);
        end
    end
    if changeSet
        varargout{1} = moduleSettings;
    elseif reShow
        if varsIn == 2
            modNumb = varargin{2};
            filter = FilterList(modNumb,moduleSettings);
            % filter list should be a separate list for showing
            ShowSettings(moduleSettings,filter);
        else
            ShowSettings(moduleSettings);
        end
    end
elseif broken
    error('GetSet:MainBreak','Unable to retreive settings, current process aborted. If user aborted please retry.');
end
%% END OF BODY OF MAIN FUNCTION - NESTED FUNCTIONS BELOW

    function CheckSettings
        for varCount = 1 : varsIn
            [matched,varargout{varCount}] = MatchSettingName(varargin{varCount},moduleSettings);
            if ~matched
                notFound(varCount) = true;
                updateSettings = true;
            end
        end
    end % Function: CheckSettings

    function MissingSettings
        missingList = '';
        for missingCount = 1 : length(notFound)
            if notFound(missingCount)
                missingList = [missingList ' "' varargin{missingCount} '"']; %#ok<AGROW>
            end
        end
        disp(['The following required settings were not found:' missingList]);
        prompt = 'Detected missing module settings - add settings or abort?';
        answer = questdlg(prompt,'Missing Settings','Use Defaults','Add manually','Abort','Use Defaults');
        switch answer
            case 'Add manually'
                for varCount2 = 1 : length(notFound)
                    if notFound(varCount2)
                        [moduleSettings,broken] = AddSettings(moduleSettings,varargin{varCount2},false);
                        CheckSettings;
                    end
                end
            case 'Use Defaults'
                [moduleSettings,broken] = UseDefaults(moduleSettings);
                notFound = zeros(varsIn,1);
                CheckSettings;
                if broken
                    return
                elseif any(notFound)
                    error('GetSet:Defaults',['No default values found for required '...
                        'setting(s), please add manually.']);
                end
            otherwise
                disp('Configure settings aborted by user.');
                broken = true;
        end
    end % Function: MissingSettings
end % Function: GetSettings


% When inputting or using settings, use data validation to check that
% values are what would be expected.
function [matched,value] = MatchSettingName(inputForMatch,moduleSettings)
%% Find the setting in the settings cell array
numSettings = size(moduleSettings,1);
matched = false;
for search = 1 : numSettings
    if strcmp(inputForMatch,moduleSettings{search,1})
        matched = search;
        value = moduleSettings{search,2};
        break;
    end
end
if ~matched
    value = false;
end
end % Function: MatchSettingName

function [moduleSettings,broken] = AddSettings(moduleSettings,settingName,changeRow)
%% Add settings to an existing settings file
if ~changeRow
    lastRow = size(moduleSettings,1)+1;
    changeRow = lastRow;
end
broken = false;

% To add settings: case 'SettingName', settingType = check GetNewSetting
% message = 'Something to guide user to appropriate input'
switch settingName
    case 'Templates'
        settingType = 1; % dir
        message = 'Please set the templates root directory (e.g. \\HDFS01\Templates)';
    case 'Projects'
        settingType = 1;% dir
        message = 'Please set the projects root directory (e.g. \\HDFS01\Projects)';
    case 'Resources'
        settingType = 1; % dir
        message = 'Please set the resources root directory (e.g. \\HDFS01\Resources)';
    case 'ID Data'
        settingType = 1; % dir
        message = 'Please set the ID Data root directory (e.g. \\HDFS01\ID_Data)';
    case 'Review Data'
        settingType = 1; % dir
        message = 'Please set the Review Data root directory (e.g. \\HDFS01\Review_Data)';
    case 'Classifier Threshold'
        settingType = 5; % double
        message = 'Please input a number for the Bird Classifier Threshold (e.g. 0.98)';
    case 'Run Classifier'
        settingType = 6; % boolean
        message = 'Run the Bird Classifier in Review Data Processing? (Module 6)?';
    case 'Bird Height'
        settingType = 1; % dir
        message = 'Please set the bird height root directory (e.g. \\HDFS01\BirdHeight)';
    case 'GSR'
        settingType = 5; % double
        message = 'Please set the GSR to strip width conversion factor (e.g. 62.5)';
    case 'Aircraft Rig'
        settingType = 7; % questdlg
        message = 'Select aircraft rig:';
        choices = {'DA42','Generic','Gen1'}; % Generic = PN68, Gen1 = USA
    case 'BH format'
        settingType = 7; % questdlg
        message = 'What format flight heights do you want?';
        choices = {'Actual','Bands','Auto (actual)'}; % Cancel will also be actual
    case 'Altitude'
        settingType = 5; % double
        message = 'Please enter a default survey altitude in feet (e.g. 1800):';
    case 'Full BH Info'
        settingType = 6; % boolean
        message = 'Export error codes, speed and direction in module 12?';
    case 'Start/End data'
        settingType = 6; % boolean
        message = 'Export all Start/End markers in module 10?';
        
    otherwise
        settingType = 0;
end % Switch on setting names

GetNewSetting;
if ~settingValue
    disp(['Alter settings for ' settingName... 
        ' aborted due to no user input or missing definitions.'...
        ' Retry or fix to run module.']);
    broken = true;
    return;
end
moduleSettings{changeRow,1} = settingName;
moduleSettings{changeRow,2} = settingValue;


    function GetNewSetting
        % settingValue = 0 is the error case, avoid allowing this value
        switch settingType
            case 0
                % Error case
                msgbox(['Unable to find definitions for the setting: ' settingName...
                    '. Code error, please contact HiDef.'],'Undefined setting','error');
                settingValue = false;
                return
            case 1
                % Folder/directory
                disp(message);
                settingValue = uigetdir('',message);
                if settingValue % Directory names as '\dir\' not '\dir'
                    settingValue = [settingValue '\'];
                end
            case 2
                % File, .xls
                disp(message)
                settingValue = uigetfile('*.xls',message);
            case 3
                % File, .xlsx
                disp(message)
                settingValue = uigetfile('*.xlsx',message);
            case 4
                % File, .mat
                disp(message)
                settingValue = uigetfile('*.mat',message);
            case 5
                % Double
                disp(message)
                settingValue = inputdlg(message);
                settingValue = str2double(settingValue);
                if isnan(settingValue)
                    settingValue = 0;
                end
            case 6
                % Boolean
                disp(message)
                settingValue = questdlg(message,'Select one:','Yes','No','Yes');
                if isempty(settingValue)
                    settingValue = false;
                end
            case 7
                % String choice (3 max)
                disp(message)
                settingValue = questdlg(message,'Select one:',...
                    choices{1},choices{2},choices{3},choices{1});
                if isempty(settingValue)
                    settingValue = false;
                end
            case 8
                % String entered
                disp(message)
                settingValue = inputdlg(message,'Setting input:');
        end
    end % Function: GetNewSetting
end % Function: AddSettings

function [moduleSettings,broken] = UseDefaults(moduleSettings)
%% Overwrite all settings with defaults for detected server
% Defaults are available for \\HDFS01\ and \\HDLX01\
broken = false;
systemFound = false;
if exist('\\HDFS01\Resources\','dir')
    systemFound = true;
    moduleSettings = {'Projects','\\HDFS01\Projects\';...
        'Templates','\\HDFS01\Templates\';...
        'Resources','\\HDFS01\Resources\';...
        'ID Data','\\HDFS01\ID_Data\';...
        'Review Data','\\HDFS01\Review_Data\';...
        'Bird Height','\\HDFS01\BirdHeight\';...
        'Classifier Threshold',0.98;...
        'Run Classifier','No';...
        'GSR',62.5;...
        'Aircraft Rig','DA42';...
        'BH format','Actual';...
        'Altitude','1800';...
        'Full BH Info','Yes';...
        'Start/End data','No'};
elseif exist('\\HDLX01\Resources\','dir')
    systemFound = true;
        moduleSettings = {'Projects','\\HDLX01\Projects\';...
        'Templates','\\HDLX01\Templates\'
        'Resources','\\HDLX01\Resources\';...
        'ID Data','\\HDLX01\ID_Data\';...
        'Review Data','\\HDLX01\Review_Data\';...
        'Bird Height','\\HDLX01\BirdHeight\';...
        'Classifier Threshold',0.98;...
        'Run Classifier','No';...
        'GSR',62.5;...
        'Aircraft Rig','Generic';...
        'BH format','Actual';...
        'Altitude','1800';...
        'Full BH Info','No';...
        'Start/End data','Yes'};
end

if ~systemFound
    msgbox('There are no default settings for this system, please enter manually.',...
        'No Defaults','warn');
    broken = true;
end
end  % Function:UseDefaults

function filter = FilterList(modNumb,moduleSettings)
%% Creates a list of whether or not this setting is used in this module
filter = zeros(size(moduleSettings,1),1);
switch modNumb
    case 'Mod01' % Project File Generation
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Projects')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod02' % Survey File Generation
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Review Data') || ...
                    strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'ID Data') || ...
                    strcmp(moduleSettings{n,1},'Projects')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod04' % Camera Direction
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Projects')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod05' % Review Audit
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Templates')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod06' % Review Data Processing
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'ID Data') || ...
                    strcmp(moduleSettings{n,1},'Projects') || ...
                    strcmp(moduleSettings{n,1},'Classifier Threshold') || ...
                    strcmp(moduleSettings{n,1},'Run Classifier')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod08'
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Resources')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod09'
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Resources')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod10' % ID Results Processing
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'Bird Height') || ...
                    strcmp(moduleSettings{n,1},'Projects') || ...
                    strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Review Data') || ...
                    strcmp(moduleSettings{n,1},'Start/End data')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod12'
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'Templates') || ...
                    strcmp(moduleSettings{n,1},'Aircraft Rig') || ...
                    strcmp(moduleSettings{n,1},'GSR') || ...
                    strcmp(moduleSettings{n,1},'Full BH Info')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    case 'Mod14'
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Bird Height') || ...
                    strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'Review Data') || ...
                    strcmp(moduleSettings{n,1},'BH format') || ...
                    strcmp(moduleSettings{n,1},'Altitude') || ...
                    strcmp(moduleSettings{n,1},'Full BH Info')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
     case 'Mod14b'  % Special case, mod for licensees. Snip off full BH here at the start.
        for n = 1 : size(moduleSettings,1)
            if      strcmp(moduleSettings{n,1},'Bird Height') || ...
                    strcmp(moduleSettings{n,1},'Resources') || ...
                    strcmp(moduleSettings{n,1},'Review Data') || ...
                    strcmp(moduleSettings{n,1},'BH format') || ...
                    strcmp(moduleSettings{n,1},'Altitude')
                filter(n) = true;
            else
                filter(n) = false;
            end
        end
    otherwise
        msgbox('The specific settings this module uses are not known.',...
            'No Filter List','error');
        return
end
end % Function:FilterList

function [moduleSettings,broken] = ChangeSetting(moduleSettings,settingName)
%% Change existing individual settings in the file
[matched,~] = MatchSettingName(settingName,moduleSettings);
if ~matched
    broken = true;
else
    [moduleSettings,broken] = AddSettings(moduleSettings,settingName,matched);
end
end
