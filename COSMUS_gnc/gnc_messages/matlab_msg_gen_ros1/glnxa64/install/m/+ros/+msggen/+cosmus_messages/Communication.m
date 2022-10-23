
classdef Communication < ros.Message
    %Communication MATLAB implementation of cosmus_messages/Communication
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'cosmus_messages/Communication' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '4137400237206eebae12864daad803a2' % The MD5 Checksum of the message definition
        PropertyList = { 'Ssid' 'X' 'Y' 'Z' } % List of non-constant message properties
        ROSPropertyList = { 'ssid' 'x' 'y' 'z' } % List of non-constant ROS message properties
        PropertyMessageTypes = { '' ...
            '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Ssid
        X
        Y
        Z
    end
    methods
        function set.Ssid(obj, val)
            val = convertStringsToChars(val);
            validClasses = {'char', 'string'};
            validAttributes = {};
            validateattributes(val, validClasses, validAttributes, 'Communication', 'Ssid');
            obj.Ssid = char(val);
        end
        function set.X(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Communication', 'X');
            obj.X = double(val);
        end
        function set.Y(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Communication', 'Y');
            obj.Y = double(val);
        end
        function set.Z(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Communication', 'Z');
            obj.Z = double(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.cosmus_messages.Communication.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.cosmus_messages.Communication(strObj);
        end
    end
end
