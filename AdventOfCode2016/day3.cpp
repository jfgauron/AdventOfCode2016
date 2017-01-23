#include "day3.hpp"
#include <algorithm>

vector<vector<int>> parseTriangles(string input)
{
	vector<string> rows = split(input, "\n");
	vector<vector<int>> triangles;

	triangles.resize(3);
	for (unsigned int y = 0; y < rows.size(); y++)
	{
		vector<string> sides = split(trim(rows[y]), "  ");
		int i = 0;
		for (auto side : sides)
		{
			if (trim(side) != "")
			{
				triangles[i].push_back(stoi(trim(side)));
				i = i >= 2 ? 0 : i + 1;
			}
		}
	}

	return triangles;
}

int solveDay3part1(string input)
{
	vector<vector<int>> triangles2D = parseTriangles(input);
	int nValidTriangles = 0;

	for (unsigned int i = 0; i < triangles2D[0].size(); i++)
	{
		vector<int> sides = {triangles2D[0][i], triangles2D[1][i], triangles2D[2][i]};
		std::sort(sides.begin(), sides.end());

		if (sides[0] + sides[1] > sides[2])
			nValidTriangles++;
	}

	return nValidTriangles;
}

/*
int solveDay3part1(string input)
{
	vector<string> rows = split(input, "\n");
	int nValidTriangles = 0;

	for (auto row : rows)
	{
		vector<string> sides = split(trim(row), "  ");
		vector<int> sortedSides;

		for (auto side : sides)
			if (trim(side) != "")
				sortedSides.push_back(stoi(trim(side)));
		std::sort(sortedSides.begin(), sortedSides.end());

		if (sortedSides[0] + sortedSides[1] > sortedSides[2])
			nValidTriangles++;
	}

	return nValidTriangles;
}
*/

int solveDay3part2(string input)
{
	vector<vector<int>> triangles2D = parseTriangles(input);
	vector<int> triangles;
	int nValidTriangles = 0;

	triangles.insert(triangles.end(), triangles2D[0].begin(), triangles2D[0].end());
	triangles.insert(triangles.end(), triangles2D[1].begin(), triangles2D[1].end());
	triangles.insert(triangles.end(), triangles2D[2].begin(), triangles2D[2].end());

	for (unsigned int i = 0; i < triangles.size(); i += 3)
	{
		vector<int> sides = {triangles[i], triangles[i+1], triangles[i+2]};
		std::sort(sides.begin(), sides.end());

		if (sides[0] + sides[1] > sides[2])
			nValidTriangles++;
	}

	return nValidTriangles;
}