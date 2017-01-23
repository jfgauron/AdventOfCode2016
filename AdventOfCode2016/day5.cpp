#include "day5.hpp"
#include "MD5.hpp"

#define PASSWORD_SIZE 8

string solveDay5part1(string input)
{
	MD5 md5;
	int index = 0;
	string indexStr;
	string hash;
	string password = "";

	while (password.size() != PASSWORD_SIZE)
	{
		indexStr = to_string(index);
		hash = md5.getMD5((input + indexStr).c_str(),
						  input.size() + indexStr.size());

		if (hash.substr(0, 5) == "00000")
			password += hash[5];
		index++;
	}

	return password;
}

string solveDay5part2(string input)
{
	MD5 md5;
	int index = 0;
	int pos = 0;
	string indexStr;
	string hash;
	string password = "--------";

	std::cout << "Decrypting: " << password << std::endl;
	while (password.find("-") != string::npos)
	{
		indexStr = to_string(index);
		hash = md5.getMD5((input + indexStr).c_str(),
			input.size() + indexStr.size());

		if (hash.substr(0, 5) == "00000")
		{
			pos = hash[5] - '0';
			if (pos >= 0 && pos < 8 && password[pos] == '-')
			{
				password[pos] = hash[6];
				std::cout << input << indexStr << " => " << hash << ": "
						  << "\t" << password << std::endl;
			}
		}
		index++;
	}

	return password;
}