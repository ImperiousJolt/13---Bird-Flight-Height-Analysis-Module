function notDone_push_Callback(hObject, eventdata, handles)
global Birds fb_input_data bird_no current_row xlspathname xlsfilename

answer = questdlg('Are you sure you want to mark this bird as "Not Done"?',...
    'Marking Not Done','Yes','No','Yes');
if strcmp(answer,'Yes')
    Birds{bird_no}.er{9} = 13009;
    Birds{bird_no}.skip = true;
    Birds{bird_no}.possible = false;
    fb_input_data{current_row,5}='Not Done';
else
    return
end

% Clear Bird
Fields = {'Frame'; 'frame_range'; 'Translation'};
Birds{bird_no} = rmfield(Birds{bird_no},Fields(isfield(Birds{bird_no},Fields)));

Birds{bird_no}.possible = false;

% Reset frame number
birdFrame = 0;
assignin('base','birdFrame',birdFrame);

% Set UI
set(handles.bird_loc_table,'data',fb_input_data);
set(handles.Bird_Frame_Number_Field,'String',birdFrame);

% Create mat file after each bird is completed.
save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');

bird_loc_input_auto_refresh(handles);

