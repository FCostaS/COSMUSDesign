addpath('Utils');
T = out.ReferenciasUAV3.Time;

% Plot Waypoints with Trajectory
X = out.ReferenciasUAV3.Data(:,2);
Y = out.ReferenciasUAV3.Data(:,4);

WaypointsX = out.ReferenciasUAV3.Data(:,1); 
WaypointsY = out.Refere
nciasUAV3.Data(:,3);

R = 100;

hold on
    plot(X,Y,"-k");
    plot(WaypointsX,WaypointsY,".r");
    circle(WaypointsX, WaypointsY, R, 'y.');
    circle(WaypointsX, WaypointsY, R+30, 'g.');
    circle(WaypointsX, WaypointsY, R+50, 'r.');
    xlabel("X (m)");
    ylabel("Y (m)");
hold off