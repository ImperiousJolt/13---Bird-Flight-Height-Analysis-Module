function OpenSEQ_Push_Callback(hObject, eventdata, handles)
global breel_no test_dbase seqpathname

%open .seq file from file structure
[filename, pathname] = uigetfile({'*.seq','Sequence Files (*.seq)'}, 'Select the SEQ-file', seqpathname);

% if no file sequence is selected throw error
if filename == 0
    % create messagebox
    msgbox('No sequence selected.','No Sequence Selected','help')
    return
else
    seqpathname = pathname;
    
    % updates the textfields on the GUI
    
    for n=1:numel(test_dbase)
        if strcmp([test_dbase{n,1}.reel_info.reelname '.seq'],filename)
            breel_no=n;
        end
    end
    
    evalin('base','seqhandles.image_no=1;');
    assignin('base','temp',filename); evalin('base','seqhandles.filename=temp;');
    assignin('base','temp',pathname); evalin('base','seqhandles.seqdir=temp;');
    
    set(handles.image_no,'String',evalin('base','seqhandles.image_no;'));
    set(handles.seqdir,'String',filename);
    
    fnum = 1;
    firstOpen = true;
    displayImage(pathname,filename,fnum,firstOpen)
    
    
end

