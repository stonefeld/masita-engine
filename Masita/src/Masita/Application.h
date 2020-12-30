#pragma once

#include "Core.h"

#include "Window.h"
#include "Masita/LayerStack.h"
#include "Masita/Events/Event.h"
#include "Masita/Events/ApplicationEvent.h"

#include "Masita/ImGui/ImGuiLayer.h"

#include "Masita/Renderer/Shader.h"

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

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        static Application* s_Instance;

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

        std::unique_ptr<Shader> m_Shader;   
    };

    // To be defined in client
    Application* CreateApplication();

}