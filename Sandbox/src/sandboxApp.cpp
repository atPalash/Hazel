#include <iostream>
#include <hazel.h>


class SandBox : public HazelApi::Application
{
public:
    SandBox()
    {

    }

    ~SandBox()
    {

    }
};

HazelApi::Application* HazelApi::CreateApplication()
{
    return new SandBox();
}
