// generated by CommonPackage.cmake, do not edit.

/**
 * @file include/cyme/defines.h
 * Includes compile-time defines of cyme.
 */

#ifndef CYME_DEFINES_H
#define CYME_DEFINES_H

#ifdef __APPLE__
#  include <cyme/definesDarwin.h>
#elif defined (__linux__)
#  include <cyme/definesLinux.h>
#elif defined (_WIN32)
#  include <cyme/definesWin32.h>
#else
#  error Unknown OS
#endif

#endif
