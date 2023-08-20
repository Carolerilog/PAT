// N is non negative.
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char num[102] = "";
    scanf("%s", (char*) &num);
    
    int sum = 0;
    for(auto ch : num) {
        if(ch == 0) {
            break;
        }

        sum += ch - '0';
    }

    char* spell[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    vector<char*> spell_num;
    int n = sum;
    while(sum > 0) {
        spell_num.push_back(spell[sum % 10]);
        sum /= 10;
    }

    reverse(spell_num.begin(), spell_num.end());

    bool flag = false;
    for(auto str : spell_num) {
        if (!flag) {
            printf("%s", str);
            flag = true;
        } else {
            printf(" %s", str);
        }
    }

    if (n == 0) {
        printf("zero");
    }

    printf("\n");
    return 0;
}