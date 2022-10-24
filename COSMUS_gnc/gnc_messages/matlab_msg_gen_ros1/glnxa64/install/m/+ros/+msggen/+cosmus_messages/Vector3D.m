
classdef Vector3D < ros.Message
    %Vector3D MATLAB implementation of cosmus_messages/Vector3D
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'cosmus_messages/Vector3D' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = 'cc153912f1453b708d221682bc23d9ac' % The MD5 Checksum of the message definition
        PropertyList = { 'X' 'Y' 'Z' } % List of non-constant message properties
        ROSPropertyList = { 'x' 'y' 'z' } % List of non-constant ROS message properties
        PropertyMessageTypes = { '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        X
        Y
        Z
    end
    methods
        function set.X(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Vector3D', 'X');
            obj.X = single(val);
        end
        function set.Y(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Vector3D', 'Y');
            obj.Y = single(val);
        end
        function set.Z(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Vector3D', 'Z');
            obj.Z = single(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.cosmus_messages.Vector3D.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.cosmus_messages.Vector3D(strObj);
        end
    end
end