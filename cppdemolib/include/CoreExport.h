#ifndef CPPDEMOLIB_COREEXPORT_H
#define CPPDEMOLIB_COREEXPORT_H



#if defined(CPPDEMOLIB_EXPORTS)
#ifdef _WIN32
#define CPPDEMOLIB_EXPORT __declspec(dllexport)
#else
#define CPPDEMOLIB_EXPORT __attribute__ ((visibility ("default")))
#endif
#else
#ifdef _WIN32
#define CPPDEMOLIB_EXPORT __declspec(dllimport)
#else
#define CPPDEMOLIB_EXPORT
#endif
#endif

#ifndef _WIN32
#define CPPDEMOLIB_EXPORT_NON_WIN32 CPPDEMOLIB_EXPORT
#else
#define CPPDEMOLIB_EXPORT_NON_WIN32
#endif



#endif
