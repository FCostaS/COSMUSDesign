function [data, info] = datagram
%Datagram gives an empty data for cosmus_messages/Datagram
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/Datagram';
[data.Ssid, info.Ssid] = ros.internal.ros.messages.ros.char('string',0);
[data.Data, info.Data] = ros.internal.ros.custommessages.cosmus_messages.vector3D;
info.Data.MLdataType = 'struct';
info.MessageType = 'cosmus_messages/Datagram';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,5);
info.MatPath{1} = 'ssid';
info.MatPath{2} = 'data';
info.MatPath{3} = 'data.x';
info.MatPath{4} = 'data.y';
info.MatPath{5} = 'data.z';
