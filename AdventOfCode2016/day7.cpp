#include "day7.hpp"
#include <set>

using std::set;

bool containsABBA(string input)
{
	for (unsigned int i = 0; i <= input.size() - 4; i++)
	{
		if (input[i] == input[i+3] &&
			input[i+1] == input[i+2] &&
			input[i] != input[i+1])
			return true;
	}
	return false;
}

set<string> findABAs(string input)
{
	set<string> ABAs;

	for (unsigned int i = 0; i <= input.size() - 3; i++)
	{
		if (input[i] == input[i + 2] && input[i] != input[i + 1])
			ABAs.insert(string("") + input[i] + input[i+1] + input[i+2]);
	}

	return ABAs;
}

bool hasBAB(string input, string ABA)
{
	string BAB = string("") + ABA[1] + ABA[0] + ABA[1];
	return input.find(BAB) != string::npos;
}

void splitIP(string ip, set<string>& supernets, set<string>& hypernets)
{
	while (ip.find("[") != string::npos)
	{
		supernets.insert(ip.substr(0, ip.find_first_of("[")));
		ip = ip.substr(ip.find_first_of("[")+1);

		hypernets.insert(ip.substr(0, ip.find_first_of("]")));
		ip = ip.substr(ip.find_first_of("]")+1);
	}

	if (ip != "")
		supernets.insert(ip);
}

int solveDay7part1(string input)
{
	int nValidIPs = 0;
	vector<string> ips = split(input, "\n");

	for (auto ip : ips)
	{
		set<string> supernets;
		set<string> hypernets;
		bool supernetsHaveABBA = false;
		bool hypernetsHaveABBA = false;

		splitIP(ip, supernets, hypernets);

		for (auto supernet : supernets)
			if (containsABBA(supernet))
				supernetsHaveABBA = true;

		for (auto hypernet : hypernets)
			if (containsABBA(hypernet))
				hypernetsHaveABBA = true;

		if (supernetsHaveABBA && !hypernetsHaveABBA)
			nValidIPs++;
	}
	return nValidIPs;
}

int solveDay7part2(string input)
{
	int nValidIPs = 0;
	vector<string> ips = split(input, "\n");

	for (auto ip : ips)
	{
		set<string> supernets;
		set<string> hypernets;
		set<string> ABAs;
		bool isValid = false;

		splitIP(ip, supernets, hypernets);

		for (auto supernet : supernets)
		{
			set<string> supernetABAs = findABAs(supernet);
			ABAs.insert(supernetABAs.begin(), supernetABAs.end());
		}

		for (auto ABA : ABAs)
			for (auto hypernet : hypernets)
				if (hasBAB(hypernet, ABA))
					isValid = true;

		if (ABAs.size() > 0 && isValid)
			nValidIPs++;
	}

	return nValidIPs;
}