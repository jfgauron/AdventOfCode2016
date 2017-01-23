#include "day11.hpp"
#include <set>
#include <tuple>
#include <list>

using std::tuple;
using std::list;
using std::set;

typedef vector<vector<int>> Floors;
typedef tuple<int, int, int> Move;

#define NELEMENTS 10
Floors parseFloors(string input)
{
	// TO-DO: parse the real input
	Floors defaultFloors =
	{
		{},
		{10, 100},			  // 1st floor
		{200, 300, 400, 500}, // 2nd floor
		{20, 30, 40, 50},	  // 3rd floor
		{},					  // 4th floor
		{},
	};
	/*
	Floors defaultFloors =
	{
		{},
		{10, 20},
		{100},
		{200},
		{},
		{},
	};
	*/
	

	return defaultFloors;
}

struct Path
{
	int floor;
	Floors floors;
	int nthNode;

	Path(int floor, Floors floors, int nthNode)
	{
		this->floor   = floor;
		this->floors  = floors;
		this->nthNode = nthNode;
	}
};

int findObjectFloor(vector<vector<int>> floors, int object)
{
	for (unsigned int i = 1; i < floors.size() - 1; i++)
	{
		for (unsigned int j = 0; j < floors[i].size(); j++)
		{
			if (object == floors[i][j])
				return i;
		}
	}
}

string generateFloorsID(Floors floors, int floor)
{
	string id = "";
	int count = 0;
	vector<tuple<int, int, string, string>> pairs;

	for (unsigned int i = 1; i < floors.size() && count < NELEMENTS / 2; i++)
	{
		for (unsigned int j = 0; j < floors[i].size() && count < NELEMENTS / 2; j++)
		{
			int obj = floors[i][j];
			string leftId = to_string(i) + (obj >= 100 ? "G" : "M");
			int floorB = findObjectFloor(floors, (obj >= 100 ? obj / 10 : obj * 10));
			string rightId = to_string(floorB) + (obj >= 100 ? "M" : "G");

			pairs.push_back({ i, floorB, leftId, rightId});
			count++;
		}
	}

	sort(pairs.begin(), pairs.end());
	for (auto p : pairs)
		id += std::get<2>(p) + "-" + std::get<3>(p) + ".";
	id += to_string(floor);
	return id;
}

bool floorsAreValid(vector<vector<int>> floors)
{
	if (floors[0].size() > 0 || floors[5].size() > 0)
		return false;

	for (auto f : floors)
	{
		bool hasGenerator = false;
		for (auto object : f)
		{
			if (object >= 100)
			{
				hasGenerator = true;
				break;
			}
		}

		if (hasGenerator)
			for (auto object : f)
				if (object < 100)
					if (std::find(f.begin(), f.end(), object * 10) == f.end())
						return false;
	}

	return true;
}

void move(int from, Move action, vector<vector<int>>& floors)
{
	auto iterA = std::find(floors[from].begin(), floors[from].end(), std::get<1>(action));
	floors[from].erase(iterA);
	floors[from + std::get<0>(action)].push_back(std::get<1>(action));

	if (std::get<2>(action) > 0)
	{
		auto iterB = std::find(floors[from].begin(), floors[from].end(), std::get<2>(action));
		floors[from].erase(iterB);
		floors[from + std::get<0>(action)].push_back(std::get<2>(action));
	}
}

vector<Move> generatePossibleMoves(int from, Floors floors)
{
	// 1. get all possible moves
	vector<tuple<int, int, int>> moves;
	for (unsigned int i = 0; i < floors[from].size(); i++)
	{
		int objectA = floors[from][i];

		for (unsigned int j = i + 1; j < floors[from].size(); j++)
		{
			int objectB = floors[from][j];
			moves.push_back(Move(1, objectA, objectB));
			moves.push_back(Move(-1, objectA, objectB));
		}

		moves.push_back(Move(1, objectA, 0));
		moves.push_back(Move(-1, objectA, 0));
	}

	// 2. remove invalid ones
	vector<Move> validMoves;
	for (auto action : moves)
	{
		Floors newFloors = floors;

		move(from, action, newFloors);
		if (floorsAreValid(newFloors))
			validMoves.push_back(action);
	}

	return validMoves;
}

void takePath(Path path, set<string>& seen, list<Path>& paths)
{
	vector<Move> moves = generatePossibleMoves(path.floor, path.floors);
	string id = generateFloorsID(path.floors, path.floor);

	if (path.floors[4].size() == NELEMENTS)
	{
		paths.clear();
		return;
	}

	if (std::find(seen.begin(), seen.end(), id) != seen.end())
		return;
	seen.insert(id);

	for (auto action : moves)
	{
		Floors newFloors = path.floors;
		move(path.floor, action, newFloors);
		paths.push_back(Path(path.floor + std::get<0>(action), newFloors, path.nthNode + 1));
	}
}

int solveDay11(int floor, Floors floors)
{
	list<Path> paths;
	set<string> seen;
	int result = 0;
	
	paths.push_back(Path(floor, floors, 0));
	while (paths.size() != 0)
	{
		Path path = paths.front();
		paths.pop_front();
		result = path.nthNode;
		takePath(path, seen, paths);
	}

	return result;
}

int solveDay11part1(string input)
{
	int nShortestPath = solveDay11(1, parseFloors(input));
	return nShortestPath;
}

int solveDay11part2(string input)
{
	return 0;
}