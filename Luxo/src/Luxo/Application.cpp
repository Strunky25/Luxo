#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Luxo {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent evt(1280, 720);
		LX_TRACE(evt);
		while (true);
	}
}
