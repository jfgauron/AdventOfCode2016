#include <iostream>

#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "day5.hpp"
#include "day6.hpp"
#include "day7.hpp"
#include "day8.hpp"
#include "day9.hpp"
#include "day10.hpp"
#include "day11.hpp"

int main(int argc, char* argv[])
{
	//std::cout << solveDay1part1(readFileContent("day1.txt")) << std::endl;
	//std::cout << solveDay1part2(readFileContent("day1.txt")) << std::endl;
	//std::cout << solveDay2part1(readFileContent("day2.txt")) << std::endl;
	//std::cout << solveDay2part2(readFileContent("day2.txt")) << std::endl;
	//std::cout << solveDay3part1(readFileContent("day3.txt")) << std::endl;
	//std::cout << solveDay3part2(readFileContent("day3.txt")) << std::endl;
	//std::cout << solveDay4part1(readFileContent("day4.txt")) << std::endl;
	//std::cout << solveDay4part2(readFileContent("day4.txt")) << std::endl;
	//std::cout << solveDay5part1(readFileContent("day5.txt")) << std::endl;
	//std::cout << solveDay5part2(readFileContent("day5.txt")) << std::endl;
	//std::cout << solveDay6part1(readFileContent("day6.txt")) << std::endl;
	//std::cout << solveDay6part2(readFileContent("day6.txt")) << std::endl;
	//std::cout << solveDay7part1(readFileContent("day7.txt")) << std::endl;
	//std::cout << solveDay7part2(readFileContent("day7.txt")) << std::endl;
	//std::cout << solveDay8part1(readFileContent("day8.txt")) << std::endl;
	//std::cout << solveDay8part2(readFileContent("day8.txt")) << std::endl;
	//std::cout << solveDay9part1(readFileContent("day9.txt")) << std::endl;
	//std::cout << solveDay9part2(readFileContent("day9.txt")) << std::endl;
	//std::cout << solveDay10part1(readFileContent("day10.txt")) << std::endl;
	//std::cout << solveDay10part2(readFileContent("day10.txt")) << std::endl;
	std::cout << solveDay11part1(readFileContent("day11.txt")) << std::endl;
	std::cout << solveDay11part2(readFileContent("day11.txt")) << std::endl;
	
	system("pause");

	if (argc == 0)
		return 1;

	if (argv[0] == "1") // day 1-1
		std::cout << solveDay1part1("R1, L3, R5, R5, R5, L4, R5, R1, R2, L1, L1, R5, R1, L3, L5, L2, R4, L1, R4, R5, L3, R5, L1, R3, L5, R1, L2, R1, L5, L1, R1, R4, R1, L1, L3, R3, R5, L3, R4, L4, R5, L5, L1, L2, R4, R3, R3, L185, R3, R4, L5, L4, R48, R1, R2, L1, R1, L4, L4, R77, R5, L2, R192, R2, R5, L4, L5, L3, R2, L4, R1, L5, R5, R4, R1, R2, L3, R4, R4, L2, L4, L3, R5, R4, L2, L1, L3, R1, R5, R5, R2, L5, L2, L3, L4, R2, R1, L4, L1, R1, R5, R3, R3, R4, L1, L4, R1, L2, R3, L3, L2, L1, L2, L2, L1, L2, R3, R1, L4, R1, L1, L4, R1, L2, L5, R3, L5, L2, L2, L3, R1, L4, R1, R1, R2, L1, L4, L4, R2, R2, R2, R2, R5, R1, L1, L4, L5, R2, R4, L3, L5, R2, R3, L4, L1, R2, R3, R5, L2, L3, R3, R1, R3") << std::endl;
	else if (argv[0] == "2") // day1-2
		std::cout << solveDay1part2("R1, L3, R5, R5, R5, L4, R5, R1, R2, L1, L1, R5, R1, L3, L5, L2, R4, L1, R4, R5, L3, R5, L1, R3, L5, R1, L2, R1, L5, L1, R1, R4, R1, L1, L3, R3, R5, L3, R4, L4, R5, L5, L1, L2, R4, R3, R3, L185, R3, R4, L5, L4, R48, R1, R2, L1, R1, L4, L4, R77, R5, L2, R192, R2, R5, L4, L5, L3, R2, L4, R1, L5, R5, R4, R1, R2, L3, R4, R4, L2, L4, L3, R5, R4, L2, L1, L3, R1, R5, R5, R2, L5, L2, L3, L4, R2, R1, L4, L1, R1, R5, R3, R3, R4, L1, L4, R1, L2, R3, L3, L2, L1, L2, L2, L1, L2, R3, R1, L4, R1, L1, L4, R1, L2, L5, R3, L5, L2, L2, L3, R1, L4, R1, R1, R2, L1, L4, L4, R2, R2, R2, R2, R5, R1, L1, L4, L5, R2, R4, L3, L5, R2, R3, L4, L1, R2, R3, R5, L2, L3, R3, R1, R3") << std::endl;
	else if (argv[0] == "3") // day2-1
		std::cout << solveDay2part1("R1, L3, R5, R5, R5, L4, R5, R1, R2, L1, L1, R5, R1, L3, L5, L2, R4, L1, R4, R5, L3, R5, L1, R3, L5, R1, L2, R1, L5, L1, R1, R4, R1, L1, L3, R3, R5, L3, R4, L4, R5, L5, L1, L2, R4, R3, R3, L185, R3, R4, L5, L4, R48, R1, R2, L1, R1, L4, L4, R77, R5, L2, R192, R2, R5, L4, L5, L3, R2, L4, R1, L5, R5, R4, R1, R2, L3, R4, R4, L2, L4, L3, R5, R4, L2, L1, L3, R1, R5, R5, R2, L5, L2, L3, L4, R2, R1, L4, L1, R1, R5, R3, R3, R4, L1, L4, R1, L2, R3, L3, L2, L1, L2, L2, L1, L2, R3, R1, L4, R1, L1, L4, R1, L2, L5, R3, L5, L2, L2, L3, R1, L4, R1, R1, R2, L1, L4, L4, R2, R2, R2, R2, R5, R1, L1, L4, L5, R2, R4, L3, L5, R2, R3, L4, L1, R2, R3, R5, L2, L3, R3, R1, R3") << std::endl;

	return 1;
}