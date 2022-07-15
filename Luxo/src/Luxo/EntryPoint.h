#pragma once

#ifdef LX_PLATFORM_WINDOWS

extern Luxo::Application* Luxo::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Luxo::CreateApplication();
	app->Run();
	delete app;
}

#endif