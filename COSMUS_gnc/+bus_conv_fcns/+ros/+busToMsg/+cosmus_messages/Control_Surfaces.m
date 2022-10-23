function rosmsgOut = Control_Surfaces(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Propeller = double(slBusIn.Propeller);
    rosmsgOut.RightAileron = double(slBusIn.RightAileron);
    rosmsgOut.RightFlap = double(slBusIn.RightFlap);
    rosmsgOut.Elevators = double(slBusIn.Elevators);
    rosmsgOut.Rudder = double(slBusIn.Rudder);
end
