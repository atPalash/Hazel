#include <iostream>
#include <hazel.h>

class ExampleLayer : public HazelApi::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {

        }

        void OnUpdate() override
        {
            HZ_INFO("ExampleLayer::Update");
        }

        void OnEvent(HazelApi::Event& event) override
        {
            HZ_TRACE("{0}", event.ToString());
        }
};

class SandBox : public HazelApi::Application
{
public:
    SandBox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new HazelApi::ImGuiLayer());
    }

    ~SandBox()
    {

    }
};

HazelApi::Application* HazelApi::CreateApplication()
{
    return new SandBox();
}