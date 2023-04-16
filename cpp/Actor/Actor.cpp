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

std::unique_ptr<ActorBuilder> Actor::Build(const std::string& _name, EActorType _type)
{
	return std::make_unique<ActorBuilder>(_name, _type);
}

void Actor::AddChild(std::shared_ptr<Actor> _child)
{
	childActor_.emplace_back(_child);
}
