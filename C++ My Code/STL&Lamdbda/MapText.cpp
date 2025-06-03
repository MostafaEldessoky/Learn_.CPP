#include "MapText.h"
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>


MapText::MapText(std::string input) {

	std::ifstream inputFile{ input };

	if (!inputFile) {
		std::cout << "Error opening file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		line += " ";
		this->m_queue.push(line);
	}
	inputFile.close();
	int linecount = 0;
	while (!m_queue.empty()) {
		std::string theline = m_queue.front();
		m_queue.pop();
		std::vector<std::pair<std::string, int>> wardList;
		int wardCount = 0;
		std::string ward = "";
		std::for_each(theline.begin(), theline.end(),
			[&wardCount, &ward, &wardList](char c)
			{
				if (c != ' ')
				{
					ward += c;
				}
				else {
					if (!ward.empty()) {
						wardCount++;
						std::pair<std::string, int> temp{ ward,wardCount };
						ward.clear();
						wardList.push_back(temp);
					}
				}
			});
		linecount++;
		std::for_each(wardList.begin(), wardList.end(),
			[this, &linecount](std::pair<std::string, int> p) {
				this->m_encodingMap[p.first][linecount].push_back(p.second);
			});
	}

	std::map<int, std::map<std::string, std::vector<int>>> refactor;
	std::for_each(this->m_encodingMap.begin(), this->m_encodingMap.end(),
		[&refactor](std::pair<std::string, std::map<int, std::vector<int>>> x) {
			std::string temp = x.first ;
			std::for_each(x.second.begin(), x.second.end(),
				[&refactor,&temp](std::pair<int, std::vector<int>> y) {
					for (auto& i : y.second) {
						refactor[y.first][temp].push_back(i);
					}
				});
		});

	std::vector<std::vector<std::string>> formation;
	std::for_each(refactor.begin(), refactor.end(),
		[&formation](std::pair<int, std::map<std::string, std::vector<int>>> x) {
			int maxsize = 0;
			std::for_each(x.second.begin(), x.second.end(),
				[&maxsize](std::pair<std::string, std::vector<int>> y) mutable {
					for (auto& i : y.second) {
						if (i > maxsize) {
							maxsize = i;
						}
					};
				});
			formation.push_back(std::vector<std::string>(maxsize));
			maxsize = 0;
		});

	int i = 0;
	for (auto& a : refactor) {
		for (auto& b : a.second) {
			for (auto& c : b.second) {
				formation[i][c-1] = b.first;
			}
		}
		i++;
	}
	//-------------------------------------------------------------------------------------output------------------------------------
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "MapText Object Created:" << std::endl;
	std::cout << std::endl;
	std::for_each(this->m_encodingMap.begin(), this->m_encodingMap.end(),
		[](std::pair<std::string, std::map<int, std::vector<int>>> x) {
			std::cout << x.first << " : ";
			std::for_each(x.second.begin(), x.second.end(),
				[](std::pair<int, std::vector<int>> y) {
					std::cout << "(" << y.first << " : ";
					std::for_each(y.second.begin(), y.second.end(), [](int z) {
						std::cout << z << " ";
						});
					std::cout << ")";
				});
			std::cout << std::endl;
		});
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Formation:" << std::endl;
	std::cout << std::endl;
	std::for_each(formation.begin(), formation.end(), [](auto v) {
		std::for_each(v.begin(), v.end(), [](auto n) {
			std::cout << n << " ";
			});
		std::cout << std::endl;
		});
};

