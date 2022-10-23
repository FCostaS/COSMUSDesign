function Fragmentation_plot(M, pos_hist, times, nb_agents)
    f = figure;
    for k=1:10:size(times)-1
        clf(f);
        x_axis = [];
        y_axis = [];
    
        pos = reshape(pos_hist(k,:),3,[]);
        pos_2 = reshape(pos_hist(k+6,:),3,[]);
        
        hold on;
        grid on;
        title(strcat('t= ',num2str(times(k)), ' [sec]'));
        %plot(WP(k,2), WP(k,1), 'or', 'MarkerSize', 10);
        for i=1:nb_agents
            pos_i = round(pos(1:2,i), 2);
            pos_i2 = round(pos_2(1:2,i), 2);
            x_axis = [x_axis; pos_i(2)]; y_axis = [y_axis; pos_i(1)];
            %text(pos_i(2), pos_i(1), num2str(i));
            
            th = atan2d(pos_i(1) - pos_i2(1), pos_i(2) - pos_i2(2)) + 180; 
            drawTriangle(5, pos_i, round(th, 2));
            
            %plot(pos_i(2), pos_i(1), '.-r', 'MarkerSize', 10, 'MarkerFaceColor', [0.5 0.5 0.5]);
            for j=i:nb_agents
               if(i ~= j && M{k}(i,j) == 1)
                   pos_j = round(pos(1:2,j), 2);
                   plot([pos_i(2) pos_j(2)], [pos_i(1) pos_j(1)], '-k', 'MarkerSize', 1, 'MarkerFaceColor', [0.5 0.5 0.5]);
               end
            end
        end
        X_c = mean(x_axis); Y_c = mean(y_axis);
        x_h = max(max(abs(X_c - min(x_axis)), abs(max(x_axis) - X_c)), 90);
        y_h = max(max(abs(Y_c - min(y_axis)), abs(max(y_axis) - Y_c)), 90);
        e = 5;
        h_0 = max(x_h, y_h) + e;

        %plot(X_c, Y_c, '.-r', 'MarkerSize', 10, 'MarkerFaceColor', [0.5 0.5 0.5]);
        
        xlim([X_c-x_h X_c+x_h]);
        ylim([Y_c-y_h Y_c+y_h]);
        xlabel('x (pos)');
        ylabel('y (pos)');
        drawnow;
    end
end