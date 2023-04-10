#include <sstream>
#include <iostream>

#include "URLSerializer.h"


using namespace std;


//	DELETE http://abc.ru/main/part2?param=3&param=4


URLSerializer::URLSerializer(const char* url)
{
    _URL = url;
    _Method = unknown;
}


HTTPMethod URLSerializer::GetMethod()
{
    if (_Method != unknown)
        return _Method;

    if (_URL.find("GET", 0) != string::npos)
        _Method = GET;
    else if (_URL.find("POST", 0) != string::npos)
        _Method = POST;
    else if (_URL.find("DELETE", 0) != string::npos)
        _Method = DELETE;
    else if (_URL.find("PUT", 0) != string::npos)
        _Method = PUT;
    else
        _Method = unknown;
}

const std::string& URLSerializer::GetURL()
{
    return _URL;
}

const std::string& URLSerializer::GetHost()
{
    if (!_Host.empty())
        return _Host;

    _Host = Split(_URL, '/')[1];

    return _Host;
}

const std::string& URLSerializer::GetPathParam(uint8_t paramNum)
{
    if (_PathParams.size() <= paramNum && paramNum != 0)
        return "";

    if (!_PathParams.empty())
        return "";

    auto params = Split(_URL, '/');

    if(params.size() < 3)   //если есть только хост
        return "";
    
    for (int i = 2; i < params.size() - 1; i++)
    {
        _PathParams.push_back(params[i]);
    }

    return _PathParams.at(paramNum);
}

const std::map<std::string, std::string>& URLSerializer::GetQueryStrings()
{
    if (!_QueryStrings.empty())
        return _QueryStrings;

    if (_URL.find("?", 0) == string::npos)
        return _QueryStrings;

    vector<string> queryStrings = Split(Split(_URL, '?')[1], '&');

    for (int i = 0; i < queryStrings.size(); i++)
    {
        auto pair = Split(queryStrings[i], '=');
        _QueryStrings.insert(std::pair<string, string>(pair[0], pair[1]));
    }

    return _QueryStrings;
}


vector<string> URLSerializer::Split(string& str, char del)
{
	vector<string> res;

    stringstream ss(str);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);

        if (word.empty())
            continue;

        res.push_back(word);
    }
    return res;
}