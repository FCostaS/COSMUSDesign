%% Swarm parameters and Simulation start
cd('/home/fabricio/catkin_ws/src/COSMUS_gnc');
addpath('Utils');
addpath('Cessna C172');
clc; clear all; close all;

T = 750; % simulation time
%%% Waypoints parameters

%%% Swarm parameters
altitude_ref = 300;
Propeller_Ref = 0.70;
radius_waypoint = 200;
Waypoints = [1000 -1000;
             -1000 1000;
             1000 1000;
             -1000 -1000];
N_Waypoints = size(Waypoints,1);
airspeed_ref = 42;
sim_rate = 0.01;

disp('Load simulation parameters');
%% Load/Store
ID_Simulation = 74;
results_dirname = strcat(pwd, '\Cessna C172');
if( exist(results_dirname,'dir') == 0 )
    mkdir(results_dirname);
    save(strcat(results_dirname, '\low_level_test.mat'));
    disp('Save simulation');
else
    load(strcat(results_dirname, '\sim_outs.mat'));
    disp('Load simulation');
end

%% Plots
outUAV = {out.UAV1, out.UAV1, out.UAV1,out.UAV1, out.UAV1};
nb_agents = 5;
fontsize = 12;
time_hist = out.tout;

% trajectory with waypoints
Trajectory_plot(outUAV, radius_waypoint, Waypoints, 1);

% low-level controllers analyse
Autopilot_plot(time_hist, outUAV, 1);

%% Real-time analysis
ros_time = out.ROStime.Data(:);
d_time = [0; diff(ros_time)];
plot(time_hist, d_time);