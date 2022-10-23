%% Swarm parameters and Simulation start
cd('/home/fabricio/catkin_ws/src/COSMUS_gnc');
addpath('swarm_algorithms');
addpath('Utils');

clc; clear all; close all;

Fixed_step = 0.01;
T = 500; % simulation time

%%% Waypoints parameters

%%% Swarm parameters
altitude_ref = 300;
Propeller_Ref = 0.64;
radius_waypoint = 200;
Waypoints = [1200 -1000;
             3000 -3000;
             -1000 1000;
             -2000 -1000];
N_Waypoints = size(Waypoints,1);
airspeed_ref = 42;
sim_rate = 0.01;

% variables to be set
p_swarm.is_active_migration = 1;
p_swarm.is_active_arena = 0;
p_swarm.is_active_spheres = 0;
p_swarm.is_active_cyl = 0;

% number of agents
p_swarm.nb_agents = 3;

% max number of neighbors - Topological distance
p_swarm.max_neig = 5;

% radius of collisions
p_swarm.r_coll = 10;

% Swarm parameters
% Reference values
p_swarm.d_ref = 80; % Inter-agent distance
p_swarm.r = 400; % max radius of influence - metric distance
p_swarm.r_agent = 20;
p_swarm.v_ref = airspeed_ref; % Speed
p_swarm.max_a = 48; % Velocity bounds for the agents
p_swarm.max_v = 42; % Acceleration bounds for the agents

% coefficients for velocity matching
p_swarm.c_vm = 3;
p_swarm.a = 1;
p_swarm.b = 5;
p_swarm.c = (p_swarm.b-p_swarm.a)/(2*sqrt(p_swarm.a*p_swarm.b));
p_swarm.delta = 0.2;
p_swarm.k = p_swarm.r/p_swarm.d_ref;

% obstacle parameters
p_swarm.r0 = 20;
p_swarm.lambda = 1; % (0,1]
p_swarm.c_pm_obs = 5;
p_swarm.c_vm_obs = 3;

% wall parameters
p_swarm.d_arena = 1.5000;
p_swarm.c_arena = 10;
p_swarm.n_spheres = 3;
p_swarm.n_cyl = 14;
p_swarm.spheres = [-70 70 0; 50 50 200; 5 5 5; 50 50 50];
p_swarm.x_arena = [-100   100; -100   100; -100   100];
p_swarm.cylinders = [];

disp('Load simulation parameters');

%% Load/Store
ID_Simulation = 74;
results_dirname = strcat(pwd, '\Algorithm_OlfatiSaber');
% save(strcat(results_dirname, '\swarm.mat'));

%% Plots
outUAV = {out.UAV1, out.UAV2, out.UAV3,out.UAV4, out.UAV5};
nb_agents = 5;
fontsize = 12;
lines_color = [];
time_hist = out.tout;

% trajectory with waypoints
Trajectory_plot(outUAV, radius_waypoint, Waypoints, nb_agents);

% low-level controllers analyse
Autopilot_plot(time_hist, outUAV, nb_agents);

%% Real-time analysis
ros_time = out.ROStime.Data(:);
d_time = [0; diff(ros_time)];
d_time = d_time(d_time ~= 0);
hist(1./(d_time))

%%
% Analyse swarm state variables
pos_hist = [];
for i=1:nb_agents
    X = outUAV{i}.Posicao.PositionX.Data;
    Y = outUAV{i}.Posicao.PositionY.Data;
    Z = outUAV{i}.Posicao.PositionZ.Data;
    pos_hist_i = [X Y Z];
    pos_hist = [pos_hist pos_hist_i];
end

vel_hist = [];
for i=1:nb_agents
    X = outUAV{i}.Velocity.Data(:,1);
    Y = outUAV{i}.Velocity.Data(:,2);
    Z = outUAV{i}.Velocity.Data(:,3);
    vel_hist_i = [X Y Z];
    vel_hist = [vel_hist vel_hist_i];
end

M = plot_state(time_hist, pos_hist, vel_hist, p_swarm, fontsize, lines_color, results_dirname);
%%
Fragmentation_subplot(M, pos_hist, time_hist, nb_agents, 100*[1 50 100 200 300 490]);

%% Fragmentation plot
close all;
Fragmentation_plot(M, pos_hist, time_hist, nb_agents);
Formation_plot(M, pos_hist, nb_agents, 2000);

%%
[safety, order, union, alg_conn, safety_obs, min_d_obs] = swarm_performance(pos_hist, vel_hist, p_swarm, results_dirname);

% Plot performance
[perf_handle] = plot_swarm_performance(time_hist, safety, order, ...
        union, alg_conn, safety_obs, 14, results_dirname);
    
%% Images Navigation
figure,
writerObj = VideoWriter(results_dirname + "_video.avi");
writerObj.FrameRate = 100;

% open the video writer
open(writerObj);
 
for t=1:100:size(time_hist,1)
    for i=1:nb_agents
        subplot(3,2,i);
        image = outUAV{i}.Image.Data(:,:, t);
        imshow( image );
        title("UAV " + int2str(i));
        writeVideo(writerObj, getframe(gcf));
        
    end
    sgtitle("t = " + time_hist(t) + " [s]");
    drawnow
end
close(writerObj);
 