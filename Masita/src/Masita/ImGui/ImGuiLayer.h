#pragma once

#include "Masita/Layer.h"

#include "Masita/Events/ApplicationEvent.h"
#include "Masita/Events/KeyEvent.h"
#include "Masita/Events/MouseEvent.h"

namespace Masita {

    class MASITA_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };

}