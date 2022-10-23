function [data, info] = airspeed
%Airspeed gives an empty data for cosmus_messages/Airspeed
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/Airspeed';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.DifferentialPressure, info.DifferentialPressure] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Intensity, info.Intensity] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Velocity, info.Velocity] = ros.internal.ros.custommessages.cosmus_messages.vector3D;
info.Velocity.MLdataType = 'struct';
info.MessageType = 'cosmus_messages/Airspeed';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,12);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'differential_pressure';
info.MatPath{8} = 'intensity';
info.MatPath{9} = 'velocity';
info.MatPath{10} = 'velocity.x';
info.MatPath{11} = 'velocity.y';
info.MatPath{12} = 'velocity.z';
