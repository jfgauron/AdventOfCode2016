#include "day9.hpp"

void applyMarker(string chars, int nRepeat, string& result)
{
	for (int i = 0; i < nRepeat; i++)
		result += chars;
}

unsigned long long decompress(string input, int repetition)
{
	unsigned long long totalSize = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			string marker = input.substr(i + 1, input.find(")") - i - 1);
			string repeatedChars = "";
			int nChars = stoi(split(marker, "x")[0]);
			int nRepeat = stoi(split(marker, "x")[1]);

			i = input.find(")", i) + 1;
			repeatedChars = input.substr(i, nChars);
			totalSize += decompress(repeatedChars, nRepeat);

			i += nChars - 1;
		}
		else
		{
			totalSize++;
		}
	}

	return totalSize * repetition;
}

int solveDay9part1(string input)
{
	string result = "";

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			string marker = input.substr(i+1, input.find(")") - i - 1);
			string repeatedChars = "";
			int nChars = stoi(split(marker, "x")[0]);
			int nRepeat = stoi(split(marker, "x")[1]);

			i = input.find(")", i) + 1;
			repeatedChars = input.substr(i, nChars);
			applyMarker(repeatedChars, nRepeat, result);

			i += nChars - 1;
		}
		else
		{
			result += input[i];
		}
	}

	return result.size();
}

unsigned long long solveDay9part2(string input)
{
	return decompress(input, 1);
}