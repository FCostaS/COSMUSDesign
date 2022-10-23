% Install custom messages

cd('/home/fabricio/catkin_ws/src/COSMUS_gnc');

% Add ROS Custom Messages
pyenv('Version','2.7');
mex -setup cpp % Select Microsoft Visual C++ 2017
path_name = strcat(pwd,'/gnc_messages');
rosgenmsg(path_name);

% windows
addpath( strcat(path_name,'\matlab_msg_gen_ros1\win64\install\m') );

% linux
addpath( strcat(path_name, '/matlab_msg_gen_ros1/glnxa64/install/m') );

savepath
clear classes
rehash toolboxcache

