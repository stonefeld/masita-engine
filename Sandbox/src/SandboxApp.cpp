#include <Masita.h>

class Sandbox : public Masita::Application
{
public:
    Sandbox()
    {}
    ~Sandbox()
    {}
};

Masita::Application* Masita::CreateApplication()
{
    return new Sandbox();
}