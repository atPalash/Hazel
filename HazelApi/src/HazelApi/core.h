#ifndef CORE_H
#define CORE_H

#ifdef HZ_PLATFORM_WINDOWS
#ifdef HZ_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#error HazelApi only supports Windows
#endif
#define BIT(x) (1 << x)
#endif // CORE_H