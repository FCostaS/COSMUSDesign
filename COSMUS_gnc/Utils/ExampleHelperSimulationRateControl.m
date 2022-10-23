classdef (StrictDefaults)ExampleHelperSimulationRateControl < matlab.System
    %EXAMPLEHELPERSIMULATIONRATECONTROL Regulates Simulink simulation update intervals according to wall-clock time
    %
    %   NOTE: This system object is included only for demonstration
    %   purposes. The name of this class and its functionality may change
    %   without notice in a future release, or the class itself may be
    %   removed   
    %
    %   This block regulates Simulink simulation updates to ensure the time
    %   interval between updates is close to the SampleTime property.
    %
    %   To use this block:
    %
    %   Ensure that the SampleTime property of this system object matches
    %   the Fixed-step size (fundamental sample time) of the model. You can
    %   get this value by: a) Opening the Solver pane of the Configuration
    %   Parameters dialog, and noting the value for Fixed-step size, or b)
    %   Executing get_param(gcs,'FixedStep')
    %
    %   Open 'simulation parameter configuration', in the 'Solver' tab,
    %   choose 'Fixed-step' for 'Solver options'->'Type'. Expand 'Additional
    %   options', make sure the SampleTime used in this block matches the
    %   'Fixed-step size (fundamental sample time)'.
    %
    %   Additional Considerations:
    %
    %   The rate control may not be effective if the simulation model is too
    %   complex to be handled at the desired rate. To check the rate control
    %   performance, consider output rateObj.LastPeriod. Ideally it should be
    %   close to SampleTime during most part of the simulation.
    %
    %   Since this helper is only designed for Simulink simulation. In its
    %   property, it should always be set to 'Interpreted execution'. 
    %
    %   In production code generation, this block will not perform any
    %   task, since Simulink generates code to enforce the update interval
    %   (fundamental sample time) in wall-clock time. 
    %   Check https://www.mathworks.com/help/rtw/ug/about-model-execution.html
    %   for details.
    
    %#codegen
    % Copyright 2015-2019 The MathWorks, Inc.
    
    properties(Nontunable)
        %SampleTime The desired update interval in wall time (seconds)
        SampleTime = 0.02
    end
    
    properties(Access = private)
        %RateObj Controls update interval in wall-clock time
        RateObj = []
    end
    
    methods (Access = protected)
        
        function stepImpl(obj)
            %stepImpl Regulates simulation update
            if coder.target('MATLAB')
                obj.RateObj.waitfor();
            end
        end
        
        function setupImpl(obj)
            %setupImpl Implement tasks that need to be performed only once,
            % such as pre-computed constants.
            if coder.target('MATLAB')
                obj.RateObj = rateControl(1/obj.SampleTime);
            end
        end
        
        function resetImpl(obj)
            %resetImpl Initialize discrete-state properties.
            if coder.target('MATLAB')
                obj.RateObj.reset();
            end
        end

        function icon = getIconImpl(~)
            %getIconImpl Define a string as the icon for the System block in Simulink.
            icon = 'Rate Control';
        end
        
    end
    
    methods
        function set.SampleTime(obj, sampleTime)
            %set.SampleTime setter for SampleTime
            validateattributes(sampleTime, {'numeric'}, {'scalar', 'positive'},'Simulation Rate Control');
            obj.SampleTime = sampleTime;
        end
    end

    methods(Access = protected, Static)
        function simMode = getSimulateUsingImpl
            %getSimulateUsingImpl Force interpreted execution during simulation.
            simMode = 'Interpreted execution';
        end
    end
    
end

