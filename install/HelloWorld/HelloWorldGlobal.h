#pragma once

#  ifdef HELLOWORLD_WIN
#    define DECL_EXPORT     __declspec(dllexport)
#    define DECL_IMPORT     __declspec(dllimport)
#  else
#    define DECL_EXPORT     __attribute__((visibility("default"))
#    define DECL_IMPORT     __attribute__((visibility("default")))
#  endif

#if defined(BUILD_SHARED) || !defined(BUILD_STATIC)
#  if defined(BUILD_HELLOWORLD_LIB)
#    define DLL_EXPORT DECL_EXPORT
#  else
#    define DLL_EXPORT DECL_IMPORT
#  endif
#else
#  define DLL_EXPORT
#endif