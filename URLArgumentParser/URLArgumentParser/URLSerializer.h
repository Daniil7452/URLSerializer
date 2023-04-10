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
	/// вернет метод запроса
	/// </summary>
	HTTPMethod GetMethod();

	/// <summary>
	/// вернет URL
	/// </summary>
	const std::string& GetURL();

	/// <summary>
	/// ¬ернет хост
	/// </summary>
	const std::string& GetHost();

	/// <summary>
	/// вернет элементы пути запроса, если они содержатс€ в URL
	/// </summary>
	const std::string& GetPathParam(uint8_t paramNum);

	/// <summary>
	/// ¬ернет пары <аргумент, значение> запроса, если они содержатс€ в URL
	/// </summary>
	const std::map<std::string, std::string>& GetQueryStrings();

private:
	HTTPMethod _Method;
	std::string _URL;
	std::string _Host;
	std::vector<std::string> _PathParams;
	std::map<std::string, std::string> _QueryStrings;

	/// <summary>
	/// –азобьет строку на подстроки по указанному разделителю
	/// </summary>
	static std::vector<std::string> Split(std::string& str, char del);


};

