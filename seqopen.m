function [Seqinfo,chk,fid,CImageInfo] = seqopen(filename)
%seqread reads the SEQ File and extracts the header and video information 
%Please refer also to WORD document on "Sequence files"

fid=fopen(filename,'r'); %'r+'
chk=0;
CImageInfo=[];
Seqinfo=[];
if fid==-1
    chk=1;
    disp('File directory does not exist');
    return
end

if checkfile(fid);
    chk=1;
    disp('File is unsuitable');
    return
end
CImageInfo=get_header_info(fid);
Seqinfo=get_video_info(fid);

function chk=checkfile(fid)
chk=0;

fseek(fid,0,'bof');
MagicNumber=65261; %Check: MagicNumber is always FEED (hexadecimal)
if ~(fread(fid,1,'uint32')==MagicNumber)
    chk=1;
end

fseek(fid,4,'bof');
expected_Name='Norpix seq'; %Check: Name is always "Norpix seq"
Name=char(fread(fid,12,'uint16'))';
if ~strcmp(Name(1:10),expected_Name)
    chk=1;
end

fseek(fid,576,'bof');
Origin=0; %Check: Origin has always an offset of 0
if ~(fread(fid,1,'uint32')==Origin)
    chk=1;
end

function CImageInfo=get_header_info(fid)
fseek(fid,548,'bof');
CImageData=fread(fid,6,'uint32');

CImageInfo.ImageWidth=CImageData(1);
CImageInfo.ImageHeight=CImageData(2);
CImageInfo.ImageBitDepth=CImageData(3);
CImageInfo.ImageBitDepthReal=CImageData(4);
CImageInfo.ImageSizeBytes=CImageData(5);
CImageInfo.ImageFormat=CImageData(6);

function Seqinfo=get_video_info(fid)
fseek(fid,32,'bof');
Seqinfo.HeaderSize=fread(fid,1,'uint32');

fseek(fid,572,'bof');
Seqinfo.AllocatedFrames=fread(fid,1,'uint32');

fseek(fid,580,'bof');
Seqinfo.TrueImageSize=fread(fid,1,'uint32');

fseek(fid,584,'bof');
Seqinfo.FrameRate=fread(fid,1,'uint64');

Seqinfo.BYTE_Description=get_user_description(fid);

function BYTE_Description=get_user_description(fid)
fseek(fid,36,'bof');
txt=fread(fid,512,'uint8');
t=find(txt);
txt=txt(t);

BYTE_Description=char(txt);