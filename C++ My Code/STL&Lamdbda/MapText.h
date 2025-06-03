#pragma once
#include <string>
#include <vector>
#include <queue>
#include <map>

class MapText
{
	std::queue<std::string> m_queue;
	std::map<std::string, std::map<int, std::vector<int>>> m_encodingMap;

public:

	MapText(std::string);

};

