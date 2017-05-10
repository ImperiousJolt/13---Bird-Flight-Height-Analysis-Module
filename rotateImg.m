function img = rotateImg(img)
% This function rotates the image to appear the right way around

[~,~,channels] = size(img);
if channels == 1    %SEQReadB
   img = rot90(img);
   img = flipud(img);
   return
end

%can only rotate/flip 2D matrices, so the 3 channel img is split
for n=1:3           %SEQReadBGR via displayImage
   imgSplit{n} = img(:,:,n); %#ok<*AGROW>
   imgRot{n} = rot90(imgSplit{n});
   imgRot{n} = flipud(imgRot{n});   
end

%recombine 3 channels
img = cat(3,imgRot{1},imgRot{2},imgRot{3});