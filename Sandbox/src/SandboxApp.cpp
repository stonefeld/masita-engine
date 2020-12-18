#include <Masita.h>
#include "imgui/imgui.h"

class ExampleLayer : public Masita::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {}

    virtual void OnUpdate() override
    {
        if (Masita::Input::IsKeyPressed(MA_KEY_TAB))
            MA_TRACE("Tab key is pressed!");
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    virtual void OnEvent(Masita::Event& event) override
    {
        if (event.GetEventType() == Masita::EventType::KeyPressed)
        {
            Masita::KeyPressedEvent& e = (Masita::KeyPressedEvent&)event;
            MA_TRACE("{0}", (char)e.GetKeyCode());
        }
    }
};

class Sandbox : public Masita::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {}
};

Masita::Application* Masita::CreateApplication()
{
    return new Sandbox();
}