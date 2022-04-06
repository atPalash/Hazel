#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"

namespace HazelApi
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in client
    Application* CreateApplication();
}

#endif // APPLICATION_H