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
	/// ������ ����� �������
	/// </summary>
	HTTPMethod GetMethod();

	/// <summary>
	/// ������ URL
	/// </summary>
	const std::string& GetURL();

	/// <summary>
	/// ������ ����
	/// </summary>
	const std::string& GetHost();

	/// <summary>
	/// ������ �������� ���� �������, ���� ��� ���������� � URL
	/// </summary>
	const std::string& GetPathParam(uint8_t paramNum);

	/// <summary>
	/// ������ ���� <��������, ��������> �������, ���� ��� ���������� � URL
	/// </summary>
	const std::map<std::string, std::string>& GetQueryStrings();

private:
	HTTPMethod _Method;
	std::string _URL;
	std::string _Host;
	std::vector<std::string> _PathParams;
	std::map<std::string, std::string> _QueryStrings;

	/// <summary>
	/// �������� ������ �� ��������� �� ���������� �����������
	/// </summary>
	static std::vector<std::string> Split(std::string& str, char del);


};

