function getVb(bird_no)
%get Vb for bird height calculation h=H*Vg/Vb
%inputs are Birds structure and bird_no.
%this function is currently called from next_bird; TO BE REVISED.

%Get Bird Struct
global Birds;

%Vb is the shift in the bird
for n=2:length(Birds{bird_no}.Frame)

%h2-h1    
Hx = Birds{bird_no}.Frame{n}.Head.x - Birds{bird_no}.Frame{n-1}.Head.x;
Hy = Birds{bird_no}.Frame{n}.Head.y - Birds{bird_no}.Frame{n-1}.Head.y;

%t2-t1
Tx = Birds{bird_no}.Frame{n}.Tail.x - Birds{bird_no}.Frame{n-1}.Tail.x;
Ty = Birds{bird_no}.Frame{n}.Tail.y - Birds{bird_no}.Frame{n-1}.Tail.y;

%put the vectors into the Birds struct
Birds{bird_no}.Frame{n}.Hshift = [Hx,Hy];
Birds{bird_no}.Frame{n}.Tshift = [Tx,Ty];
%Birds{bird_no}.Frame{n}.HTshift_avg = mean([Hx,Hy],[Tx,Ty]);

end