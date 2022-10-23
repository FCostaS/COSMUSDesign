function [data, info] = wifiSignals
%WifiSignals gives an empty data for cosmus_messages/WifiSignals
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'cosmus_messages/WifiSignals';
[data.Signals, info.Signals] = ros.internal.ros.custommessages.cosmus_messages.wifiSignal;
info.Signals.MLdataType = 'struct';
info.Signals.MaxLen = NaN;
info.Signals.MinLen = 0;
data.Signals = data.Signals([],1);
info.MessageType = 'cosmus_messages/WifiSignals';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'signals';
info.MatPath{2} = 'signals.ssid';
info.MatPath{3} = 'signals.signal_dbm';
info.MatPath{4} = 'signals.frequency';
