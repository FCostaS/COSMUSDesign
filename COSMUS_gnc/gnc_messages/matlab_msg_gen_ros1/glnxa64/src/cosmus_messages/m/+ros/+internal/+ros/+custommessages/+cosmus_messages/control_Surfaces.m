function [data, info] = control_Surfaces
%Control_Surfaces gives an empty data for cosmus_messages/Control_Surfaces
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/Control_Surfaces';
[data.Propeller, info.Propeller] = ros.internal.ros.messages.ros.default_type('double',1);
[data.RightAileron, info.RightAileron] = ros.internal.ros.messages.ros.default_type('double',1);
[data.RightFlap, info.RightFlap] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Elevators, info.Elevators] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Rudder, info.Rudder] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'cosmus_messages/Control_Surfaces';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,5);
info.MatPath{1} = 'propeller';
info.MatPath{2} = 'right_aileron';
info.MatPath{3} = 'right_flap';
info.MatPath{4} = 'elevators';
info.MatPath{5} = 'rudder';
