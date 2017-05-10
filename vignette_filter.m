function img = vignette_filter(img)

img = img(:,21:end);

gau = exp(-(-45:45).^2/(2*15^2));
gau = gau/sum(gau);

if ~exist('vweights')
    
    persistent vweights;
    vweights = conv2(conv2(ones(size(img)),gau,'same'),gau','same');
end

img = img - conv2(conv2(img,gau,'same'),gau','same')./vweights;
var = conv2(conv2(img.^2,gau,'same'),gau','same')./vweights;
img = img./sqrt(var);
