function [im,time] = SEQReadBGR(reelname, frame)
%returns a colour image
%needs compiled mexfile HSEQRead2 and HermesAPI

[data,timest,timeMS] = HSEQRead2(reelname,frame);
%data = double(data);

imhei = size(data,2);%2050;
imwid = size(data,1);%2448;

bim = zeros(size(data,1)/2,size(data,2)/2);
gim = zeros(size(data,1)/2,size(data,2)/2);
rim = zeros(size(data,1)/2,size(data,2)/2);

bim = data((1:2:end)+0,(1:2:end)+0);
gim = data((1:2:end)+1,(1:2:end)+0);
rim = data((1:2:end)+1,(1:2:end)+1);

im = zeros(imwid/2,imhei/2,3);

im(:,:,1)=bim;
im(:,:,2)=gim;
im(:,:,3)=rim;

clear bim
clear gim
clear rim
clear data

%unix_epoch = datenum(1970,1,1,0,0,0);
%timestamp = timest./86400 + unix_epoch;

%datestr(timestamp)

time = [timest;timeMS];


