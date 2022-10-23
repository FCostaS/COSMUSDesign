function [data, info] = networkComm
%NetworkComm gives an empty data for cosmus_messages/NetworkComm
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/NetworkComm';
[data.Comms, info.Comms] = ros.internal.ros.custommessages.cosmus_messages.communication;
info.Comms.MLdataType = 'struct';
info.Comms.MaxLen = NaN;
info.Comms.MinLen = 0;
data.Comms = data.Comms([],1);
info.MessageType = 'cosmus_messages/NetworkComm';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,5);
info.MatPath{1} = 'comms';
info.MatPath{2} = 'comms.ssid';
info.MatPath{3} = 'comms.x';
info.MatPath{4} = 'comms.y';
info.MatPath{5} = 'comms.z';
