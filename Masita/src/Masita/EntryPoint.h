#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Masita::Application* Masita::CreateApplication();

void main(int argc, char** argv)
{
    Masita::Log::Init();
    MA_CORE_WARN("Initialized Log!");

    auto app = Masita::CreateApplication();
    app->Run();
    delete app;
}

#endif