#include "json.h"
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

	double bedoop2 = json["bedoop"][2].get<double>();
	logln("boop: {}, {}, {}", json["bedoop"][0].get<std::string>(), json["bedoop"][1].get<uint64_t>(), json["bedoop"][2].get<double>());

	return 0;
}
