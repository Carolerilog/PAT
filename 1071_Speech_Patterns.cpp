#include <iostream>
#include <cstring>
#include <string>
#include <string_view>
#include <unordered_set>

using namespace std;

int main() {
    unordered_map<string, int> map;

    while (true) {
        string word;
        cin >> word;
        char sep = getchar();

        for(char& c : word) {
            c = tolower(c);
        }
        int l = 0;
        int r = 0;

        while(true) {
            while(r < word.size() && !isdigit(word[r]) && !isalpha(word[r])) {
                r++;
            }

            l = r;

            while(r < word.size() && (isdigit(word[r]) || isalpha(word[r]))) {
                r++;
            }

            if(l == word.size()) {
                break;
            }

            string sub_word = word.substr(l, r - l);
            map[sub_word]++;
        }

        if(sep == '\n') {
            break;
        }
    }

    string_view max_word;
    int max_num = 0;

    for(auto& [word, count] : map) {
        if(count > max_num) {
            max_num = count;
            max_word = word;
        }
    }

    cout << max_word << ": " << max_num << endl;
    return 0;
}