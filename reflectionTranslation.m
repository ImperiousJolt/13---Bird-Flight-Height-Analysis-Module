function reflectionTranslation(birdReflectionXY, handles)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
global Birds xlsfilename xlspathname bird_no

%get camera number for height by reflection calculation.
survey_name_split = textscan(xlsfilename, '%s',5,'Delimiter','_');

cam_no = textscan(survey_name_split{1,1}{5,1}, 'C%d');

% Record version bird was marked with
Birds{bird_no}.Version = version;
Birds{bird_no}.cam_no = cam_no;

Birds{bird_no}.points(1,1) = birdReflectionXY(1,1);
Birds{bird_no}.points(1,2) = birdReflectionXY(1,2);

Birds{bird_no}.points(2,1) = birdReflectionXY(2,1);
Birds{bird_no}.points(2,2) = birdReflectionXY(2,2);

Birds{bird_no}.possible = 1;
Birds{bird_no}.markedByReflection = true;

% Create mat file after each bird is completed.
save([xlspathname xlsfilename(1:end-5) '.mat'],'Birds');

  bird_loc_input_auto_refresh(handles);

end

