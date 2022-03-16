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
        std::string name = "";
        std::cout << "Enter your name " ;
        std::cin >> name;
        std::cout << std::endl;

        std::cout << "Entered name " << name << std::endl;
        while(count < 100)
        {
            std::cout << "time now " << count << std::endl;
            count++;
        }
    }
}

