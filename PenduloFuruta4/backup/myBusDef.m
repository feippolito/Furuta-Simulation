function myBusDef() 
% MYBUSDEF initializes a set of bus objects in the MATLAB base workspace 

% Bus object: BO 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'signal1';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'signal2';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

BO = Simulink.Bus;
BO.HeaderFile = '';
BO.Description = '';
BO.DataScope = 'Auto';
BO.Alignment = -1;
BO.Elements = elems;
clear elems;
assignin('base','BO', BO);

