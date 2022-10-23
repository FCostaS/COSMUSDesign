function [M] = ...
    plot_state(time_history, pos_history, ...
    vel_history, p_swarm, fontsize, ...
    lines_color, dirname)

% Plot state variables - This function allows to plot the state variables
% of the swarm (trajectories, distance, velocity, acceleration).
%
% Inputs:
%   time_history: series of time steps
%   pos_history: series of agents' positions
%   vel_history: series of agents' velocities
%   acc_history: series of agents' accelerations
%   p_swarm: swarm parameters
%   dirname:
%
% Outputs:
%   plots of the 
% 
% 

%% Parameters

nb_agents = p_swarm.nb_agents;


%% Plot state variables

% Trajectories

% Distance
[dist_handle, M] = plot_distance(pos_history, time_history, ...
                        p_swarm.r_coll, p_swarm.d_ref, p_swarm.r, p_swarm.max_neig, fontsize, ...
                        lines_color);
% Speed
subplot(2,1,2)
speed_handle = plot_speed(vel_history, time_history, p_swarm.v_ref, ...
                        p_swarm.max_v, fontsize, lines_color, dist_handle);
% Acceleration
%accel_handle = plot_acceleration_offline(accel_history, time_history, ...
%                        p_swarm.max_a, fontsize, lines_color);

                    
%% Save plots

if ~isempty(dirname)
    
    %dist_path = strcat(dirname, '-dist');
    %savefig(dist_handle, dist_path);
    %print(dist_handle, dist_path, '-dpng', '-r0');
    
    %speed_path = strcat(dirname, '-speed');
    %savefig(speed_handle, speed_path);
    %print(speed_handle, speed_path, '-dpng', '-r0');
    
    %accel_path = strcat(dirname, '/accel');
    %savefig(accel_handle, accel_path);
    %print(accel_handle, accel_path, '-dpng', '-r0');
    
end


end
