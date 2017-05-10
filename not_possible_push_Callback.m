function not_possible_push_Callback(hObject, eventdata, handles)
global Birds fb_input_data bird_no current_row xlspathname xlsfilename

% Assigns error codes to reasons for bird not being marked
FrameQ2 = false; % Second question required?
FrameQ3 = false;
reason = questdlg('Please specify why it is not possible to mark this bird.'...
    ,'Reason Required','Too Few Frames','Other','Too Few Frames');
switch reason
    case 'Other'
        FrameQ3 = true;
    case 'Too Few Frames'
        FrameQ2 = true;
    otherwise
        disp('User cancelled marking bird as not possible');
        return;
end

if FrameQ2
    reasonFrames = questdlg(['Please estimate the reason for too few frames. Note: High flying'...
        ' birds will appear larger than usual.'],'Further Details','High flier','Other','Other');
    switch reasonFrames
        case 'High flier'
            Birds{bird_no}.er{3} = 13003;
            fb_input_data{current_row,5}='EC:13003';
        case 'Other'
            Birds{bird_no}.er{4} = 13004;
            fb_input_data{current_row,5}='EC:13004';
        otherwise
            disp('User cancelled marking bird as not possible');
            return;
    end
end

if FrameQ3
    reasonFrames = questdlg('Please specify why this bird is not being marked:','Further Details',...
        'Poor Visibility','Bird Is Sitting','Not For Bird Height','Poor Visibility');
    switch reasonFrames
        case 'Poor Visibility'
            Birds{bird_no}.er{1} = 13001;
            fb_input_data{current_row,5}='EC:13001';
        case 'Bird Is Sitting'
            Birds{bird_no}.er{2} = 13002;
            fb_input_data{current_row,5}='EC:13002';
        case 'Not For Bird Height'
            Birds{bird_no}.er{8} = 13008;
            fb_input_data{current_row,5}='EC:13008';
        otherwise
            disp('User cancelled marking bird as not possible');
            return;
    end
end

% Clear Bird
Fields = {'Frame'; 'frame_range'; 'Translation'};
Birds{bird_no} = rmfield(Birds{bird_no},Fields(isfield(Birds{bird_no},Fields)));
% Still having a translation error it seems
if isfield(Birds{bird_no},'Translation')
    Birds{bird_no} = rmfield(Birds{bird_no},'Translation');
end
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

