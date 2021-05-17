#include <bits/stdc++.h>
using namespace std;

#include "include/file.hpp"

vector<string> ReadAllLines(string path)
{
    fstream fileStream;
    fileStream.open(path, ios::in);

    vector<string> lines;

    if (fileStream.is_open())
    {
        string lc;

        while (getline(fileStream, lc))
        {
            lines.push_back(lc);
        }

        fileStream.close();
    }

    return lines;
}