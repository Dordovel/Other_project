#pragma once
#include "../Interface/iapplication.hpp"
#include <memory>
#include "../Interface/ievents.hpp"
#include "../struct/eventobject.hpp"
#include "../Interface/iclock.hpp"
#include "../Interface/icore.hpp"
#include <map>


class Core : public ICore
{
    private:
        std::shared_ptr<IApplication> _window;
        std::shared_ptr<IEventDispatcher> _eventDispatcher;
		std::shared_ptr<ILayoutDispatcher> _layoutDispatcher;

    public:
        void run() noexcept override;

        void close() noexcept override;

        void register_app(const std::shared_ptr<IApplication>& window) noexcept override;

        void set_event_dispatcher(const std::shared_ptr<IEventDispatcher>& eventDispatcher) noexcept override;

		void set_layout_dispatcher(const std::shared_ptr<ILayoutDispatcher>& layoutDispatcher) noexcept override;

		Core() = default;
		~Core() = default;
};
