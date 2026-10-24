#pragma once

#if defined(_WIN32)
#if DIORAMA_API_BUILD
#define DIORAMA_API __declspec(dllexport)
#else
#define DIORAMA_API __declspec(dllimport)
#endif
#elif defined(__GNUC__) || defined(__clang__)
#define DIORAMA_API __attribute__((visibility("default")))
#else
#define DIORAMA_API
#endif

#ifdef __cplusplus
#define DIORAMA_API_SCOPE_START \
    extern "C"                  \
    {
#define DIORAMA_API_SCOPE_END   \
    }
#else
#define DIORAMA_API_SCOPE_START 
#define DIORAMA_API_SCOPE_END 
#endif