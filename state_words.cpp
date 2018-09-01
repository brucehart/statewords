#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

bool isMatch(std::set<char>& letters, std::string word)
{
	for (char w: word)
		if (letters.count(w) > 0) return true;

	return false;
}

std::vector<int> noMatches(std::vector<std::set<char>>& sLetters, std::string word)
{
	std::vector<int> result;

	for (int i=0;i<sLetters.size();i++)
	{
		if (!isMatch(sLetters[i], word))
			result.push_back(i);
	}

	return result;
}

int main(int argc, char** argv)
{
	std::vector<std::string> states;
	std::vector<std::set<char>> sLetters;

	std::ifstream stateList("states.txt");
	std::string s;

	std::ifstream wordList("words.txt");
	std::string w; 

	while(std::getline(stateList, s))
	{
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);	
		std::set<char> sChars;
		states.push_back(s);
		sChars.insert(s.begin(), s.end());
		sLetters.push_back(sChars);
	}

	while(std::getline(wordList, w))
	{
		std::transform(w.begin(), w.end(), w.begin(), [](auto const& c)->)
		auto nm = noMatches(sLetters, w);

		if (nm.size() == 1)
			std::cout << w << " : " << states[nm[0]] << "\n";
	}
}