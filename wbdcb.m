function wbdcb(src,callback,f1,birdFrame,handles,panning,autoFrames,hObject,eventdata)

global Birds fb_input_data bird_no points birdMarked firstBirdMarkedPlaced

ah = get(f1,'CurrentAxes');
birdMarked = false;

if firstBirdMarkedPlaced == 1 
   return
end

%    function wbdcb(src,callbackdata)
seltype = get(src,'SelectionType');
if strcmp(seltype,'normal')
    
    set(src,'Pointer','circle');
    cp = get(ah,'CurrentPoint');
    xinit = cp(1,1);
    yinit = cp(1,2);
    
    firstBirdMarkedPlaced = 1;
    
    hl = line('XData',xinit,'YData',yinit,...
        'Marker','p','color','b');
    
    points(1,1) = cp(1,1);
    points(1,2) = cp(1,2);
    
    set(src,'WindowButtonMotionFcn',@wbmcb);%creates line that follows cursor
    set(src,'WindowButtonUpFcn',@wbucb);
end

    function  wbmcb(src,callbackdata)%creates the line following the cursor
        
        cp = get(ah,'CurrentPoint');
        xdat = [xinit,cp(1,1)];
        ydat = [yinit,cp(1,2)];
         
        points(2,1) = cp(1,1);
        points(2,2) = cp(1,2);
        
        
        set(hl,'XData',xdat);
        set(hl,'YData',ydat);
        drawnow
    end

    function wbucb(src,callbackdata)%
        
        
        last_seltype = get(src,'SelectionType');
        if strcmp(last_seltype,'extend')
            
            set(src,'Pointer','arrow');
            set(src,'WindowButtonMotionFcn','');
            set(src,'WindowButtonUpFcn','');

            set(f1,'WindowButtonDownFcn','');
            
            
%               Calls confirm window and waits for the response
    answer = questdlg('Confirm Head and Tail?','Confirm?','Accept','Cancel','Accept');
    
            
    if strcmp(answer,'Accept')
        assignin('base','Confirm_Boolean',1);
        birdMarked = true;
    else
        assignin('base','Confirm_Boolean',0);
        birdMarked = false;
    end
    % evalin is unnecessary now, delete in a future update
    
    % If cancel is pressed clear scatter points
    if ~evalin('base','Confirm_Boolean')
        %refresh_pic(handles);
        pathname = evalin('base','seqhandles.seqdir');
        filename = evalin('base','seqhandles.filename');
        Bird_SEQFrame = evalin('base','seqhandles.image_no');
        
        fnum = Bird_SEQFrame;
        displayImage(pathname,filename,fnum)
        
        
        % stop processing code
        return
    end
    
    % Load points into the workspaces
    assignin('base','points', points);
    
    % Start_bird_frame and end_bird_frame are required for the translation
    % program. If this is the first head/tail input for this bird record the
    % start bird frame into the Birds Struct.
    
    if birdFrame==1
        
        image_no = evalin('base','seqhandles.image_no');
        
        % Put start_bird_frame into frame_range struct
        Birds{bird_no}.frame_range.start_bird_frame=image_no;
        %assignin('base','Birds',Birds);
        
        confirm_size(handles);
                
    else
        
        birdFrame=birdFrame-1;
        %BirdFrame
        
        Bird_SEQFrame = evalin('base','seqhandles.image_no');
        %Bird_SEQFrame
        
        preBird_SEQFrame = Birds{bird_no}.Frame{birdFrame}.SEQFrame;
        
        %preBird_SEQFrame
        
        % If confirmed runs the confirm_size function and records the points to
        % the bird struct.
        if preBird_SEQFrame+1==Bird_SEQFrame;
            confirm_size(handles);
        else
            
            if preBird_SEQFrame==Bird_SEQFrame;
                %refresh_pic(handles);
                msgbox('This Frame has already been marked. Go to next frame.','Already Marked','warn');
            end
            
            if preBird_SEQFrame<Bird_SEQFrame;
                %refresh_pic(handles);
                msgbox('You have skipped a frame. Go to previous frame.','Frame Skipped','warn');
            end
            
            if preBird_SEQFrame>Bird_SEQFrame;
                %refresh_pic(handles);
                msgbox('You are marking a frame previous to the one you have done. Go to next unmarked frame.','Wrong Order','warn');
            end
            
        end
    end
    
    if birdFrame+1 == 8 && evalin('base','Confirm_Boolean')==1
        %msgbox('This Bird has been marked 8 times.');
        translation(handles,Birds,fb_input_data, bird_no, current_row);
    end
        end
       
if birdMarked == true
        pan on
end

if birdMarked == true
    if strcmp(autoFrames,'on')
        next_frame_push_Callback(hObject,eventdata,handles);
    end
end
        
    end
end

