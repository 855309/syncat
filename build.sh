#!/usr/bin/bash

[ -f "build/syncat" ] && rm -rf "build/syncat"

declare -a filearr=()

function join_by { local d=${1-} f=${2-}; if shift 2; then printf %s "$f" "${@/#/$d}"; fi; }

searchext="cpp"
function searchforcpp() {
    for entry in "$1"/*
    do
        if [ -d "$entry" ] 
        then
            searchforcpp "$entry"
        else
            if [[ "$entry" == *."$searchext" ]]
            then
                #echo "$entry"
                filearr+=("$entry")
            fi
        fi
    done
}

searchforcpp "src"

res=$(join_by " " ${filearr[@]})

g++ $res -o build/syncat -lboost_filesystem

echo -e "\e[1m::\e[0m \e[32;1mBuild complete.\e[0m"
printf "\n"