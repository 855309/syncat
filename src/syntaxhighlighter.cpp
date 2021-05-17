#include <bits/stdc++.h>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/replace.hpp>
using namespace std;
using namespace boost::filesystem;
using namespace boost;

#include "include/file.hpp"
#include "include/strh.hpp"
#include "include/colorizer.hpp"

string highlightText(string text, string lang){
    if(is_regular_file("hl/" + lang + ".def")){
        string outstr = "";
        outstr = text;
        for(string def : ReadAllLines("hl/" + lang + ".def")){
            if(trim(def) != ""){
                vector<string> coldef = splitstrcount(def, ' ', 1);
                for(string keyword : splitstr(coldef[1], ' ')){
                    string nw = colorize(keyword, coldef[0], true);
                    replace_all(outstr, keyword, nw);
                }
            }
        }
        return outstr;
    }
    else{
        return text;
    }
}