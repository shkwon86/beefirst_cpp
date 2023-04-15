#pragma once

#include "../Common/CommonDefs.h"

class Actor;

template <typename T> 
class AndSpecification;


template <typename T>
class Specification
{
public :
	virtual bool is_satisfied(T* param) = 0;
	AndSpecification<T> operator &&(Specification&& other)
	{
		return AndSpecification<T>(*this, other);
	}
};

template <typename T>
class AndSpecification : public Specification<T>
{
public :
	AndSpecification(Specification<T>& _first, Specification<T>& _second)
		: first_(_first)
		, second_(_second)
	{

	}

	virtual bool is_satisfied(T* param) override
	{
		return first_.is_satisfied(param) && second_.is_satisfied(param);
	}

private :
	Specification<T>& first_;
	Specification<T>& second_;
};

template <typename T>
class Filter : public Specification<T>
{
public :
	virtual std::vector<T*> filter(const std::vector<T*>& elements, Specification<T>& spec) = 0;
};
