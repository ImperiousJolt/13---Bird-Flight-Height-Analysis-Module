function [im,time] = SEQReadB(reelname, frame)
%returns a black and white image (the blue channel)
%needs compiled mexfile HSEQRead2 and HermesAPI

[data,timest,timestampMS] = HSEQRead2(reelname,frame);

data = double(data);

imhei = size(data,2);%2050;
imwid = size(data,1);%2448;

im = zeros(imwid/2,imhei/2);
for j=0:1,
    for k=0:1,
        %size(data((1:2:end)+j,(1:2:end)+k)),
        im = im+data((1:2:end)+j,(1:2:end)+k);
    end; 
end;

%unix_epoch = datenum(1970,1,1,0,0,0);
%timestamp = timest./86400 + unix_epoch;

time = [timest;timestampMS]; 



