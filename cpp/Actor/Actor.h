#pragma once

#include "../Common/CommonDefs.h"
#include "Builder.h"

enum EActorType
{
	None,
	Player,
	Monster,
	Object,
	Max
};

/**
 * Actor Class
 */
class Actor
{
public :
	friend ActorBuilder;

	~Actor();

	static std::unique_ptr<ActorBuilder> Build(const std::string& _name, EActorType _type);

	void AddChild(std::shared_ptr<Actor> _child);

	std::string GetName() const { return name_; }
	EActorType GetType() const { return type_; }

protected :
	Actor();
	Actor(const std::string& _name, EActorType _type);

private :
	std::string name_;
	EActorType type_;
	std::vector<std::shared_ptr<Actor>> childActor_;
};

