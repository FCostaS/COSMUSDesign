# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "cosmus_messages: 10 messages, 0 services")

set(MSG_I_FLAGS "-Icosmus_messages:/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg;-Istd_msgs:/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Istd_msgs:/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cosmus_messages_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg" ""
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg" "cosmus_messages/Vector3D:std_msgs/Header"
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg" ""
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg" "cosmus_messages/Communication"
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg" ""
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg" "cosmus_messages/Vector3D"
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg" ""
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg" ""
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg" "cosmus_messages/Vector3D"
)

get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg" NAME_WE)
add_custom_target(_cosmus_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cosmus_messages" "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg" "cosmus_messages/WifiSignal"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg;/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)
_generate_msg_cpp(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
)

### Generating Services

### Generating Module File
_generate_module_cpp(cosmus_messages
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cosmus_messages_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cosmus_messages_generate_messages cosmus_messages_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_cpp _cosmus_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cosmus_messages_gencpp)
add_dependencies(cosmus_messages_gencpp cosmus_messages_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cosmus_messages_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg;/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)
_generate_msg_py(cosmus_messages
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg"
  "${MSG_I_FLAGS}"
  "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
)

### Generating Services

### Generating Module File
_generate_module_py(cosmus_messages
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cosmus_messages_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cosmus_messages_generate_messages cosmus_messages_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg" NAME_WE)
add_dependencies(cosmus_messages_generate_messages_py _cosmus_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cosmus_messages_genpy)
add_dependencies(cosmus_messages_genpy cosmus_messages_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cosmus_messages_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cosmus_messages
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cosmus_messages_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cosmus_messages_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages)
  install(CODE "execute_process(COMMAND \"/home/fabricio/.matlab/R2021b/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cosmus_messages
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cosmus_messages_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cosmus_messages_generate_messages_py std_msgs_generate_messages_py)
endif()
