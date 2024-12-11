#pragma once

#include <cassert>
#include <string>
#include <nlohmann/json.hpp>

namespace tt
{
	class c_json
	{
	public:
		c_json() {}
		c_json(nlohmann::json const& other) : data(other) {}
		c_json(std::string const& file_name);
		bool load(std::string const& file_name);
		bool is_empty() const { return data.empty(); }
		bool is_string() const { return data.is_string(); }
		bool is_number() const { return data.is_number(); }
		bool is_number_integer() const { return data.is_number_integer(); }
		bool is_number_unsigned() const { return data.is_number_unsigned(); }
		bool is_number_float() const { return data.is_number_float(); }
		c_json operator[](std::string const& key);
		c_json operator[](size_t index);

		template<typename T>
		T get() const
		{
			return data.get<T>();
		}

	private:
		nlohmann::json data;
	};
}