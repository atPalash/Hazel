#include "hzpch.h"
#include "application.h"
#include "log.h"
#include "Events/applicationEvent.h"

#include <GLFW/glfw3.h>

namespace HazelApi
{
    # define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    Application::~Application()
    {

    }

    void Application::Run()
    {
        int count = 0;
        while(m_Running)
        {
            glClearColor(1,0,1,1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();

            for (Layer* layer : m_Layerstack)
            {
                layer->OnUpdate();
            }
        }
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispacther(e);

        dispacther.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
        HZ_CORE_TRACE("{0}", e.ToString());

        for(auto it = m_Layerstack.end(); it!=m_Layerstack.begin();)
        {
            (*--it)->OnEvent(e);
            if(e.Handled)
            {
                break;
            }
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        m_Layerstack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_Layerstack.PushOverlay(layer);
    }

    bool Application::OnWindowClosed(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }
}