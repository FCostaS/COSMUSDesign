function slBusOut = NetworkComm(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    maxlength = length(slBusOut.Comms);
    recvdlength = length(msgIn.Comms);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Comms', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Comms_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Comms_SL_Info.CurrentLength = uint32(currentlength);
    for iter=1:currentlength
        slBusOut.Comms(iter) = bus_conv_fcns.ros.msgToBus.cosmus_messages.Communication(msgIn.Comms(iter),slBusOut(1).Comms(iter),varargin{:});
    end
end
