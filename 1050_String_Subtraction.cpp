#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a;
    string b;
    a.reserve(10001);
    b.reserve(10001);
    getline(cin, a);
    getline(cin, b);

    unordered_set<char> diff;
    for(auto ch : b) {
        diff.insert(ch);
    }

    string c;
    c.reserve(10001);
    for(int i = 0; i < a.size(); i++) {
        if(diff.count(a[i]) == 0) {
            c.push_back(a[i]);
        }
    }

    cout << c << endl;
    return 0;
}
