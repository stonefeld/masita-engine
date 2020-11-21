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
