#!/bin/sh

# get directory of script and cd to its parent
DIR="$( cd "$( dirname "$0" )" && pwd )"
cd $DIR/..

# no build directory, create it
if [[ ! -d "build" ]]; then
    mkdir build
fi

cd build

# build directory is empty, run cmake
if [[ "$(ls -A . 2> /dev/null)" == "" ]]; then
  cmake ..
fi

# build it
make -j4
