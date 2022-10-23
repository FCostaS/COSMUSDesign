function circle(x, y, r, color)
    %x and y are the coordinates of the center of the circle
    %r is the radius of the circle
    %0.01 is the angle step, bigger values will draw the circle faster but
    %you might notice imperfections (not very smooth)
    ang = 0:0.01:2*pi; 
    xp=r*cos(ang);
    yp=r*sin(ang);
    
    n = length(x);
    for t=1:n
        plot(x(t)+xp, y(t)+yp, color);
    end
end