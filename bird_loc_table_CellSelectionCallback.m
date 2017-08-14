function bird_loc_table_CellSelectionCallback(hObject, eventdata, handles)
global Birds fb_input_data bird_no num_birds current_row

filename = evalin('base','seqhandles.filename');

if ~isempty(eventdata.Indices)
    if isempty(filename)
        
        msgbox('Error: Please select a SEQ file','Error','error')
        
    else
        if eventdata.Indices(2)==1||eventdata.Indices(2)==2||eventdata.Indices(2)==3||eventdata.Indices(2)==5
            
            % Do nothing if frame isn't selected
            
        else
            
            current_row = eventdata.Indices(1);
            
            current_reel = fb_input_data{current_row,2};
            assignin('base','current_reel',current_reel);
            
            
            if fb_input_data{current_row,8} == 0,
                num_birds = num_birds + 1;
                bird_no = num_birds;
                fb_input_data{current_row,8} = bird_no;
            else
                bird_no = fb_input_data{current_row,8};
            end
            
            
            set(handles.Bird_Number_Field,'String',num2str(current_row));
            
            Birds{bird_no}.Frame_Number = fb_input_data{current_row,4};
            Birds{bird_no}.Marker_Number = fb_input_data{current_row,2};
            Birds{bird_no}.Reel_Number = fb_input_data{current_row,3};
            
            image_no = fb_input_data{eventdata.Indices(1),eventdata.Indices(2)};
            
            % From this text input you can go to any frame on the sequence file.
            pathname = evalin('base','seqhandles.seqdir;');
            filename = evalin('base','seqhandles.filename;');
            assignin('base','temp',image_no);
            evalin('base','seqhandles.image_no=temp;');
            clear('base','temp');
            
            set(handles.image_no,'String',image_no);
            
            fnum = image_no;
            hold on;
            displayImage(pathname,filename,fnum)
            
            %(fb_input_data{eventdata.Indices(1),6}/2)+15,
            %(fb_input_data{eventdata.Indices(1),7}/2)+15,
            
            text((fb_input_data{current_row,6}/2)+15,(fb_input_data{current_row,7}/2)+15,...
                num2str(fb_input_data{current_row,2}),'Color', 'white');
            
            hold off;
            %scatter(fb_input_data{eventdata.Indices(1),6},fb_input_data{eventdata.Indices(1),7},'10','O');
            
            %axis image;
            axis off;
            
        end
    end
end

