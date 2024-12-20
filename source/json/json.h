#pragma once

#include <cassert>
#include <string>
#include <nlohmann/json.hpp>

namespace tt
{
	class c_json
	{
	public:
		// Inner iterator class
		class iterator
		{
		public:
			using json_iterator = nlohmann::json::iterator;

			iterator(json_iterator it) : current(it) {}

			// Dereference to return a `c_json` object
			c_json operator*() const
			{
				return c_json(*current);
			}

			// Increment operators
			iterator& operator++()
			{
				++current;
				return *this;
			}
			iterator operator++(int)
			{
				iterator temp = *this;
				++(*this);
				return temp;
			}

			// Equality and inequality operators
			bool operator==(iterator const& other) const
			{
				return current == other.current;
			}
			bool operator!=(iterator const& other) const
			{
				return current != other.current;
			}

		private:
			json_iterator current;
		};

		// Public API
		c_json();
		c_json(nlohmann::json const& other);
		c_json(c_json const& other);
		c_json(std::string const& file_name);
		bool load(std::string const& file_name);
		bool is_empty() const { return data.empty(); }
		bool is_string() const { return data.is_string(); }
		bool is_number() const { return data.is_number(); }
		bool is_number_integer() const { return data.is_number_integer(); }
		bool is_number_unsigned() const { return data.is_number_unsigned(); }
		bool is_number_float() const { return data.is_number_float(); }
		bool is_array() const { return data.is_array(); }
		size_t size() const { return data.size(); }

		c_json operator[](std::string const& key);
		c_json operator[](size_t index);

		template<typename T>
		T get() const
		{
			return data.get<T>();
		}

		// Iterator methods
		iterator begin();
		iterator end();

	private:
		nlohmann::json data;
	};
}
