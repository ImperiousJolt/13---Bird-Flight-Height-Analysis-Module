function Bird_Height_GUI_OpeningFcn(hObject, eventdata, handles, varargin) %#ok<*DEFNU,*INUSL,*INUSD>
global version
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Bird_Height_GUI (see VARARGIN)

% Choose default command line output for Bird_Height_GUI

% Update handles structure
guidata(hObject, handles);

% Set the name, version number and date
moduleName = 'Bird Flight Height Analysis Module';
moduleVersion = '7.2';
versionDate = 'Sept 2017';

% Update window name, in-app name and copyright date
version = [moduleName ' v' moduleVersion];
set(hObject,'Name',version);
set(handles.text8,'String',version);
%set(handles.text5,'String',['© HiDef Aerial Surveying Ltd. ' versionDate]);

iconPath = 'HiDefIcon.jpg';
if exist(iconPath,'file')
    im = imread(iconPath);
    javaIm = im2java(im);
    warning('off','MATLAB:HandleGraphics:ObsoletedProperty:JavaFrame');
    jframe = get(handles.figure1,'javaframe');
    jlcon = javax.swing.ImageIcon(javaIm);
    jframe.setFigureIcon(jlcon);
    warning('on','MATLAB:HandleGraphics:ObsoletedProperty:JavaFrame');
end

% UIWAIT makes Bird_Height_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);
handles.output = hObject;
evalin('base','seqhandles.startflag=0;');
seqdefault(handles)
evalin('base','seqhandles.startflag=1;');

% Update handles structure
guidata(hObject, handles);
