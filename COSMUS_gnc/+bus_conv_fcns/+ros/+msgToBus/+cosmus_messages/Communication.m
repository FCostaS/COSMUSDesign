function slBusOut = Communication(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    slBusOut.Ssid_SL_Info.ReceivedLength = uint32(strlength(msgIn.Ssid));
    currlen  = min(slBusOut.Ssid_SL_Info.ReceivedLength, length(slBusOut.Ssid));
    slBusOut.Ssid_SL_Info.CurrentLength = uint32(currlen);
    slBusOut.Ssid(1:currlen) = uint8(char(msgIn.Ssid(1:currlen))).';
    slBusOut.X = double(msgIn.X);
    slBusOut.Y = double(msgIn.Y);
    slBusOut.Z = double(msgIn.Z);
end
