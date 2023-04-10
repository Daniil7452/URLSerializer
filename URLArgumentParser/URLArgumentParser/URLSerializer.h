#pragma once
#include "common.h"
#include <vector>
#include <string>
#include <map>




class URLSerializer
{
public:
	URLSerializer(const char* url);

	HTTPMethod GetMethod();

	const std::string& GetURL();

	const std::string& GetHost();

	const std::string& GetPathParam(uint8_t paramNum);

	const std::map<std::string, std::string>& GetQueryStrings();

private:
	HTTPMethod _Method;
	std::string _URL;
	std::string _Host;
	std::vector<std::string> _PathParams;
	std::map<std::string, std::string> _QueryStrings;

	static std::vector<std::string> Split(std::string& str, char del);


};

