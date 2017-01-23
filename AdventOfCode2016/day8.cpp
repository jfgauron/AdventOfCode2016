#include "day8.hpp"

#define MAX_WIDTH 50
#define MAX_HEIGHT 6

vector<vector<char>> screen =
{
	vector<char>(50),
	vector<char>(50),
	vector<char>(50),
	vector<char>(50),
	vector<char>(50),
	vector<char>(50)
};

void resetScreen()
{
	for (int i = 0; i < MAX_WIDTH; i++)
		for (int j = 0; j < MAX_HEIGHT; j++)
			screen[j][i] = 'X';
}

void rect(int x, int y)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			screen[j][i] = 'O';
}

void rotateRow(int y, int qty)
{
	string newValues = "";

	// Select the last qty values
	for (int i = MAX_WIDTH - qty%MAX_WIDTH; i < MAX_WIDTH; i++)
		newValues += screen[y][i];

	// merge newValues with old vaolues
	for (int i = 0; i < MAX_WIDTH-qty%MAX_WIDTH; i++)
		newValues += screen[y][i];

	// update new values
	for (int i = 0; i < MAX_WIDTH; i++)
		screen[y][i] = newValues[i];
}

void rotateCol(int x, int qty)
{
	string newValues = "";

	// Select the last qty values
	for (int i = MAX_HEIGHT - qty%MAX_HEIGHT; i < MAX_HEIGHT; i++)
		newValues += screen[i][x];

	// merge newValues with old vaolues
	for (int i = 0; i < MAX_HEIGHT - qty%MAX_HEIGHT; i++)
		newValues += screen[i][x];

	// update new values
	for (int i = 0; i < MAX_HEIGHT; i++)
		screen[i][x] = newValues[i];
}

int countPixels()
{
	int nPixels = 0;
	for (int i = 0; i < MAX_HEIGHT; i++)
		for (int j = 0; j < MAX_WIDTH; j++)
			if (screen[i][j] == 'O')
				nPixels++;
	return nPixels;
}

void printScreen()
{
	int nPixels = 0;

	std::cout << std::endl;
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			if (screen[i][j] == 'O')
				std::cout << "#";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int solveDay8part1(string input)
{
	vector<string> instructions = split(input, "\n");
	resetScreen();

	for (auto instruction : instructions)
	{
		vector<string> parts = split(instruction, " ");
		if (parts[0] == "rect")
			rect(stoi(split(parts[1], "x")[0]), stoi(split(parts[1], "x")[1]));
		else if (parts[0] == "rotate" && parts[1] == "row")
			rotateRow(stoi(parts[2].substr(2)), stoi(parts[4]));
		else
			rotateCol(stoi(parts[2].substr(2)), stoi(parts[4]));
	}

	return countPixels();
}

string solveDay8part2(string input)
{
	vector<string> instructions = split(input, "\n");
	resetScreen();

	for (auto instruction : instructions)
	{
		vector<string> parts = split(instruction, " ");
		if (parts[0] == "rect")
			rect(stoi(split(parts[1], "x")[0]), stoi(split(parts[1], "x")[1]));
		else if (parts[0] == "rotate" && parts[1] == "row")
			rotateRow(stoi(parts[2].substr(2)), stoi(parts[4]));
		else
			rotateCol(stoi(parts[2].substr(2)), stoi(parts[4]));
	}

	printScreen();
	return "";
}