#include "day1.hpp"
#include <algorithm>

#define NORTH	0
#define EAST	1
#define WEST	2
#define SOUTH	3

struct MovementVector
{
	MovementVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	MovementVector(char direction)
	{
		if (direction == 'R') {
			this->x = 1;
			this->y = -1;
		} else {
			this->x = -1;
			this->y = 1;
		}
	}

	MovementVector operator*(MovementVector a)
	{
		return MovementVector(this->x * a.x, this->y * a.y);
	}

	MovementVector reverse()
	{
		return MovementVector(y, x);
	}

	int x;
	int y;
};

int solveDay1part1(string direction)
{
	vector<string> moves = split(direction, ", ");
	MovementVector facing = MovementVector(1, 0);
	vector<string> coords;
	int x = 0;
	int y = 0;

	coords.push_back("0,0");
	for (unsigned int i = 0; i < moves.size(); i++) {
		int length = stoi(moves[i].substr(1));
		MovementVector move = MovementVector(length, length);
		MovementVector direction = MovementVector(moves[i][0]);
		MovementVector result = move * direction * facing;
		facing = (facing * direction).reverse();

		x += result.x;
		y += result.y;
	}

	return abs(x) + abs(y); // distance
}

int solveDay1part2(string direction)
{
	vector<string> moves = split(direction, ", ");
	MovementVector facing = MovementVector(1, 0);
	vector<string> coords;
	int x = 0;
	int y = 0;

	coords.push_back("0,0");
	for (unsigned int i = 0; i < moves.size(); i++) {
		int length = stoi(moves[i].substr(1));
		MovementVector move = MovementVector(length, length);
		MovementVector direction = MovementVector(moves[i][0]);
		MovementVector result = move * direction * facing;
		facing = (facing * direction).reverse();

		for (int i = 0; i < abs(result.x); i++) {
			if (result.x < 0)
				x -= 1;
			else
				x += 1;

			string id = to_string(x) + "," + to_string(y);
			if (std::find(coords.begin(), coords.end(), id) != coords.end())
			{
				return abs(x) + abs(y); // distance of first location visited twice
			}
			coords.push_back(id);
		}

		for (int i = 0; i < abs(result.y); i++) {
			if (result.y < 0)
				y -= 1;
			else
				y += 1;

			string id = to_string(x) + "," + to_string(y);
			if (std::find(coords.begin(), coords.end(), id) != coords.end())
			{
				return abs(x) + abs(y); // distance of virst location visited twice
			}
			coords.push_back(id);
		}
	}

	return -1;
}