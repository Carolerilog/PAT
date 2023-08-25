#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;    

    int n2 = 1;
    while((word.size() - n2) % 2 || (word.size() - n2) / 2 > n2 + 2) {
        n2++;
    }
    int n1 = (word.size() - n2) / 2;

    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", word[i]);

        for(int j = 0; j < n2; j++) {
            printf(" ");
        }

        printf("%c\n", word[word.size() - 1 - i]);
    }

    printf("%c", word[n1 - 1]);
    printf("%s", word.substr(n1, n2).c_str());
    printf("%c\n", word[word.size() - n1]);

    return 0;
}