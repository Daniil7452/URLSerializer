#pragma once
#include "common.h"
#include <vector>
#include <string>
#include <map>




class URLSerializer
{
public:
	URLSerializer(const char* url);

	/// <summary>
	/// 
	/// </summary>
	/// <returns>HTTP method</returns>
	HTTPMethod GetMethod();

	/// <summary>
	/// 
	/// </summary>
	/// <returns>URL</returns>
	const std::string& GetURL();

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Host</returns>
	const std::string& GetHost();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="paramNum">parameter number</param>
	/// <returns>HTTP path parameter</returns>
	const std::string& GetPathParam(uint8_t paramNum);

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Query strings, if contained in the URL</returns>
	const std::map<std::string, std::string>& GetQueryStrings();

private:
	HTTPMethod _Method;
	std::string _URL;
	std::string _Host;
	std::vector<std::string> _PathParams;
	std::map<std::string, std::string> _QueryStrings;

	/// <summary>
	/// Split the string into substrings according to the specified delimiter
	/// </summary>
	static std::vector<std::string> Split(std::string& str, char del);


};

