#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef HZ_PLATFORM_WINDOWS

#include "application.h"
#include "log.h"

extern HazelApi::Application* HazelApi::CreateApplication();

int main(int argc, char** argv)
{
    HazelApi::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    HZ_CLIENT_INFO("Hello Log!");

    auto app = HazelApi::CreateApplication();
    app->Run();
    delete app;
}
#endif

#endif // ENTRYPOINT_H
