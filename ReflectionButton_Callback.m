% --- Executes on button press in ReflectionButton.
function ReflectionButton_Callback(eventdata, hObject)
% hObject    handle to ReflectionButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


global xlspathname xlsfilename bird_no

birdsWithReflection = [];

% hObject    handle to ReflectionButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ReflectionButton

%gets bird and reflection coordinates
birdsWithReflection{bird_no}.birdXY = ginput(1);
birdsWithReflection{bird_no}.reflectionXY = ginput(1);
birdsWithReflection{bird_no}.camera_number = '';


%Save has a mat file.
save([xlspathname xlsfilename(1:end-5) '.mat'], 'birdsWithReflection');
