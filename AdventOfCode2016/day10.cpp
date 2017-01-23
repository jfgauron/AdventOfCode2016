#include "day10.hpp"

struct Robot;

vector<Robot> robots;
vector<vector<int>> outputs;
int answer = -1;

struct Robot
{
	int chip1;
	int chip2;
	int id;
	string instruction;

	Robot()
	{
		chip1 = -1;
		chip2 = -1;
	}

	void setId(int id)
	{
		this->id = id;
	}

	void executeInstruction()
	{
		if (chip2 != -1)
		{
			vector<string> parts = split(instruction, ":");
			int low = chip1 < chip2 ? chip1 : chip2;
			int high = chip1 > chip2 ? chip1 : chip2;
			int lowId = stoi(parts[1]);
			int highId = stoi(parts[3]);

			chip1 = -1;
			chip2 = -1;

			// low
			if (parts[0] == "output")
			{
				if (outputs.size() < lowId + 1)
					outputs.resize(lowId + 1);
				outputs[lowId].push_back(low);
			}
			else
				robots[lowId].giveChip(low);

			// low
			if (parts[2] == "output")
			{
				if (outputs.size() < highId + 1)
					outputs.resize(highId + 1);
				outputs[highId].push_back(high);
			}
			else
				robots[highId].giveChip(high);
		}
	}

	void setInstruction(string command)
	{
		instruction = command;
	}

	void setChip(int value)
	{
		if (chip1 == -1)
			chip1 = value;
		else
			chip2 = value;

		if ((chip1 == 61 && chip2 == 17) ||
			(chip2 == 61 && chip1 == 17) &&
			answer == -1)
			answer = id;
	}

	void giveChip(int value)
	{
		setChip(value);
		if (chip2 != -1)
			executeInstruction();
	}
};

void initializeRobots(vector<string> instructions)
{
	for (auto instruction : instructions)
	{
		vector<string> parts = split(instruction, " ");

		if (parts[0] == "value")
		{
			int value = stoi(parts[1]);
			int robotId = stoi(parts[5]);

			if (robots.size() < robotId + 1)
				robots.resize(robotId + 1);

			robots[robotId].setChip(value);
		}
		else if (parts[0] == "bot")
		{
			int robotId = stoi(parts[1]);

			if (robots.size() < robotId + 1)
				robots.resize(robotId + 1);

			string instruction = parts[5] + ":" + parts[6] + ":" + parts[10] + ":" + parts[11];
			robots[robotId].setInstruction(instruction);
		}
	}

	for (unsigned int i = 0; i < robots.size(); i++)
	{
		robots[i].setId(i);
	}
}

int solveDay10part1(string input)
{
	vector<string> instructions = split(input, "\n");
	initializeRobots(instructions);

	for (auto robot : robots)
		robot.executeInstruction();

	return answer;
}

int solveDay10part2(string input)
{
	/*
	vector<string> instructions = split(input, "\n");
	initializeRobots(instructions);

	for (auto robot : robots)
		robot.executeInstruction();
	*/

	return outputs[0][0] * outputs[1][0] * outputs[2][0];
}