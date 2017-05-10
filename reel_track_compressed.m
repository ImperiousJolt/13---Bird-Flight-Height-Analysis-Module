function [ trans ] = reel_track_compressed( reelname,frames )


%SeqInfo = GetSeqInfo(reelname);
%if nargin==1,
%    frames = [1,SeqInfo.AllocatedFrames];
%end;

%if frames(2)>SeqInfo.AllocatedFrames
%    frames(2)=SeqInfo.AllocatedFrames;
%end;

%im1 = seqimagereadgrey(reelname,1);

nframes = frames(2)-frames(1);

H = waitbar(0,'Tracking reel motion');

im1 = SEQReadB(reelname, frames(1));

%imagesc(im1);pause;

im1 = vignette_filter(im1);
[dimx,dimy] = size(im1);

trans = zeros(nframes,2);

for n=frames(1)+1:frames(2),

    waitbar((n-frames(1))/nframes,H);
    
    im2 = SEQReadB(reelname, n);
    
    %imagesc(im2);
    
    im2 = vignette_filter(im2);
    
    acorr = real(ifft2(fft2(im1).*fft2(rot90(im2,2))));

    [v,shiftx] = max(acorr);
    [~,shifty] = max(v);

    shiftx = shiftx(shifty);
    if shiftx>dimx/2,
        shiftx=shiftx-dimx;
    end;
    if shifty>dimy/2,
        shifty=shifty-dimy;
    end;

    trans(n-frames(1),:) = -[shiftx,shifty];
    im1=im2;
end
close(H);

