function seqdefault(handles)
evalin('base','seqhandles.playflag=0;');
evalin('base','seqhandles.recordflag=0;');
evalin('base','seqhandles.playflag=0;');
evalin('base','seqhandles.disp_coordflag=0;');
%evalin('base','seqhandles.rec_playbackflag=0;')
%evalin('base','seqhandles.recfile_no=0;')
%evalin('base','seqhandles.save_name=[];');
evalin('base','seqhandles.frm_rate=1;');
%evalin('base','seqhandles.rec_rate=50;');
%evalin('base','seqhandles.rec_filename=[];');
%evalin('base','seqhandles.pixel_lost=0;');

evalin('base','seqhandles.colour.red=0;');
evalin('base','seqhandles.colour.green=0;');
evalin('base','seqhandles.colour.blue=0;');
evalin('base','seqhandles.contrast=0;');
evalin('base','seqhandles.confactor=1;');
evalin('base','seqhandles.brightness=0;');
evalin('base','seqhandles.colour.rval=1;');
evalin('base','seqhandles.colour.gval=1;');
evalin('base','seqhandles.colour.bval=1;');
evalin('base','seqhandles.conval=1;');
evalin('base','seqhandles.brival=1;');

if evalin('base','seqhandles.startflag;');
evalin('base','seqhandles.image_no;');
set(handles.image_no,'String',evalin('base','seqhandles.image_no;'));
else
    evalin('base','seqhandles.seqcreateflag=0;');
    evalin('base','seqhandles.seqdir=[];');
    evalin('base','seqhandles.filename=[];');
    evalin('base','seqhandles.pixel_n=0;');
end

%set(handles.frm_rate,'String',evalin('base','seqhandles.frm_rate;'));
%set(handles.rec_rate,'String',evalin('base','seqhandles.rec_rate;'));
%set(handles.editc,'String',evalin('base','seqhandles.contrast;'));
%set(handles.editcf,'String',evalin('base','seqhandles.confactor;'));
%set(handles.editb,'String',evalin('base','seqhandles.brightness;'));
%set(handles.rec_minus,'Visible','off');
%set(handles.rec_plus,'Visible','off');
%set(handles.create_SEQ,'Visible','off');