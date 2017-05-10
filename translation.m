function translation(handles)
global Tlist Birds fb_input_data xlsfilename xlspathname bird_no current_row version List

% If confirmed runs the confirm_size function and records the points to the bird struct.
birdFrame = evalin('base','birdFrame');

if birdFrame<=2
    % Create error messagebox
    msgbox('To calculate the Bird Height, data is needed from more frames.','Error','error')
    return
else
    
    % Put end_bird_frame into frame_range struct
    image_no = evalin('base','seqhandles.image_no');
    %Birds = evalin('base','Birds');
    
    Birds{bird_no}.frame_range.end_bird_frame=image_no;
    
    frame_range = [Birds{bird_no}.frame_range.start_bird_frame, Birds{bird_no}.frame_range.end_bird_frame];
    
    % NEW
    Tlist = reel_track_compressed([evalin('base','seqhandles.seqdir') '/' evalin('base','seqhandles.filename')],frame_range);
    
    % Tlist is returned from frame_translations and read into the Birds struct
    for n=1:size(Tlist,1)
        Birds{bird_no}.Translation{n}.x=Tlist(n,1);
        Birds{bird_no}.Translation{n}.y=Tlist(n,2);
        Vgl=Vg_length(Birds{bird_no}.Translation{n}.x,Birds{bird_no}.Translation{n}.y);
        Birds{bird_no}.Translation{n}.Vgl=Vgl;
    end
    
    % Bird has all the required data to perform a height calculation.
    Birds{bird_no}.possible = 1;
    
    % Check if any of the translations are (0,0) if any are, 'possible' is back to 0!
    for n=1:size(Birds{bird_no}.Translation{n},1)
        if(Birds{bird_no}.Translation{n}.x == 0 && Birds{bird_no}.Translation{n}.y == 0)
            Birds{bird_no}.possible = 0;
            Birds{bird_no}.er{5} = 13005;
        end
    end
    
    % getVb create the Hshift and Tshift variables
    getVb(bird_no);
    
    % Reset frame number
    birdFrame = 0;
    assignin('base','birdFrame',birdFrame);
    
    % Update fb_input_data
    fb_input_data{current_row,5}='Yes';
    
    %need to remove the measured birds here now and also after not done
    %etc, to auto refresh.
    
    
    % Set UI
    set(handles.Bird_Frame_Number_Field,'String',0);
    set(handles.bird_loc_table,'data',fb_input_data);
    
end

% Record version bird was marked with
Birds{bird_no}.Version = version;
Birds{bird_no}.markedByReflection = false;

% Create mat file after each bird is completed.
save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');

bird_loc_input_auto_refresh(handles);

