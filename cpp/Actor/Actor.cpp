#include "Actor.h"

Actor::Actor()
	: name_("")
	, type_(None)
{
}

Actor::Actor(const std::string& _name, EActorType _type)
	: name_(_name)
	, type_(_type)
{
}

Actor::~Actor()
{
}
