function confirm_size(handles)
% When the bird marking is confirmed the head/tail coordinates are read into
% the Birds struct.

global Birds bird_no

Bird_SEQFrame = evalin('base','seqhandles.image_no');

birdFrame = evalin('base','birdFrame')+1;
points = evalin('base','points');
pointXHead = points(1,1);
pointYHead = points(1,2);
pointXTail = points(2,1);
pointYTail = points(2,2);

%read into Birds; Bird, BirdFrame.
Birds{bird_no}.Frame{birdFrame}.Head.x=pointXHead;
Birds{bird_no}.Frame{birdFrame}.Head.y=pointYHead;
Birds{bird_no}.Frame{birdFrame}.Tail.x=pointXTail;
Birds{bird_no}.Frame{birdFrame}.Tail.y=pointYTail;
Birds{bird_no}.Frame{birdFrame}.HeadnTail=points;

Birds{bird_no}.Frame{birdFrame}.SEQFrame = Bird_SEQFrame;

% The bird frame number is increased and then the next head/tail coordinates
% Can be taken on the next frame.
set(handles.Bird_Frame_Number_Field,'String',birdFrame);

% Once updated it is read into the birds struct
assignin('base','birdFrame',birdFrame);

% Get timestamp from SEQ file
%timestampread([evalin('base','seqhandles.seqdir;') '\' evalin('base','seqhandles.filename;')],evalin('base','seqhandles.image_no;'), bird_no, birdFrame)

%refresh_pic(handles);
pathname = evalin('base','seqhandles.seqdir');
filename = evalin('base','seqhandles.filename');

fnum = Bird_SEQFrame;
displayImage(pathname,filename,fnum)

