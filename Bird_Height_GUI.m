function varargout = Bird_Height_GUI(varargin)
% BIRD_HEIGHT_GUI M-file for Bird_Height_GUI.fig
%      BIRD_HEIGHT_GUI, by itself, creates a new BIRD_HEIGHT_GUI or raises the existing
%      singleton*.
%
%      H = BIRD_HEIGHT_GUI returns the handle to a new BIRD_HEIGHT_GUI or the handle to
%      the existing singleton*.
%
%      BIRD_HEIGHT_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BIRD_HEIGHT_GUI.M with the given input arguments.
%
%      BIRD_HEIGHT_GUI('Property','Value',...) creates a new BIRD_HEIGHT_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Bird_Height_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Bird_Height_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Bird_Height_GUI

% Last Modified by GUIDE v2.5 10-Mar-2017 09:51:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @Bird_Height_GUI_OpeningFcn, ...
    'gui_OutputFcn',  @Bird_Height_GUI_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

end

% % --- Executes on button press in togglebutton1.
% function togglebutton1_Callback(hObject, eventdata, handles)
% % hObject    handle to togglebutton1 (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    structure with handles and user data (see GUIDATA)
% 
% % Hint: get(hObject,'Value') returns toggle state of togglebutton1


% --- Executes on button press in ReflectionButton.
function ReflectionButton_Callback(hObject, eventdata, handles)
% hObject    handle to ReflectionButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

global birdMarked

% hObject    handle to ReflectionButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ReflectionButton

%gets bird and reflection coordinates
birdReflectionXY = ginput(2);

hold on;

scatter(birdReflectionXY(1,1),birdReflectionXY(1,2),'og');
scatter(birdReflectionXY(2,1),birdReflectionXY(2,2),'or');


 answer = questdlg('Confirm Bird and Reflection?','Confirm?','Accept','Cancel','Accept');
    
            
    if strcmp(answer,'Accept')
        assignin('base','Confirm_Boolean',1);
        birdMarked = true;
    else
        assignin('base','Confirm_Boolean',0);
        birdMarked = false;
    end
    % evalin is unnecessary now, delete in a future update
    
    % If cancel is pressed clear scatter points
    if ~evalin('base','Confirm_Boolean')
        %refresh_pic(handles);
        pathname = evalin('base','seqhandles.seqdir');
        filename = evalin('base','seqhandles.filename');
        Bird_SEQFrame = evalin('base','seqhandles.image_no');
        
        fnum = Bird_SEQFrame;
        displayImage(pathname,filename,fnum)
        
        
        % stop processing code
        return
    end
    
    % Load points into the workspaces
%     assignin('base','points', points);
    
    % Start_bird_frame and end_bird_frame are required for the translation
    % program. If this is the first head/tail input for this bird record the
    % start bird frame into the Birds Struct.
       

reflectionTranslation(birdReflectionXY, handles);
end
