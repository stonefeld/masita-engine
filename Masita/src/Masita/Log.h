#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Core.h"

namespace Masita {

    class MASITA_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
#define MA_CORE_TRACE(...)    ::Masita::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MA_CORE_INFO(...)     ::Masita::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MA_CORE_WARN(...)     ::Masita::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MA_CORE_ERROR(...)    ::Masita::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MA_CORE_CRITICAL(...) ::Masita::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MA_TRACE(...)         ::Masita::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MA_INFO(...)          ::Masita::Log::GetClientLogger()->info(__VA_ARGS__)
#define MA_WARN(...)          ::Masita::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MA_ERROR(...)         ::Masita::Log::GetClientLogger()->error(__VA_ARGS__)
#define MA_CRITICAL(...)      ::Masita::Log::GetClientLogger()->critical(__VA_ARGS__)