function image_no_Callback(hObject, eventdata, handles)

%from this text input you can go to any frame on the sequence file.
pathname=evalin('base','seqhandles.seqdir;');
filename=evalin('base','seqhandles.filename;');
image_no=get(handles.image_no,'string');
image_no=str2double(image_no);
assignin('base','temp',image_no);
evalin('base','seqhandles.image_no=temp;');
clear('base','temp');

fnum = image_no;
displayImage(pathname,filename,fnum)

