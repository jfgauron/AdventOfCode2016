#include "util.hpp"

string trim(string const& str)
{
	if (str.empty())
		return str;

	std::size_t first = str.find_first_not_of(' ');
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, last - first + 1);
}

vector<string> split(const string &s, const string delimiter)
{
	vector<string> tokens;
	size_t last = 0, next = 0;
	while ((next = s.find(delimiter, last)) != string::npos)
	{
		tokens.push_back(trim(s.substr(last, next - last)));
		last = next + delimiter.size();
	}
	tokens.push_back(trim(s.substr(last, next - last)));

	return tokens;
}

void removeFromString(string& s, char removed)
{
	s.erase(std::remove(s.begin(), s.end(), removed), s.end());
}

string exePath()
{
	char path[MAX_PATH];

	GetModuleFileName(NULL, path, MAX_PATH);
	PathRemoveFileSpec(path);

	return string(path);
}

bool directoryExists(const string& dirName)
{
	DWORD ftyp = GetFileAttributesA(dirName.c_str());

	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

bool fileExists(const string& fileName)
{
	return (bool)(ifstream(fileName));
}

string rawFileName(const string& fileName)
{
	int lastIndex = fileName.find_last_of(".");

	if (lastIndex != string::npos)
		return fileName.substr(0, lastIndex);

	return fileName;
}

int deleteDirectory(const string &refcstrRootDirectory,
	bool bDeleteSubdirectories)
{
	bool			bSubdirectory = false;		// Flag, indicating whether
												// subdirectories have been found

	HANDLE			hFile;				// Handle to directory
	string			strFilePath;		// Filepath
	string			strPattern;			// Pattern
	WIN32_FIND_DATA FileInformation;	// File information

	strPattern = refcstrRootDirectory + "\\*.*";
	hFile = FindFirstFile(strPattern.c_str(), &FileInformation);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (FileInformation.cFileName[0] != '.')
			{
				strFilePath.erase();
				strFilePath = refcstrRootDirectory + "\\" + FileInformation.cFileName;

				if (FileInformation.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (bDeleteSubdirectories)
					{
						// Delete subdirectory
						int iRC = deleteDirectory(strFilePath, bDeleteSubdirectories);
						if (iRC)
							return iRC;
					}
					else
						bSubdirectory = true;
				}
				else
				{
					// Set file attributes
					if (SetFileAttributes(strFilePath.c_str(), FILE_ATTRIBUTE_NORMAL) == FALSE)
						return GetLastError();

					// Delete file
					if (DeleteFile(strFilePath.c_str()) == FALSE)
						return GetLastError();
				}
			}
		} while (FindNextFile(hFile, &FileInformation) == TRUE);

		// Close handle
		FindClose(hFile);

		DWORD dwError = GetLastError();
		if (dwError != ERROR_NO_MORE_FILES)
		{
			return dwError;
		}
		else
		{
			if (!bSubdirectory)
			{
				// Set directory attributes
				if (SetFileAttributes(refcstrRootDirectory.c_str(), FILE_ATTRIBUTE_NORMAL) == FALSE)
					return GetLastError();

				// Delete directory
				if (RemoveDirectory(refcstrRootDirectory.c_str()) == FALSE)
					return GetLastError();
			}
		}
	}

	return 0;
}

string implode(vector<string> v, string delim)
{
	stringstream result;

	for (unsigned int i = 0; i < v.size(); i++)
	{
		result << v[i];

		if (i != v.size() - 1)
			result << delim;
	}

	return result.str();
}

bool getNextFile(HANDLE& hFind, WIN32_FIND_DATA* fd)
{
	if (!FindNextFile(hFind, fd))
		return false;

	if (hFind == INVALID_HANDLE_VALUE)
		return false;

	if (fd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		return getNextFile(hFind, fd);

	return true;
}

string createErrorMsg(string msg, int line, char* file)
{
	return string(file) + " (" + to_string(line) + "): " + msg;
}

string readFileContent(string filepath)
{
	std::ifstream t(filepath);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}
