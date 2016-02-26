#include "utils.h"

namespace utils
{
	bool fileExists(const std::string& name)
	{
		std::ifstream strStream(name.c_str());
		if (strStream.good()) {
			strStream.close();
			return true;
		}
		else {
			strStream.close();
			return false;
		}
	}

	std::string getStrFromUser(std::string output)
	{
		std::string testStr;
		std::cout << output;
		std::cin >> testStr;
		return testStr;
	}
}