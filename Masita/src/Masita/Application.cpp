#include "mapch.h"
#include "Application.h"

#include "Masita/Events/ApplicationEvent.h"
#include "Masita/Log.h"

namespace Masita {

    Application::Application()
    {}

    Application::~Application()
    {}

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            MA_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            MA_TRACE(e);
        }

        while (true);
    }

}