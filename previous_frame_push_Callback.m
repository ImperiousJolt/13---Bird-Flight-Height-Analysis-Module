function previous_frame_push_Callback(hObject, eventdata, handles)

% Loads the previous frame to the currently displayed frame into the display
pathname=evalin('base','seqhandles.seqdir;');
filename=evalin('base','seqhandles.filename;');
image_no=get(handles.image_no,'string');
image_no=str2double(image_no);
if image_no < 2
    return
end
image_no=image_no-1;
set(handles.image_no,'String',image_no);
assignin('base','temp',image_no);
evalin('base','seqhandles.image_no=temp;');
clear('base','temp');

displayImage(pathname,filename,image_no)

