#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef HZ_PLATFORM_WINDOWS

#include "application.h"
extern HazelApi::Application* HazelApi::CreateApplication();

int main(int argc, char** argv)
{
    HazelApi::Log::Init();
    auto app = HazelApi::CreateApplication();
    app->Run();
    delete app;
}
#endif

#endif // ENTRYPOINT_H