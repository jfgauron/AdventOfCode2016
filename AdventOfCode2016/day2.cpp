#include "day2.hpp"

vector<vector<char>> numpad1 =
{
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
};

vector<vector<char>> numpad2 =
{
	{'X', 'X', '1', 'X', 'X'},
	{'X', '2', '3', '4', 'X'},
	{'5', '6', '7', '8', '9'},
	{'X', 'A', 'B', 'C', 'X'},
	{'X', 'X', 'D', 'X', 'X'},
};

char solveRow(vector<vector<char>> numpad, string row, int& x, int& y)
{
	int xMax = numpad[0].size()-1;
	int yMax = numpad.size()-1;

	for (auto move : row)
	{
		switch (move)
		{
		case 'U': y = y > 0 && numpad[y-1][x] != 'X' ? y - 1 : y; break;
		case 'R': x = x < xMax && numpad[y][x+1] != 'X' ? x + 1 : x; break;
		case 'D': y = y < yMax && numpad[y+1][x] != 'X' ? y + 1 : y; break;
		case 'L': x = x > 0 && numpad[y][x-1] != 'X' ? x - 1 : x; break;
		}
	}

	return numpad[y][x];
}

string solveDay2part1(string code)
{
	vector<string> rows = split(code, "\n");
	string result;
	int x = 1;
	int y = 1;

	for (auto row : rows)
	{
		result += solveRow(numpad1, row, x, y);
	}

	return result;
}

string solveDay2part2(string code)
{
	vector<string> rows = split(code, "\n");
	string result;
	int x = 1;
	int y = 1;

	for (auto row : rows)
	{
		result += solveRow(numpad2, row, x, y);
	}

	return result;
}