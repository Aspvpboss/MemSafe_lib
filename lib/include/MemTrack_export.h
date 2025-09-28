#ifndef EXPORT_H
#define EXPORT_H


#ifdef _WIN32
    #ifdef DLL_EXPORTS
        #define MemSafe_API __declspec(dllexport)
    #elif defined(STATIC_LINK)
        #define MemSafe_API
    #else 
        #define MemSafe_API __declspec(dllimport)
    #endif
#else
    #define MemSafe_API
#endif


#endif