#pragma once

#include "Core.h"

namespace Masita {

    class MASITA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in client
    Application* CreateApplication();

}