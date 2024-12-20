#include "json.h"

#include <fstream>

namespace tt
{
	c_json::c_json() {}

	c_json::c_json(nlohmann::json const& other) : data(other) {}

	c_json::c_json(c_json const& other) : data(other.data) {}

	c_json::c_json(std::string const& file_name)
	{
		load(file_name);
	}

	bool c_json::load(std::string const& file_name)
	{
		std::ifstream file(file_name.c_str());
		if (!file.is_open())
		{
			return false;
		}
		file >> data;
		return true;
	}

	c_json c_json::operator[](std::string const& key)
	{
		if (data.is_object())
		{
			nlohmann::json& value = data[key];
			return c_json(value);
		}
		return c_json();
	}

	c_json c_json::operator[](size_t index)
	{
		if (data.is_array())
		{
			nlohmann::json& value = data[index];
			return c_json(value);
		}
		return c_json();
	}

	c_json::iterator c_json::begin()
	{
		if (data.is_array())
		{
			return iterator(data.begin());
		}
		return iterator(nlohmann::json::iterator());
	}

	c_json::iterator c_json::end()
	{
		if (data.is_array())
		{
			return iterator(data.end());
		}
		return iterator(nlohmann::json::iterator());
	}
}