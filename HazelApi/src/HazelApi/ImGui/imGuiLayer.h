#pragma once

#include "HazelApi/layer.h"

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
            float m_time = 0.0f;
    };
}
