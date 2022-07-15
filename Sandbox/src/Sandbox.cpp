#include <Luxo.h>

class Sandbox : public Luxo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Luxo::Application* Luxo::CreateApplication()
{
	return new Sandbox();
}