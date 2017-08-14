function reset_bird_Callback(hObject, eventdata, handles)
global Birds fb_input_data bird_no current_row xlspathname xlsfilename 

% Calls confirm window and waits for the response
answer =    questdlg('Confirm Reset Bird','Confirm?','Confirm',...
    'Cancel','Confirm');
if strcmp(answer,'Confirm')
    assignin('base','Confirm_Boolean',1);
else
    assignin('base','Confirm_Boolean',0);
end
%uiwait(ConfirmResetBird);

if evalin('base','Confirm_Boolean') == 1
    
    
    fb_input_data{current_row,5}='No';

    BirdsTemp = [];
    birdsCount = 0;
    
    for b=1:size(Birds, 2)
        if ~isempty(Birds{b})
            birdsCount = birdsCount +1;
            BirdsTemp{birdsCount} = Birds{b};
        end
    end
    
    Birds = BirdsTemp;
    
    BirdsTemp = [];
    birdsCount = 0;
    
    for b=1:size(Birds, 2)
        if ~exist('Birds{bird_no}', 'var')%need to work out how to not delete birds that dont want deleted
            if(Birds{b}.Marker_Number == Birds{bird_no}.Marker_Number && Birds{b}.Frame_Number == Birds{bird_no}.Frame_Number)
                Birds{b} = [];
            end
        
            if ~isempty(Birds{b})
                birdsCount = birdsCount +1;
                BirdsTemp{birdsCount} = Birds{b};
            end
            if isempty(Birds{b})
                break;
            end
        end
    end
    
    Birds = BirdsTemp;
    
            % Clear Bird
    Fields = {'Frame'; 'frame_range'; 'Translation'; 'possible' ; 'er'; 'error'; 'skip'};
    
    if exist('Birds{bird_no}', 'var')
        Birds{bird_no} = rmfield(Birds{bird_no},Fields(isfield(Birds{bird_no},Fields)));
    end
    
    % Reset frame number
    birdFrame = 0;
    assignin('base','birdFrame',birdFrame);
    
    % Set UI
    set(handles.bird_loc_table,'data',fb_input_data);
    set(handles.Bird_Frame_Number_Field,'String',birdFrame);
    
    % Create mat file after each bird is completed.
    save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');
    
    bird_loc_input_auto_refresh(handles);
end

