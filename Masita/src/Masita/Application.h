#pragma once

#include "Core.h"

#include "Window.h"
#include "Masita/LayerStack.h"
#include "Masita/Events/Event.h"
#include "Masita/Events/ApplicationEvent.h"

namespace Masita {

    class MASITA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be defined in client
    Application* CreateApplication();

}