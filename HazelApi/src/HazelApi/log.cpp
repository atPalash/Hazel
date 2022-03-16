#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace HazelApi
{
    std::shared_ptr<spdlog::logger> Log::sCoreLogger;
    std::shared_ptr<spdlog::logger> Log::sClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%s");
        sCoreLogger = spdlog::stdout_color_mt("HAZEL");
        sCoreLogger->set_level(spdlog::level::trace);

        sClientLogger = spdlog::stdout_color_mt("APP");
        sClientLogger->set_level(spdlog::level::trace);
    }
}
