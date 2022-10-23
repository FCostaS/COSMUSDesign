classdef ExampleHelperROSTimer < handle
    %ExampleHelperROSTimer Encapsulates a periodic timer object for the ROS examples
    %   This class ensures that the timer is properly deleted when its
    %   object goes out-of-scope or is cleared from the workspace.
    %
    %   t = ExampleHelperROSTimer(PERIOD, TIMERFCN) creates a timer object
    %   and sets its execution rate to PERIOD (in seconds). TIMERFCN will
    %   be executed each PERIOD.
    
    % Copyright 2014-2015 The MathWorks, Inc.
    
    properties
        %Timer - The encapsulated timer object
        Timer
        
        %TimerListener - Listener for Timer's ExecuteFcn event
        TimerListener = [] 
        
        %TimerFcn - Handle to timer callback function
        TimerFcn = []    

    end
    
    methods
        function obj = ExampleHelperROSTimer(period, timerFcn)
            %ExampleHelperROSTimer Create and start a timer
            
            % Create and start timer
            % Using the IntervalTimer ensures that the circular reference
            % is resolved correctly.
            obj.Timer = internal.IntervalTimer( period );
            obj.TimerListener = event.listener( obj.Timer, 'Executing', ...
                @(~,~)(obj.executeTimerCallback));     
            
            if ~internal.Callback.validate(timerFcn)
                error('Timer callback function is not a valid callback');
            end

            obj.TimerFcn = timerFcn;
            obj.Timer.start;
        end
        
        function delete(obj)
            %delete Stop the timer and delete it
            %   This function will also be called if the object is cleared
            %   from the workspace.
            
            if ~isempty(obj.TimerListener)
                delete(obj.TimerListener);
            end
            obj.Timer.stop;
            obj.TimerFcn = [];
        end
    end    
    
    methods (Access = private)
        function executeTimerCallback(obj)
            %executeTimerCallback Executes the timer callback each time a
            %timer period elapses
            
            try
                internal.Callback.execute(obj.TimerFcn, obj);
            catch ex
                obj.Timer.stop;
                obj.TimerFcn = [];                
                rethrow(ex)
            end
            
        end
    end
end
