#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Luxo {

	class LUXO_API Log
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

// Core Log macros
#define LX_CORE_TRACE(...)	::Luxo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LX_CORE_INFO(...)   ::Luxo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LX_CORE_WARN(...)   ::Luxo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LX_CORE_ERROR(...)  ::Luxo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LX_CORE_FATAL(...)  ::Luxo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define LX_TRACE(...)	    ::Luxo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LX_INFO(...)        ::Luxo::Log::GetClientLogger()->info(__VA_ARGS__)
#define LX_WARN(...)        ::Luxo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LX_ERROR(...)       ::Luxo::Log::GetClientLogger()->error(__VA_ARGS__)
#define LX_FATAL(...)       ::Luxo::Log::GetClientLogger()->fatal(__VA_ARGS__)


