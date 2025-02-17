#pragma once
#include<vector>
#include <map>
#include "../Interface/ievents.hpp"
#include "../struct/eventobject.hpp"


class Events: public IEvents
{
    private:

        struct EventHandler
        {
            Keyboard_Key::Key key;
            std::function<void()> fun;
        };

        struct EventHandlerMousePressed
        {
            std::function<void(float X, float Y)> fun;
        };

        struct EventHandlerMouseMoved
        {
            std::function<void(float X, float Y)> fun;
        };

        struct EventHandlerMouseWheelScrolled
        {
            std::function<void(float X, float Y, float Delta)> fun;
        };

        struct EventHandlerMouseEntered
        {
            std::function<void()> fun;
        };

        struct EventHandlerMouseReleased
        {
            std::function<void()> fun;
        };

        EventObject _eventObject; 
		std::string _id;

        std::function<void()> _closeWindowEvent;

        std::vector<Events::EventHandler> _eventLoopPool;
        std::vector<Events::EventHandler> _eventNonePool;
        std::map<Mouse_Key::Button, Events::EventHandlerMousePressed> _eventMousePressedPool;
        std::vector<Events::EventHandlerMouseMoved> _eventMouseMovedPool;
        std::vector<Events::EventHandlerMouseWheelScrolled> _eventMouseWheelScrolledPool;
        std::vector<Events::EventHandlerMouseEntered> _eventMouseEnteredPool;
        std::vector<Events::EventHandlerMouseReleased> _eventMouseReleasedPool;

        std::vector<std::function<void()>> _gameEvents;

        inline void catch_mouse_pressed_event();
        inline void catch_mouse_wheel_scrolled_event();
        inline void catch_mouse_mouse_moved_event();
        inline void catch_mouse_enter_event();
        inline void catch_mouse_released_event();

    public:
        void set_close_window_event(const std::function<void()>& closeWindowEvent) override;
        void add_key_event(int key , const std::function<void()>& fun , EventHandlerType eventType) override;
        inline void catch_events_loop() override;
        inline void catch_events_none() override;

        void mouse_button_pressed(int key, const std::function<void(int X, int Y)>& fun) override;

        void mouse_button_released(const std::function<void()>& fun) override;

        void mouse_moved(const std::function<void(int X, int Y)>& fun) override;

        void mouse_wheel_scrolled(const std::function<void(int X, int Y, int Delta)>& fun) override;

        void mouse_entered(const std::function<void()>& fun) override;

        void add_user_event(const std::function<void()>& event) override;

        EventObject& get_event_object() override;

		std::string get_id() const override;

        void set_id(const std::string& id) override;

        ~Events() = default;
		Events() = default;
};
