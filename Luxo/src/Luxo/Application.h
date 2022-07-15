#pragma once

#include "Core.h"

namespace Luxo {

	class LUXO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

