#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Shlwapi.h>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <iterator>

#pragma comment(lib, "shlwapi.lib")

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::map;
using std::pair;
using std::multimap;
using std::to_string;

string trim(string const& str);
vector<string> split(const string &s, const string delimiter);
void removeFromString(string& s, char removed);
string exePath();
bool directoryExists(const string& dirName);
bool fileExists(const string& fileName);
string rawFileName(const string& fileName);
int deleteDirectory(const string &refcstrRootDirectory,
	bool bDeleteSubdirectories = true);
string implode(vector<string> v, string delim);
bool getNextFile(HANDLE& hFind, WIN32_FIND_DATA* fd);
string createErrorMsg(string msg, int line, char* file);
#define ERROR_MSG(message) createErrorMsg(message, __LINE__, __FILE__).c_str()
string readFileContent(string filepath);


/*
Functions to flip à map and order it by it's values
instead of it's keys.
*/
template<typename A, typename B>
pair<B, A> flip_pair(const pair<A, B> &p)
{
	return pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
multimap<B, A> flip_map(const map<A, B> &src)
{
	multimap<B, A> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
				   flip_pair<A, B>);
	return dst;
}

#endif // UTILITIES_H_INCLUDED
