function input_push_Callback(hObject, eventdata,handles)
% Gets input x and y coordinates from the frame, ginput(2) takes two inputs
% for the head and the tail.

global Birds fb_input_data bird_no current_row firstBirdMarkedPlaced

pan off;
zoom off;

birdFrame=evalin('base','birdFrame')+1;

panning = get(handles.Pan,'State');
autoFrames = get(handles.AutoFrames,'State');
if isempty(current_row)
    msgbox('You must select a bird first','Nothing Selected','warn');
    return
end


if strcmp(fb_input_data(current_row,5),'Yes') || strcmp(fb_input_data(current_row,5),'Not Possible')
    
    % Are you sure you want overwrite bird?
    cont = questdlg('Are you sure you want to overwrite this Bird?', 'Overwrite Bird?', 'Yes');
    
    switch cont,
        case 'Yes',
            % Set result to 'No' so it wont come back here
            fb_input_data{current_row,5} = 'No';
            % Update table
            set(handles.bird_loc_table,'data',fb_input_data);
            % Clear Bird
            Fields = {'Frame'; 'frame_range'; 'Translation'; 'possible' ; 'er'; 'error'; 'skip'};
            Birds{bird_no} = rmfield(Birds{bird_no},Fields(isfield(Birds{bird_no},Fields)));
            % Rerun function
            input_push_Callback(hObject, eventdata, handles);
        case 'No',
            return
    end %switch
    
else
     
    firstBirdMarkedPlaced = 0;
    set(gcf,'WindowButtonDownFcn',{@wbdcb,gcf,birdFrame,handles,panning,autoFrames, hObject, eventdata});
    
    

    
   
end

