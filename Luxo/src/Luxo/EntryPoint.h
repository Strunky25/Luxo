#pragma once

#ifdef LX_PLATFORM_WINDOWS

extern Luxo::Application* Luxo::CreateApplication();

int main(int argc, char** argv)
{
	Luxo::Log::Init();
	LX_CORE_WARN("Initialized Log!");
	int a = 3;
	LX_INFO("Hello! Var={0}", a);

	auto app = Luxo::CreateApplication();
	app->Run();
	delete app;
}

#endif