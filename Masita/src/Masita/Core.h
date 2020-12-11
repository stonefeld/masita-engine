#pragma once

#ifdef MA_PLATFORM_WINDOWS
    #ifdef MA_BUILD_DLL
        #define MASITA_API __declspec(dllexport)
    #else
        #define MASITA_API __declspec(dllimport)
    #endif
#else
    #error Masita only supports Windows!
#endif

#ifdef MA_ENABLE_ASSERTS
    #define MA_ASSETS(x, ...) { if (!(x)) { MA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define MA_CORE_ASSERT(x, ...) { if (!(x)) { MA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define MA_ASSERT(x, ...)
    #define MA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)