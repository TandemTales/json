#include "json/json.h"
#include "core/log.h"

using namespace tt;

int main()
{
	c_json json;
	if (json.load("test.json"))
	{
		logln("json file test.json loaded successfully");
	}
	else
	{
		logln("json file test.json failed to load");
	}

	if (json["bedoop"].is_array())
	{
		logln("bedoop size: {}", json["bedoop"].size());
		for (c_json const& obj : json["bedoop"])
		{
			if (obj.is_string())
			{
				logln("bedoop: {}", obj.get<std::string>());
			}
			else if (obj.is_number())
			{
				if (obj.is_number_integer())
				{
					logln("bedoop: {}", obj.get<int64_t>());
				}
				else if (obj.is_number_unsigned())
				{
					logln("bedoop: {}", obj.get<uint64_t>());
				}
				else if (obj.is_number_float())
				{
					logln("bedoop: {}", obj.get<double>());
				}
			}
		}
	}
	return 0;
}
