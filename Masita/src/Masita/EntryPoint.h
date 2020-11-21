#pragma once

#ifdef MA_PLATFORM_WINDOWS

extern Masita::Application* Masita::CreateApplication();

void main(int argc, char** argv)
{
    auto app = Masita::CreateApplication();
    app->Run();
    delete app;
}

#endif