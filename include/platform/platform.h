#pragma once

/* os detection */

#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOW
#elif defined(__ANDROID__)
    #define PLATFORM_ANDROID
#elif defined(__linux__)
    #define PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_0S_IPHONE
        #define PLATFORM_IOS
    #else
        #define PLATFORM_MACOS
    #endif
#else
    #error "OS not supported"
#endif

