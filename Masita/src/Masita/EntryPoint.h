#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Masita::Application* Masita::CreateApplication();

void main(int argc, char** argv)
{
    Masita::Log::Init();
    MA_CORE_WARN("Initialized Log!");
    int a = 5;
    MA_INFO("Hello! Var={0}", a);

    auto app = Masita::CreateApplication();
    app->Run();
    delete app;
}

#endif