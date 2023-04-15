#pragma once

#include "../Common/CommonDefs.h"

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

	Actor();
	Actor(const std::string& _name, EActorType _type);
	~Actor();

	std::string GetName() const { return name_; }
	EActorType GetType() const { return type_; }

private :
	std::string name_;
	EActorType type_;
};

