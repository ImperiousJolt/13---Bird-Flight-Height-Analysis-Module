function displayImage(pathname,filename,frame,firstOpen) %#ok<INUSD>
global brightness

try
    if ~exist('firstOpen','var')
        L = get(gca,{'xlim','ylim'});
        if frame < 1
            return
        end
    end
    
    [img] = SEQReadBGR([pathname,filename], frame);
    img = rotateImg(img);
    cla;
    
    %adjust brightness
    img = img .* brightness;
    
    img = min(img,255);
    image(img/255);
    
    %set aspect ratio
    [hei, wid, ~] = size(img);
    pbaspect([wid, hei, 1])
    
    if ~exist('firstOpen','var')
        set(gca,{'xlim','ylim'},L)
    end
    
    axis off;
catch %#ok<CTCH>
end