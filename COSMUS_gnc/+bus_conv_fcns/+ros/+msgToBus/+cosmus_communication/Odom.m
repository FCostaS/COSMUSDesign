function slBusOut = Odom(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    slBusOut.Pitch = double(msgIn.Pitch);
    slBusOut.Roll = double(msgIn.Roll);
    slBusOut.Yaw = double(msgIn.Yaw);
    slBusOut.PositionX = double(msgIn.PositionX);
    slBusOut.PositionY = double(msgIn.PositionY);
    slBusOut.PositionZ = double(msgIn.PositionZ);
    slBusOut.Velocity = double(msgIn.Velocity);
end
