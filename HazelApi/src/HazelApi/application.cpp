#include "application.h"
#include <iostream>

namespace HazelApi
{
    Application::Application()
    {

    }
    Application::~Application()
    {

    }

    void Application::Run()
    {
        int count = 0;
        while(count < 100)
        {
            std::cout << "time now " << count << std::endl;
            count++;
        }
    }
}

