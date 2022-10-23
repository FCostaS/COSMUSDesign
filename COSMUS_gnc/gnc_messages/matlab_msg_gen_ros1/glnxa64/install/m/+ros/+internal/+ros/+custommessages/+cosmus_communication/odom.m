function [data, info] = odom
%Odom gives an empty data for cosmus_communication/Odom
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_communication/Odom';
[data.Pitch, info.Pitch] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Roll, info.Roll] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Yaw, info.Yaw] = ros.internal.ros.messages.ros.default_type('double',1);
[data.PositionX, info.PositionX] = ros.internal.ros.messages.ros.default_type('double',1);
[data.PositionY, info.PositionY] = ros.internal.ros.messages.ros.default_type('double',1);
[data.PositionZ, info.PositionZ] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Velocity, info.Velocity] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'cosmus_communication/Odom';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,7);
info.MatPath{1} = 'pitch';
info.MatPath{2} = 'roll';
info.MatPath{3} = 'yaw';
info.MatPath{4} = 'position_x';
info.MatPath{5} = 'position_y';
info.MatPath{6} = 'position_z';
info.MatPath{7} = 'velocity';
