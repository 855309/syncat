#include <bits/stdc++.h>
using namespace std;

#include "include/file.hpp"
#include "include/syntaxhighlighter.hpp"
#include "include/colorizer.hpp"
#include "include/strh.hpp"

void colorPrint(string file){
    vector<string> lines = ReadAllLines(file);
    vector<string> lext = splitstr(file, '.');
    string ext = trim(lext[lext.size() - 1]);
    int s = to_string(lines.size()).size();
    for(int i = 1; i <= lines.size(); i++){
        string currentLine = lines[i - 1];
        int spacesize = s - to_string(i).size();
        string linestr = "";
        for(int i = 0; i < spacesize; i++){
            linestr += " ";
        }
        linestr += colorize(to_string(i) + "| ", "", true) + highlightText(currentLine, ext);
        cout << linestr << endl;
    }
}

int main(int argc, char** argv){
    if(argc == 1){
        cout << "syncat <file>" << endl;
        return 1;
    }

    string file = argv[1];
    colorPrint(file);

    return 0;
}