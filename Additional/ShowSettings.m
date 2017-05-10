function varargout = ShowSettings(varargin)
% SHOWSETTINGS MATLAB code for ShowSettings.fig
%      SHOWSETTINGS, by itself, creates a new SHOWSETTINGS or raises the existing
%      singleton*.
%
%      H = SHOWSETTINGS returns the handle to a new SHOWSETTINGS or the handle to
%      the existing singleton*.
%
%      SHOWSETTINGS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SHOWSETTINGS.M with the given input arguments.
%
%      SHOWSETTINGS('Property','Value',...) creates a new SHOWSETTINGS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ShowSettings_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ShowSettings_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ShowSettings

% Last Modified by GUIDE v2.5 18-Aug-2015 16:20:52

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ShowSettings_OpeningFcn, ...
                   'gui_OutputFcn',  @ShowSettings_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function ShowSettings_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ShowSettings (see VARARGIN)

iconPath = 'HiDefIcon.jpg';
if exist(iconPath,'file')
    im = imread(iconPath);
    javaIm = im2java(im);
    warning('off','MATLAB:HandleGraphics:ObsoletedProperty:JavaFrame');
    jframe = get(handles.ChangeSetsFig,'javaframe');
    jlcon = javax.swing.ImageIcon(javaIm);
    jframe.setFigureIcon(jlcon);
    warning('on','MATLAB:HandleGraphics:ObsoletedProperty:JavaFrame');
end

% Choose default command line output for ShowSettings
handles.output = hObject;

if nargin == 5
    filter = varargin{2};
    set(handles.thisMod,'UserData',filter);
else
    set(handles.thisMod,'Value',0,'Enable','Off')
end

PopulateSettings(varargin{1},handles);


% Update handles structure
guidata(hObject, handles);

function varargout = ShowSettings_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

function settingsList_Callback(hObject, eventdata, handles) %#ok<*DEFNU>
% hObject    handle to settingsList (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns settingsList contents as cell array
%        contents{get(hObject,'Value')} returns selected item from settingsList
selection = (get(hObject,'Value') - 1);
set(handles.settingsStatusText,'Visible','Off');
if selection
    moduleSettings = get(handles.settingsList,'UserData');
    settingName = moduleSettings{selection,1};
    settingValue = moduleSettings{selection,2};
    set(handles.settingDisp,'String',settingValue);
    set(handles.redefine_Push,'Enable','On','UserData',settingName);
    %set(handles.settingDisp,'UserData',selection);
else
    set(handles.settingDisp,'String','');
    set(handles.redefine_Push,'Enable','Off');
end

function settingsList_CreateFcn(hObject, eventdata, handles) %#ok<*INUSD>
% hObject    handle to settingsList (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function redefine_Push_Callback(hObject, eventdata, handles) %#ok<*INUSL>
% hObject    handle to redefine_Push (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
settingName = get(handles.redefine_Push,'UserData');
try
    moduleSettings = GetSettings('Change',settingName);
catch err
    if strcmp(err.identifier,'GetSet:MainBreak') || strcmp(err.identifier,'GetSet:Defaults')
        %warning('GetSet:ErrTrap',err.message)
        return
    else
        rethrow(err)
    end
end
set(handles.redefine_Push,'Enable','Off');
PopulateSettings(moduleSettings,handles);
selection = (get(handles.settingsList,'Value') - 1);
%selection = get(handles.settingDisp,'UserData');
newSetting = moduleSettings{selection,2};
set(handles.settingDisp,'String',newSetting);
set(handles.settingsStatusText,'Visible','On','String','Setting changed');

function settingDisp_Callback(hObject, eventdata, handles)

function settingDisp_CreateFcn(hObject, eventdata, handles)
% hObject    handle to settingDisp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function PopulateSettings(moduleSettings,handles)
% Populate the drop down menu with settings

modOnly = get(handles.thisMod,'Value');
filter = get(handles.thisMod,'UserData');
if modOnly
    numSettings = sum(filter);
    filteredList = cell(numSettings,2);
else
    numSettings = size(moduleSettings,1);
end
setList = cell(numSettings+1,1);
setList{1} = 'Select:';
m = 2;
for n = 1 : size(moduleSettings,1)
    if modOnly && filter(n)
        setList{m} = moduleSettings{n,1};
        filteredList(m-1,:) = moduleSettings(n,:);
        set(handles.settingsList,'UserData',filteredList);
        m = m + 1;
        continue
    elseif ~modOnly
        setList{n+1} = moduleSettings{n,1};
        set(handles.settingsList,'UserData',moduleSettings);
        continue
    end
end
set(handles.settingsList,'String',setList);
set(handles.settingDisp,'UserData',moduleSettings);

function viewChangeLog_Callback(hObject, eventdata, handles)
if exist('change_log.txt','file')
    popupmessage('change_log.txt','Change Log');
end

function thisMod_Callback(hObject, eventdata, handles)
set(handles.settingsList,'Value',1);
set(handles.settingDisp,'String','');
set(handles.redefine_Push,'Enable','Off');
moduleSettings = get(handles.settingDisp,'UserData');
PopulateSettings(moduleSettings,handles);

function showGuide_Callback(hObject, eventdata, handles)
if exist('UserGuide.txt','file')
    popupmessage('UserGuide.txt','User Guide');
end
