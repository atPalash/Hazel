#ifndef LOG_H
#define LOG_H

#include "core.h"
#include "spdlog/spdlog.h"

namespace HazelApi
{
    class HAZEL_API Log
    {
        public:
            static void Init();
            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return sCoreLogger;}
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return sClientLogger;}

        private:
            static std::shared_ptr<spdlog::logger> sCoreLogger;
            static std::shared_ptr<spdlog::logger> sClientLogger;
    };
}

// core log macros
#define HZ_CORE_TRACE(...)  ::HazelApi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)   ::HazelApi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)   ::HazelApi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)  ::HazelApi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)  ::HazelApi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define HZ_CLIENT_TRACE(...)  ::HazelApi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_CLIENT_INFO(...)   ::HazelApi::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_CLIENT_WARN(...)   ::HazelApi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...)  ::HazelApi::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CLIENT_FATAL(...)  ::HazelApi::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // LOG_H
