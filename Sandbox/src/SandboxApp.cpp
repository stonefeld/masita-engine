#include <Masita.h>

class ExampleLayer : public Masita::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {}

    void OnUpdate() override
    {
        MA_INFO("ExampleLayer::Update");
    }

    void OnEvent(Masita::Event& event) override
    {
        MA_TRACE("{0}", event);
    }
};

class Sandbox : public Masita::Application
{
public:
    Sandbox()
    {
        //PushLayer(new ExampleLayer());
        PushOverlay(new Masita::ImGuiLayer());
    }

    ~Sandbox()
    {}
};

Masita::Application* Masita::CreateApplication()
{
    return new Sandbox();
}