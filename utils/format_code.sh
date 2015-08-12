#!/bin/bash

DIR="$( cd "$( dirname "$0" )" && pwd )"

shopt -s globstar

style="Chromium"

types=(
    ".cc"
    ".h"
)

folders=(
    "$DIR/../include"
    "$DIR/../src"
    "$DIR/../editor"
    "$DIR/../examples"
)

ignored=()

isIgnored () {
    local e
    for e in "${ignored[@]}"; do [[ "$e" == "$1" ]] && return 0; done
    return 1
}

for folder in "${folders[@]}"
do
    for type in "${types[@]}"
    do
        for file in ${folder}/**/*${type}
        do
            if [ -f $file ]
            then
                isIgnored "$file"

                if [ $? -ne 0 ]
                then
                    echo "Reformatting $(basename $file) ..."
                    clang-format -style=$style $file > /tmp/clang_tmp
                    cat /tmp/clang_tmp > $file
                else
                    echo "Ignoring $(basename $file) ..."
                fi
            fi
        done
    done
done
