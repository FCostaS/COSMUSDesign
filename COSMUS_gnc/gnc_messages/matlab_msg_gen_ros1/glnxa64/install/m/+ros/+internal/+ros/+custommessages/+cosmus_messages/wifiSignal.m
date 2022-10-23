function [data, info] = wifiSignal
%WifiSignal gives an empty data for cosmus_messages/WifiSignal
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/WifiSignal';
[data.Ssid, info.Ssid] = ros.internal.ros.messages.ros.char('string',0);
[data.SignalDbm, info.SignalDbm] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Frequency, info.Frequency] = ros.internal.ros.messages.ros.default_type('single',1);
info.MessageType = 'cosmus_messages/WifiSignal';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,3);
info.MatPath{1} = 'ssid';
info.MatPath{2} = 'signal_dbm';
info.MatPath{3} = 'frequency';
