#include "day4.hpp"

bool sortingLetters(pair<char, int> a, pair<char, int> b)
{
	return (a.second > b.second) ||
		   (a.second == b.second && a.first < b.first);
}

string decryptName(string name, int key)
{
	string result = "";

	for (auto letter : name)
		result += (letter + (key % 26) - 'a') % 26 + 'a';

	return result;
}

bool isRoomValid(string id, string name, string checksum)
{
	map<char, int> lettersCount;
	string validChecksum = "";

	for (auto letter : name)
		lettersCount[letter]++;

	vector<pair<char, int>> orderedLetters;
	for (auto letter : lettersCount)
		orderedLetters.push_back(pair<char, int>(letter.first, letter.second));
	std::sort(orderedLetters.begin(), orderedLetters.end(), sortingLetters);

	for (int i = 0; i < 5; i++)
		validChecksum += orderedLetters[i].first;

	return checksum == validChecksum;
}

int solveDay4part1(string input)
{
	vector<string> rooms = split(input, "\n");
	int validIdsSum = 0;

	for (auto room : rooms)
	{
		map<char, int> lettersCount;
		vector<string> parts = split(room, "-");
		string lastPart = parts[parts.size() - 1];
		string id = lastPart.substr(0, lastPart.find_first_of("["));
		string checksum = lastPart.substr(lastPart.find_first_of("[")+1, 5);
		string name = "";

		parts.erase(parts.end() - 1);
		name = implode(parts, "");

		if (isRoomValid(id, name, checksum))
			validIdsSum += stoi(id);
	}

	return validIdsSum;
}

int solveDay4part2(string input)
{
	vector<string> rooms = split(input, "\n");

	for (auto room : rooms)
	{
		map<char, int> lettersCount;
		vector<string> parts = split(room, "-");
		string lastPart = parts[parts.size() - 1];
		string id = lastPart.substr(0, lastPart.find_first_of("["));
		string checksum = lastPart.substr(lastPart.find_first_of("[") + 1, 5);
		string name = "";

		parts.erase(parts.end() - 1);
		name = implode(parts, "");

		if (isRoomValid(id, name, checksum))
		{ 
			for (auto part : parts)
				if (decryptName(part, stoi(id)).find("north") != string::npos)
					return stoi(id);
		}
	}

	return 0;
}