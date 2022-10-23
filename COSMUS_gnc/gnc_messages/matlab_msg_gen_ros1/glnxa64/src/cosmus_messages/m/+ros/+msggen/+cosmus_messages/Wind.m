
classdef Wind < ros.Message
    %Wind MATLAB implementation of cosmus_messages/Wind
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'cosmus_messages/Wind' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '5c75feb886f80a82c19f1632ee37220a' % The MD5 Checksum of the message definition
        PropertyList = { 'Velocity' 'FrameId' 'TimeUsec' } % List of non-constant message properties
        ROSPropertyList = { 'velocity' 'frame_id' 'time_usec' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.cosmus_messages.Vector3D' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Velocity
        FrameId
        TimeUsec
    end
    methods
        function set.Velocity(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.cosmus_messages.Vector3D'};
            validateattributes(val, validClasses, validAttributes, 'Wind', 'Velocity')
            obj.Velocity = val;
        end
        function set.FrameId(obj, val)
            val = convertStringsToChars(val);
            validClasses = {'char', 'string'};
            validAttributes = {};
            validateattributes(val, validClasses, validAttributes, 'Wind', 'FrameId');
            obj.FrameId = char(val);
        end
        function set.TimeUsec(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Wind', 'TimeUsec');
            obj.TimeUsec = int64(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.cosmus_messages.Wind.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.cosmus_messages.Wind(strObj);
        end
    end
end
