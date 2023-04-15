#pragma once

#include "../Common/CommonDefs.h"

class Tag
{
protected:

	friend std::ostream& operator<<(std::ostream& _os, const Tag& _tag)
	{
		std::cout << "name: " << _tag.name_ << ", " << _tag.text_ << std::endl;
		return _os;
	}

	Tag(const std::string& _name, const std::string& _text)
		: name_(_name)
		, text_(_text)
	{}

	Tag(const std::string& _name, const std::vector<Tag>& _children)
		: name_(_name)
		, children_{_children}
	{}

public :
	std::string name_;
	std::string text_;
	std::vector<Tag> children_;
	std::vector<std::pair<std::string, std::string>> attriibutes;
};

class P : public Tag
{
public :
	explicit P(const std::string& _text)
		: Tag{ "P", _text }
	{}

	P(std::initializer_list<Tag> _children)
		: Tag{ "P", _children }
	{}
};

class IMG : public Tag
{
public :
	explicit IMG(const std::string& _url)
		: Tag{ "img", "" }
	{
		attriibutes.emplace_back("src", _url);
	}
};