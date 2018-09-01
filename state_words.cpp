#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	std::vector<std::string> states;
	std::set<char> sLetters;

	std::ifstream stateList("states.txt");
	std::string s;

	while(std::getline(stateList, s))
	{
		states.push_back(s);

	}

	std::cout << s[12] << "\n";

}