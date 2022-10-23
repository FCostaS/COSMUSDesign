function Trajectory_plot(outUAV, R, Waypoints, N)
    WPS_X = Waypoints(:,1); 
    WPS_Y = Waypoints(:,2);
    
    fig = figure;
    hold on
    
    legends = cell(1, N + 2);
    colors = ["-r" "-b" "-c" "-y" "-k" "-w"];
    for t=1:N
        PlotUAV(outUAV{t}.Posicao.PositionY.Data, outUAV{t}.Posicao.PositionX.Data, colors(t));
        %PlotUAV(outUAV{2}.Posicao.PositionY.Data, outUAV{2}.Posicao.PositionX.Data, R, "-b");
        %PlotUAV(outUAV{3}.Posicao.PositionY.Data, outUAV{3}.Posicao.PositionX.Data, R, "-m");
        %PlotUAV(outUAV{4}.Posicao.PositionY.Data, outUAV{4}.Posicao.PositionX.Data, R, "-k");
        %PlotUAV(outUAV{5}.Posicao.PositionY.Data, outUAV{5}.Posicao.PositionX.Data, R, "-c");

        %PlotUAV(outUAV{1}.Posicao.PositionY.Data(1), outUAV{1}.Posicao.PositionX.Data(1), R, "*g");
        %PlotUAV(outUAV{2}.Posicao.PositionY.Data(1), outUAV{2}.Posicao.PositionX.Data(1), R, "*b");
        %PlotUAV(outUAV{3}.Posicao.PositionY.Data(1), outUAV{3}.Posicao.PositionX.Data(1), R, "*m");
        %PlotUAV(outUAV{4}.Posicao.PositionY.Data(1), outUAV{4}.Posicao.PositionX.Data(1), R, "*k");
        %PlotUAV(outUAV{5}.Posicao.PositionY.Data(1), outUAV{5}.Posicao.PositionX.Data(1), R, "*c");
        legends{t} = "UAV " + int2str(t);
    end
    title('Trajectory');
    fig.Position = [0 0 500 500];
    
    % initial position
    %circle(0, 0, 0.4*R, 'g.');
    legends{t+1} = "Start Point";
    circle(0, 0, 0.5*R, 'm.');
        
    % waypoints
    %circle(WPS_X, WPS_Y, R, 'y.');
    legends{t+2} = "Waypoints";
    circle(WPS_X, WPS_Y, R, 'r.');
    text(WPS_X,WPS_Y, string(1:length(WPS_X)), 'FontSize', 12);
    
    legend(legends);
    hold off
end