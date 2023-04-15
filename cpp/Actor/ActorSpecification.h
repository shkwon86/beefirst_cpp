#pragma once

#include "Actor.h"
#include "ActorFilter.h"


class ActorFilter : public Filter<Actor>
{
public:
	virtual bool is_satisfied(Actor* param) override;
	virtual std::vector<Actor*> filter(const std::vector<Actor*>& elements, Specification<Actor>& spec) override;
};


class ActorNameSpecification : public Specification<Actor>
{
public:

	ActorNameSpecification(const std::string& _name);

	virtual bool is_satisfied(Actor* param) override;

	std::string GetName() const { return name_; }
	void SetName(const std::string& _name) { name_ = _name; }

private:
	std::string name_;
};

class ActorTypeSpecification : public Specification<Actor>
{
public:

	ActorTypeSpecification(EActorType _type);

	virtual bool is_satisfied(Actor* param) override;

	EActorType GetType() const { return actorType_; }

private:
	EActorType actorType_;
};
