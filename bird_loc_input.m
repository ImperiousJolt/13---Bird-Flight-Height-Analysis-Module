function bird_loc_input(handles)
global Birds brightness bird_input fb_input_data xlsfilename xlspathname num_birds original_birds List

Birds = [];
fb_input_data={};
List = {};
brightness = 1;
lp = 1;

%set birdframe to 0;
evalin('base','birdFrame=0;');
%define points matrix;
evalin('base','points=[];');

%get radio button value
[file, path] = uigetfile({'*.xlsx','Excel Files (*.xlsx)'}, 'Select the excel file', xlspathname );
if file == 0
    %create messagebox
    msgbox('No spreadsheet selected.','No Spreadsheet Selected','help')
    return
else
    
    xlspathname = path;
    xlsfilename = file;
    
    set(handles.xlsdir,'string', xlsfilename);
    
    %{
    % Obsolete HiDef Inc data:
    behaviourCol = 13;
    markerCol = 10;
    reelCol = 5;
    frameCol = 8;
    xCol = 29;
    yCol = 30;
    %}
    
    reelCol = 5;
    frameCol = 8;
    markerCol = 10;
    behaviourCol = 11;
    speciesCol = 12;
    flightHeightCol = 19; %wayne%
    xCol = 30;
    yCol = 31;
    
    checkFile = 'BirdsList.mat';
    if exist(checkFile,'file')
        load(checkFile,'birdsList');
        zoneCheck = birdsList.zone;
        bhList = birdsList.bhList;
        if strcmp(xlsfilename(5:6),zoneCheck)
            useList = true;
        else
            useList = false;
        end
    else
        useList = false;
    end
    
    
    [~,~,bird_input] = xlsread([xlspathname, xlsfilename],1,'','basic');
    
    fileFound = false;
    if exist([xlspathname xlsfilename(1:end-5) '.mat'],'file')
        fileFound = true;
        load([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');
        if ~isempty(Birds)
            empty_elems = cellfun(@(s) max(~isfield(s,{'Reel_Number','Frame_Number','Marker_Number','possible'})), Birds);
            Birds(empty_elems) = [];
            Birds = CheckBirdsIntegrity(Birds);
            save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');
        end
    else
        Birds = [];
    end
    
    
    % Set bird_no for next bird after those which already exist.
    original_birds = numel(Birds);
    set(handles.Bird_Number_Field,'String',num2str(0));
    
    p = 0;
    filter = false;
    
    for n=1:size(bird_input,1)
        
        if ~isempty(strfind(lower(bird_input{n,behaviourCol}),'flying'));
            markedEr = false;
            markedErCode = [];
            
            found = 0;
            
            if max(isnan(bird_input{n,markerCol}))
                bird_input{n,markerCol} = str2double([num2str(bird_input{n,frameCol}) num2str(n)]);
            end
            
            if fileFound
                o = 1;
                while o <= numel(Birds)
                    
                    if      ~isfield(Birds{o},'Frame_Number') || ...
                            ~isfield(Birds{o},'Marker_Number') || ...
                            ~isfield(Birds{o},'Reel_Number')
                        Birds(o) = [];
                        disp('Deleting saved bird with missing data');
                        o = o - 1;
                    end
                    try
                        if      (strcmp(bird_input{n,reelCol}, Birds{o}.Reel_Number) && ...
                                (bird_input{n,frameCol} ==  Birds{o}.Frame_Number) && ...
                                max(bird_input{n,markerCol} ==  Birds{o}.Marker_Number))
                            found = 1;
                            if isfield(Birds{o},'er')
                                markedEr = true;
                                markedErCode = Birds{o}.er;
                            end
                            break
                        end
                    catch  %#ok<*CTCH>
                        % Should now be redundant
                        disp([bird_input{n,reelCol} ' : ' num2str(bird_input{n,frameCol}) ' : ' ...
                            num2str(bird_input{n,markerCol}) ' has data missing.']);
                        Birds(o) = [];
                        o = o - 1;
                    end
                    o = o + 1;
                end
            end
            
            % Check bird species against a list
            if useList && ~found
                filter = true;
                for i = 1 : numel(bhList)
                    if strcmpi(bhList{i},bird_input{n,speciesCol})
                        filter = false;
                        break
                    end
                end
                
                % Filtered birds will be marked as not done
                if filter
                    nextBird = length(Birds) + 1;
                    Birds{nextBird}.Reel_Number = bird_input(n,reelCol);
                    Birds{nextBird}.Frame_Number = bird_input{n,frameCol};
                    Birds{nextBird}.Marker_Number = bird_input{n,markerCol};
                    Birds{nextBird}.possible = false;
                    Birds{nextBird}.skip = true;
                    Birds{nextBird}.error = 13007;
                    Birds{nextBird}.er{7} = 13007;
                end
            end
            
            if ~found && ~filter
%                 p = p + 1;
                markerNum = bird_input{n,markerCol};
               
                flightHeightColumn = bird_input{n,flightHeightCol};
                if isnan(flightHeightColumn)
                    p = p + 1;
                   fb_input_data(p,:) = {n; markerNum; bird_input{n,reelCol}; bird_input{n,frameCol}; ...
                    'No'; bird_input{n,xCol}; bird_input{n,yCol}; 0}; %#ok<*AGROW>
                end %Wayne%
                
                if strcmp(fb_input_data(p,5),'No')
                    List(lp,:) = fb_input_data(p,:);  
                
                lp = lp+1;
                end
                
            end
            
            if markedEr
                for c = 1 : numel(markedErCode)
                    if ~isempty(markedErCode{c})
                        if markedErCode{c} == 13009
                            writeEr = 'Not Done';
                        else
                            writeEr = ['EC:' num2str(markedErCode{c})];
                        end
                    end
                end
                p = p + 1;
                
                markerNum = bird_input{n,markerCol};
                fb_input_data(p,:) = {n; markerNum; bird_input{n,reelCol}; bird_input{n,frameCol}; ...
                    writeEr; bird_input{n,xCol}; bird_input{n,yCol}; 0};
                
                if strcmp(fb_input_data(p,5),'No')
                    List(lp,:) = fb_input_data(p,:);  
                
                lp = lp+1;
                end
            end
            
        end
    end
    
    fb_input_data = List;
    num_birds = numel(Birds);
    set(handles.bird_loc_table,'data',fb_input_data);
    save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');
    
end
