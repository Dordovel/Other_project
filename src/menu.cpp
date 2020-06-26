#include "../headers/menu.hpp"
#include "../struct/rectobject.hpp"
#include "../struct/vectorobject.hpp"
#include "../id.hpp"

namespace PROJECT::MENU
{
	bool Menu::menu_configure() noexcept
	{
		PROJECT::BASE::DATA::Vector2UI layoutSize = this->_layout->get_size();
		
		size_t size = 0;

		for(const auto& object : this->_item)
		{
			size += object->get_global_bounds().height;
		}

		if(size < layoutSize.y)
		{
			this->item_step = (layoutSize.y - size) / this->_item.size();

			PROJECT::BASE::DATA::Vector2UI layoutCenter = { (layoutSize.x / 2), (layoutSize.y / 2) };
			float x_center = layoutCenter.x;
			float y_pos = layoutCenter.y / 2;
			PROJECT::BASE::DATA::Vector2F pos{x_center, y_pos};

			for(const auto& object : this->_item)
			{
				object->set_position(pos);
				pos.y += this->item_step;
			}

			PROJECT::BASE::DATA::Vector2F firstElementPosition = (*this->_item.begin())->get_position();
			PROJECT::BASE::DATA::RectangleF pointerBounds = this->_pointer->get_global_bounds();
			this->_pointer->set_position(x_center - (pointerBounds.width * 2), firstElementPosition.y + (pointerBounds.height / 2));

			return true;
		}

		return false;
	}

	void Menu::set_layout(const std::shared_ptr<PROJECT::COLLECTION::ILayout>& layout) noexcept
	{
		this->reset();
		this->_layout = layout;
	}

	void Menu::set_pointer(const std::shared_ptr<OBJECT>& pointer) noexcept
	{
		this->_pointer = pointer;
	}

	void Menu::add_item(const std::shared_ptr<OBJECT>& object) noexcept
	{
		this->_item.emplace_back(object);
	}

	void Menu::step_forward() noexcept
	{
		std::string selected_item_id = this->selected_item();

		if(selected_item_id != this->_item.back()->get_id())
		{
			PROJECT::BASE::DATA::Vector2F oldPosition = this->_pointer->get_position();
			this->_pointer->set_position(oldPosition.x, oldPosition.y + this->item_step);
		}
	}

	void Menu::step_back() noexcept
	{	
		std::string selected_item_id = this->selected_item();

		if(selected_item_id != this->_item.front()->get_id())
		{
			PROJECT::BASE::DATA::Vector2F oldPosition = this->_pointer->get_position();
			this->_pointer->set_position(oldPosition.x, oldPosition.y - this->item_step);
		}
	}

	std::string Menu::selected_item() noexcept
	{
		PROJECT::BASE::DATA::Vector2F itemPosition;
		PROJECT::BASE::DATA::Vector2F pointerPosition = this->_pointer->get_position();
		PROJECT::BASE::DATA::RectangleF itemRect;

		for (const auto& object : this->_item)
		{
			itemPosition = object->get_position();
			itemRect = object->get_global_bounds();

			if(pointerPosition.y > itemPosition.y - itemRect.height
				&& pointerPosition.y < itemPosition.y + itemRect.height)
			{
				return object->get_id();
			}
		}

		return "";
	}


	void Menu::reset() noexcept
	{
		this->_item.clear();
		this->_layout = nullptr;
	}
};