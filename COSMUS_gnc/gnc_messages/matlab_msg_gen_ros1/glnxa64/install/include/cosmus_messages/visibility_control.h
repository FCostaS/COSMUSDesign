#ifndef COSMUS_MESSAGES__VISIBILITY_CONTROL_H_
#define COSMUS_MESSAGES__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define COSMUS_MESSAGES_EXPORT __attribute__ ((dllexport))
    #define COSMUS_MESSAGES_IMPORT __attribute__ ((dllimport))
  #else
    #define COSMUS_MESSAGES_EXPORT __declspec(dllexport)
    #define COSMUS_MESSAGES_IMPORT __declspec(dllimport)
  #endif
  #ifdef COSMUS_MESSAGES_BUILDING_LIBRARY
    #define COSMUS_MESSAGES_PUBLIC COSMUS_MESSAGES_EXPORT
  #else
    #define COSMUS_MESSAGES_PUBLIC COSMUS_MESSAGES_IMPORT
  #endif
  #define COSMUS_MESSAGES_PUBLIC_TYPE COSMUS_MESSAGES_PUBLIC
  #define COSMUS_MESSAGES_LOCAL
#else
  #define COSMUS_MESSAGES_EXPORT __attribute__ ((visibility("default")))
  #define COSMUS_MESSAGES_IMPORT
  #if __GNUC__ >= 4
    #define COSMUS_MESSAGES_PUBLIC __attribute__ ((visibility("default")))
    #define COSMUS_MESSAGES_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define COSMUS_MESSAGES_PUBLIC
    #define COSMUS_MESSAGES_LOCAL
  #endif
  #define COSMUS_MESSAGES_PUBLIC_TYPE
#endif
#endif  // COSMUS_MESSAGES__VISIBILITY_CONTROL_H_
// Generated 19-Jul-2022 13:01:17
// Copyright 2019-2020 The MathWorks, Inc.
