function next_frame_push_Callback(hObject, eventdata, handles)

% Loads the next frame to the currently displayed frame into the display
pathname=evalin('base','seqhandles.seqdir;');
filename=evalin('base','seqhandles.filename;');
%image_no=evalin('base','seqhandles.image_no;');
image_no=get(handles.image_no,'string');
image_no=str2double(image_no);
image_no=image_no+1;
set(handles.image_no,'String',image_no);

assignin('base','temp',image_no);
evalin('base','seqhandles.image_no=temp;');
clear('base','temp');

displayImage(pathname,filename,image_no)

