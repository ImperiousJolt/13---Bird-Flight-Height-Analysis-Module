function run_trans_Callback(hObject, eventdata, handles)
% Calls confirm window and waits for the response
answer =    questdlg('Confirm run translation?','Confirm?','Confirm',...
    'Cancel','Confirm');
if strcmp(answer,'Confirm')
    assignin('base','Confirm_Boolean',1);
else
    assignin('base','Confirm_Boolean',0);
end
%uiwait(ConfirmNextBird);

if evalin('base','Confirm_Boolean')==1
    
    translation(handles);
    
end

