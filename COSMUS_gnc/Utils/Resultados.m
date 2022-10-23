addpath('Utils');
T = out.Posicao.Y.Time;

% Plot Waypoints with Trajectory
Y = out.Posicao.Y.Data;
X = out.Posicao.X.Data;

WaypointsX = out.Referencias.Data(:,1); 
WaypointsY = out.Referencias.Data(:,3);

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

%% Plot Waypoints with Refs
subplot(1,2,1);
    hold on
    plot(T, X,"-b");
    plot(T, WaypointsX, "--r");
    xlabel("tempo (s)");
    ylabel("X (m)");
    title('(a)')
    legend('eixo X','Referência');
    hold off
    
subplot(1,2,2);
    hold on
    plot(T, Y,"-b");
    plot(T, WaypointsY, "--r");
    xlabel("tempo (s)");
    ylabel("Y (m)");
    title('(b)')
    legend('eixo Y ','Referência');
    hold off

%% Altitude

out = outUAV{1}
Altitude = out.Posicao.Altitude.Data;
Ref = 300 + zeros(1, length(T));

subplot(1,2,1)
hold on
    plot(T, Altitude,"-b");
    plot(T, Ref, "--r");
    xlabel("tempo (s)");
    ylabel("Z (m)");
    legend('Altitude','Referência');
hold off

subplot(1,2,2)
hold on
    plot(T, Altitude,"-b");
    plot(T, Ref, "--r");
    xlabel("tempo (s)");
    ylabel("Z (m)");
    legend('Altitude','Referência');
hold off

%% Velocidade
Vel = out.Velocidade.Data;
Ref = 40 + zeros(1, length(T));
subplot(1,2,1)
hold on
    plot(T, Vel,"-b");
    plot(T, Ref, "--r");
    xlabel("tempo (s)");
    ylabel("Velocidade (m/s)");
    legend('Velocidade','Referência');
hold off

subplot(1,2,2)
hold on
    plot(T, Vel,"-b");
    plot(T, Ref, "--r");
    xlabel("tempo (s)");
    ylabel("Velocidade (m/s)");
    legend('Velocidade','Referência');
hold off



%% Poses 
Roll = out.Pose.Roll.Data;
Pitch = out.Pose.Pitch.Data;
Yaw = out.Pose.Yaw.Data;

RefRoll =  out.PoseRefs.Roll_Ref.Data;
RefPitch = out.PoseRefs.Pitch_Ref.Data;

subplot(2,2,1);
hold on
    plot(T, Roll,"-b");
    plot(T, RefRoll, "--r");
    xlabel("tempo (s)");
    ylabel("Roll (rad)");
    legend('\phi','Referência');
    title('(a)')
hold off

subplot(2,2,2);
hold on
    plot(T, -Pitch,"-b");
    plot(T, RefPitch, "--r");
    xlabel("tempo (s)");
    ylabel("Pitch (rad)");
    legend('\theta','Referência');
    title('(b)')
hold off

subplot(2,2,[3,4]);
hold on
    plot(T, Yaw,"-b");
    xlabel("tempo (s)");
    ylabel("Yaw (rad)");
    legend('\psi','Referência');
    title('(c)')
hold off
