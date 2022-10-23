function [data, info] = odom
%Odom gives an empty data for cosmus_messages/Odom
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/Odom';
[data.Pitch, info.Pitch] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Roll, info.Roll] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Yaw, info.Yaw] = ros.internal.ros.messages.ros.default_type('double',1);
[data.AccelX, info.AccelX] = ros.internal.ros.messages.ros.default_type('double',1);
[data.AccelY, info.AccelY] = ros.internal.ros.messages.ros.default_type('double',1);
[data.AccelZ, info.AccelZ] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'cosmus_messages/Odom';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'pitch';
info.MatPath{2} = 'roll';
info.MatPath{3} = 'yaw';
info.MatPath{4} = 'accel_x';
info.MatPath{5} = 'accel_y';
info.MatPath{6} = 'accel_z';
