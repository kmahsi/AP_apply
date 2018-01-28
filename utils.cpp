#ifndef SPLIT_BY_DELIMITER
#define SPLIT_BY_DELIMITER
#include <iostream>
#include <list>


std::list<std::string> splitByDelimiter(std::string str, char delimiter)
{
	std::list<std::string> result;	
	while( str.find(delimiter) != std::string::npos)		
	{
		result.push_back(str.substr(0, str.find(delimiter)));
		str = str.substr(str.find(delimiter) + 1);
	}
	result.push_back(str);
	return result;
}



#endif