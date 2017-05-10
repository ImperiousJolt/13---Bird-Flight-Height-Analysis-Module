function varargout = SetBands(varargin)
% SETBANDS MATLAB code for SetBands.fig
%      SETBANDS, by itself, creates a new SETBANDS or raises the existing
%      singleton*.
%
%      H = SETBANDS returns the handle to a new SETBANDS or the handle to
%      the existing singleton*.
%
%      SETBANDS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SETBANDS.M with the given input arguments.
%
%      SETBANDS('Property','Value',...) creates a new SETBANDS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before SetBands_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to SetBands_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help SetBands

% Last Modified by GUIDE v2.5 28-Nov-2012 09:53:15

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @SetBands_OpeningFcn, ...
                   'gui_OutputFcn',  @SetBands_OutputFcn, ...
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
% End initialization code - DO NOT EDIT


% --- Executes just before SetBands is made visible.
function SetBands_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to SetBands (see VARARGIN)

% Choose default command line output for SetBands
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes SetBands wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = SetBands_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function firstBandEdit_Callback(hObject, eventdata, handles)
% hObject    handle to firstBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of firstBandEdit as text
%        str2double(get(hObject,'String')) returns contents of firstBandEdit as a double


% --- Executes during object creation, after setting all properties.
function firstBandEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to firstBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function secondBandEdit_Callback(hObject, eventdata, handles)
% hObject    handle to secondBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of secondBandEdit as text
%        str2double(get(hObject,'String')) returns contents of secondBandEdit as a double


% --- Executes during object creation, after setting all properties.
function secondBandEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to secondBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function thirdBandEdit_Callback(hObject, eventdata, handles)
% hObject    handle to thirdBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of thirdBandEdit as text
%        str2double(get(hObject,'String')) returns contents of thirdBandEdit as a double


% --- Executes during object creation, after setting all properties.
function thirdBandEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to thirdBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function forthBandEdit_Callback(hObject, eventdata, handles)
% hObject    handle to forthBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of forthBandEdit as text
%        str2double(get(hObject,'String')) returns contents of forthBandEdit as a double


% --- Executes during object creation, after setting all properties.
function forthBandEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to forthBandEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in submit_newBands.
function submit_newBands_Callback(hObject, eventdata, handles)
% hObject    handle to submit_newBands (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

global Bands;

firstBand = get(handles.firstBandEdit,'string');
secondBand = get(handles.secondBandEdit,'string');
thirdBand = get(handles.thirdBandEdit,'string');
forthBand = get(handles.forthBandEdit,'string');

Bands = [str2num(firstBand),str2num(secondBand),str2num(thirdBand),str2num(forthBand)];

disp(Bands);

close(handles.figure1);
