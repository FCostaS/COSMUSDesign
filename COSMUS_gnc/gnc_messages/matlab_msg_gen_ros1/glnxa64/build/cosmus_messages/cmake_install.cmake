# Install script for directory: /home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cosmus_messages/msg" TYPE FILE FILES
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Airspeed.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Communication.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Control_Surfaces.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Datagram.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/NetworkComm.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Odom.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Vector3D.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignal.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/WifiSignals.msg"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg/Wind.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cosmus_messages/cmake" TYPE FILE FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/build/cosmus_messages/catkin_generated/installspace/cosmus_messages-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/devel/include/cosmus_messages")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/home/fabricio/.matlab/R2021b/ros1/glnxa64/venv/bin/python2" -m compileall "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/devel/lib/python2.7/dist-packages/cosmus_messages")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/devel/lib/python2.7/dist-packages/cosmus_messages")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/build/cosmus_messages/catkin_generated/installspace/cosmus_messages.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cosmus_messages/cmake" TYPE FILE FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/build/cosmus_messages/catkin_generated/installspace/cosmus_messages-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cosmus_messages/cmake" TYPE FILE FILES
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/build/cosmus_messages/catkin_generated/installspace/cosmus_messagesConfig.cmake"
    "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/build/cosmus_messages/catkin_generated/installspace/cosmus_messagesConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cosmus_messages" TYPE FILE FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/devel/lib/libcosmus_messages_matlab.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcosmus_messages_matlab.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcosmus_messages_matlab.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcosmus_messages_matlab.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/m/" TYPE DIRECTORY FILES "/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/m/" FILES_MATCHING REGEX "/[^/]*\\.m$")
endif()

