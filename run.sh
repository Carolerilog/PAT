if [ ! -d "build" ]; then
    mkdir build
fi

src=$1
exe=build/${src%.cpp}

clang++ -Wall -std=c++17 -pipe -g $src -lm -o $exe
$exe
