function Autopilot_plot(times, outUAV, N)

colors = ["-r" "-b" "-c" "-y" "-k" "-w"];
legends = cell(1, N);

%% Altitude plot
f = figure;
hold on
for t=1:N
    plot(times, outUAV{t}.error_altitude.Data, colors(t));
    legends{t} = "UAV " + int2str(t);
end
title('Altitude Error');
ylabel('Altitude (m)');
xlabel('Time [s]');
legend(legends);
hold off
f.Position = [0 0 500 500];

%% Airspeed plot
f = figure;
hold on
for t=1:N
    plot(times, outUAV{t}.velocity_error.Data, colors(t));
end
title('Airspeed Error');
ylabel('Airspeed (m/s)');
xlabel('Time [s]');
legend(legends);
hold off
f.Position = [0 0 500 500];
    
%% Attitude plot
f = figure;
hold on
for t=1:N
    plot(times, rad2deg(outUAV{t}.yaw_error.Data), colors(t));
end
title('Yaw Error');
ylabel('Yaw (degree)');
xlabel('Time [s]');
legend(legends);
hold off

f = figure;
hold on
for t=1:N
    plot(times, rad2deg(outUAV{t}.error_roll.Data), colors(t));
end
title('Roll Error');
ylabel('Roll (degree)');
xlabel('Time [s]');
legend(legends);
hold off

f = figure;
hold on
for t=1:N
    plot(times, rad2deg(outUAV{t}.pitch_error.Data), colors(t));
end
title('Pitch Error');
ylabel('Pitch (degree)');
xlabel('Time [s]');
legend(legends);
hold off

end