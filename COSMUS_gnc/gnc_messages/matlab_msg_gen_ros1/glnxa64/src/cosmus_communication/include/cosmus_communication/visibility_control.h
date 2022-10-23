#ifndef COSMUS_COMMUNICATION__VISIBILITY_CONTROL_H_
#define COSMUS_COMMUNICATION__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define COSMUS_COMMUNICATION_EXPORT __attribute__ ((dllexport))
    #define COSMUS_COMMUNICATION_IMPORT __attribute__ ((dllimport))
  #else
    #define COSMUS_COMMUNICATION_EXPORT __declspec(dllexport)
    #define COSMUS_COMMUNICATION_IMPORT __declspec(dllimport)
  #endif
  #ifdef COSMUS_COMMUNICATION_BUILDING_LIBRARY
    #define COSMUS_COMMUNICATION_PUBLIC COSMUS_COMMUNICATION_EXPORT
  #else
    #define COSMUS_COMMUNICATION_PUBLIC COSMUS_COMMUNICATION_IMPORT
  #endif
  #define COSMUS_COMMUNICATION_PUBLIC_TYPE COSMUS_COMMUNICATION_PUBLIC
  #define COSMUS_COMMUNICATION_LOCAL
#else
  #define COSMUS_COMMUNICATION_EXPORT __attribute__ ((visibility("default")))
  #define COSMUS_COMMUNICATION_IMPORT
  #if __GNUC__ >= 4
    #define COSMUS_COMMUNICATION_PUBLIC __attribute__ ((visibility("default")))
    #define COSMUS_COMMUNICATION_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define COSMUS_COMMUNICATION_PUBLIC
    #define COSMUS_COMMUNICATION_LOCAL
  #endif
  #define COSMUS_COMMUNICATION_PUBLIC_TYPE
#endif
#endif  // COSMUS_COMMUNICATION__VISIBILITY_CONTROL_H_
// Generated 19-Jul-2022 13:01:16
// Copyright 2019-2020 The MathWorks, Inc.
