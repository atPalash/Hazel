#pragma once

#include "HazelApi/layer.h"
#include "HazelApi/Events/applicationEvent.h"
#include "HazelApi/Events/mouseEvent.h"
#include "HazelApi/Events/keyEvent.h"

namespace HazelApi
{
    class HAZEL_API ImGuiLayer : public Layer
    {
        public:
            ImGuiLayer();
            ~ImGuiLayer();

            void OnAttach();
            void OnDettach();
            void OnUpdate();
            void OnEvent(Event& event);
        private:
            bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
            bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
            bool OnMouseButtonMovedEvent(MouseMovedEvent& e);
            bool OnMouseButtonScrolledEvent(MouseScrolledEvent& e);
            bool OnKeyPressedEvent(KeyPressedEvent& e);
            bool OnKeyReleasedEvent(KeyReleasedEvent& e);
            bool OnKeyTypedEvent(KeyTypedEvent& e);
            bool OnWindowResizedEvent(WindowResizeEvent& e);

        private:
            float m_time = 0.0f;
    };
}