#pragma once

#include "day6.hpp"

bool mostCommonLetter(pair<char, int> a, pair<char, int> b)
{
	return (a.second > b.second) ||
		(a.second == b.second && a.first < b.first);
}

vector<vector<pair<char, int>>> charsCountByColumn(string input)
{
	vector<string> rows = split(input, "\n");
	vector<vector<pair<char, int>>> result;

	for (unsigned int i = 0; i < rows[0].size(); i++)
	{
		map<char, int> lettersCount;
		vector<pair<char, int>> orderedLetters;

		for (unsigned int j = 0; j < rows.size(); j++)
			lettersCount[rows[j][i]]++;

		for (auto letter : lettersCount)
			orderedLetters.push_back(pair<char, int>(letter.first, letter.second));
		std::sort(orderedLetters.begin(), orderedLetters.end(), mostCommonLetter);

		result.push_back(orderedLetters);
	}

	return result;
}

string solveDay6part1(string input)
{
	vector<vector<pair<char, int>>> charsCountByCol = charsCountByColumn(input);
	string result = "";

	for (auto col : charsCountByCol)
		result += col[0].first;

	return result;
}

string solveDay6part2(string input)
{
	vector<vector<pair<char, int>>> charsCountByCol = charsCountByColumn(input);
	string result = "";

	for (auto col : charsCountByCol)
		result += col[col.size()-1].first;

	return result;
}
