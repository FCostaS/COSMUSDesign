function slBusOut = Image(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    currentlength = length(slBusOut.Header);
    for iter=1:currentlength
        slBusOut.Header(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header(iter),slBusOut(1).Header(iter),varargin{:});
    end
    slBusOut.Header = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header,slBusOut(1).Header,varargin{:});
    slBusOut.Height = uint32(msgIn.Height);
    slBusOut.Width = uint32(msgIn.Width);
    slBusOut.Encoding_SL_Info.ReceivedLength = uint32(strlength(msgIn.Encoding));
    currlen  = min(slBusOut.Encoding_SL_Info.ReceivedLength, length(slBusOut.Encoding));
    slBusOut.Encoding_SL_Info.CurrentLength = uint32(currlen);
    slBusOut.Encoding(1:currlen) = uint8(char(msgIn.Encoding(1:currlen))).';
    slBusOut.IsBigendian = uint8(msgIn.IsBigendian);
    slBusOut.Step = uint32(msgIn.Step);
    maxlength = length(slBusOut.Data);
    recvdlength = length(msgIn.Data);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Data', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Data_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Data_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.Data = uint8(msgIn.Data(1:slBusOut.Data_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.Data(recvdlength+1:maxlength) = 0;
    end
end
