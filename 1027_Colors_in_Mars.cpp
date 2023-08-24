#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int r,g,b;
    scanf("%d%d%d", &r, &g, &b);

    auto to_13 = [](int n) -> string {
        string res;

        while(n > 0) {
            char a = n % 13;
            if(a < 10) {
                a = '0' + a;
            } else {
                a = 'a' + a - 10;
            }

            res.push_back(a);
            n /= 13;
        }

        while(res.size() < 2) {
            res.push_back('0');
        }

        reverse(res.begin(), res.end());
        return res;
    };

    string res = "#" + to_13(r) + to_13(g) + to_13(b) + "\n";
    printf("%s", res.data());

    return 0;
}