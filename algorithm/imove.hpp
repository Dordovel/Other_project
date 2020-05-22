#pragma once

#include <memory>
#include "../Interface/iclock.hpp"
#include "../Interface/iphysics.hpp"
#include "../Interface/icollection.hpp"
#include "../object/object.hpp"

enum class SIDE;

class IMove
{
    public:
		virtual void move(SIDE side, const std::shared_ptr<MOVABLE>& object, float clock, float speed) = 0;

		virtual void block_side(SIDE side, bool status) = 0;
        
		virtual ~IMove() = default;
};
