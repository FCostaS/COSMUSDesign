function [data, info] = communication
%Communication gives an empty data for cosmus_communication/Communication
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_communication/Communication';
[data.Id, info.Id] = ros.internal.ros.messages.ros.default_type('uint8',1);
[data.X, info.X] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Y, info.Y] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Z, info.Z] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'cosmus_communication/Communication';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'id';
info.MatPath{2} = 'x';
info.MatPath{3} = 'y';
info.MatPath{4} = 'z';
