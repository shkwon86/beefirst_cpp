#include "ActorSpecification.h"

bool ActorFilter::is_satisfied(Actor* param)
{
	return false;
}

std::vector<Actor*> ActorFilter::filter(const std::vector<Actor*>& elements, Specification<Actor>& spec)
{
	std::vector<Actor*> result;
	for (auto actor : elements)
	{
		if (spec.is_satisfied(actor))
		{
			result.push_back(actor);
		}
	}

	return result;
}

ActorNameSpecification::ActorNameSpecification(const std::string& _name)
	: name_(_name)
{
}

bool ActorNameSpecification::is_satisfied(Actor* param)
{
	if (param->GetName() == name_)
	{
		return true;
	}

	return false;
}

ActorTypeSpecification::ActorTypeSpecification(EActorType _type)
	: actorType_(_type)
{
}

bool ActorTypeSpecification::is_satisfied(Actor* param)
{
	return param->GetType() == actorType_;
}
