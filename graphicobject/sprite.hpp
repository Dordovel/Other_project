#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../struct/databaseresult.hpp"
#include "./isprite.hpp"

namespace PROJECT::BASE::GRAPHIC
{
    class Sprite : public PROJECT::BASE::GRAPHIC::ISprite
    {
        private:
            std::shared_ptr<sf::Sprite> _sprite;
            std::shared_ptr<sf::Texture> _texture;
            std::string _id;
            bool _isVisible;
        
            bool _up;
            bool _down;
            bool _left;
            bool _right;


        public:

            PROJECT::BASE::DATA::DrawableObject draw() const noexcept override;

            void move(const PROJECT::BASE::DATA::Vector2F& step) noexcept override;

            void move(float X, float Y) noexcept override;

            void set_position(const PROJECT::BASE::DATA::Vector2F& position) noexcept override;

            void set_position(float X, float Y) noexcept override;

            PROJECT::BASE::DATA::Vector2F get_position() const noexcept override;

            PROJECT::BASE::DATA::RectangleF get_global_bounds() const noexcept override;

            bool collision(const std::shared_ptr<INTERACTION>& object) noexcept override;
            
            bool collision(const PROJECT::BASE::DATA::Vector2F& vec) noexcept override;

            bool collision(const PROJECT::BASE::DATA::RectangleF& rect) noexcept override;

            void visible(bool flag) noexcept override;

            bool is_visible() noexcept override;

            void set_scale(PROJECT::BASE::DATA::Vector2F scale) noexcept override;

            PROJECT::BASE::DATA::Vector2F get_scale() noexcept override;

            std::string get_id() const noexcept override;

            void block_side(PROJECT::MOVE::Side side, bool status) noexcept override;

            void block_all_side() noexcept override;

            void unblock_all_side() noexcept override;

            void set_texture_rect(const PROJECT::BASE::DATA::RectangleI& rect) override;
			
            explicit Sprite(const PROJECT::DATABASE::DataBaseResult& data, std::string_view id);

            ~Sprite();
			
			Sprite(Sprite&&) = default;

			Sprite& operator= (Sprite&&) = default;
    };
};
