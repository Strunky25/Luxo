#pragma once

#ifdef LX_PLATFORM_WINDOWS
	#ifdef LX_BUILD_DLL
		#define LUXO_API __declspec(dllexport)
	#else
		#define LUXO_API __declspec(dllimport)
	#endif	
#else
	#error Luxo only supports Windows!
#endif

#define BIT(x) (1 << x)