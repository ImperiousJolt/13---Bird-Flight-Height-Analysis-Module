#ifdef HERMES_STATIC
#define HERMES_API
#endif

#ifndef HERMES_STATIC

#ifdef HERMESAPI_EXPORTS
#define HERMES_API __declspec(dllexport)
#else
#define HERMES_API __declspec(dllimport)
#endif

#endif
