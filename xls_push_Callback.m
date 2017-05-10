function xls_push_Callback(hObject, eventdata, handles)
xlsstr = get(handles.xlsdir,'String');

if isempty(xlsstr)
    bird_loc_input(handles)
else
    cont = questdlg('Are you sure you want to load a new spreadsheet?', 'Load a new spreadsheet?', 'Yes');
    switch cont,
        case 'Yes',
            bird_loc_input(handles)
    end % switch
end

