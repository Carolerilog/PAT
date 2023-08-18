if [ ! -d "build" ]; then
    mkdir build
fi

input="$1"
output=${input%.cpp}
clang -lstdc++ -o "build/$output" "$input"
./build/"$output"
