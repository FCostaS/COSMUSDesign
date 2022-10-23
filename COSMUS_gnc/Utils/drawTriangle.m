function drawTriangle(r, p, th)
    % calculate vertex locations
    xv = r*cosd(th+[0 150 200 0]) + p(2);
    yv = r*sind(th+[0 150 200 0]) + p(1);

    % plot this triangle
    plot(xv,yv)
    fill(xv, yv, 'k')
end