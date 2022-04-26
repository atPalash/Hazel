#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"
#include "Events/event.h"
#include "Events/applicationEvent.h"
#include "Window.h"
#include "HazelApi/layerStack.h"

namespace HazelApi
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_Layerstack;

        bool OnWindowClosed(WindowCloseEvent& e);
    };

    // To be defined in client
    Application* CreateApplication();
}

#endif // APPLICATION_H