function [data, info] = wind
%Wind gives an empty data for cosmus_messages/Wind
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/Wind';
[data.FrameId, info.FrameId] = ros.internal.ros.messages.ros.char('string',0);
[data.TimeUsec, info.TimeUsec] = ros.internal.ros.messages.ros.default_type('int64',1);
[data.Velocity, info.Velocity] = ros.internal.ros.custommessages.cosmus_messages.vector3D;
info.Velocity.MLdataType = 'struct';
info.MessageType = 'cosmus_messages/Wind';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'frame_id';
info.MatPath{2} = 'time_usec';
info.MatPath{3} = 'velocity';
info.MatPath{4} = 'velocity.x';
info.MatPath{5} = 'velocity.y';
info.MatPath{6} = 'velocity.z';
