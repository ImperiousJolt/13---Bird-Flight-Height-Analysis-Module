function display_markers_push_Callback(hObject, eventdata, handles)
global Birds

current_frame = get(handles.image_no,'String');
current_reel = get(handles.seqdir,'String');

for b = 1:length(Birds)
    try
        if strfind(current_reel,Birds{b}.Reel_Number);
            for n = 1:length(Birds{b}.Frame)
                if Birds{b}.Frame{n}.SEQFrame == str2double(current_frame)
                    % Plot markers
                    hold on;
                    scatter(Birds{b}.Frame{n}.Head.x,Birds{b}.Frame{n}.Head.y,'og');
                    scatter(Birds{b}.Frame{n}.Tail.x,Birds{b}.Frame{n}.Tail.y,'or');
                else
                    % no nothing
                end
            end
        end
    catch %#ok<*CTCH>
        disp('Bird not completed yet.');
    end
    
end

