#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int max_len = 1;
    for(int i = 0; i < str.size(); i++) {
        auto search = [&str, &max_len] (int l, int r) {
            while(l >=0 && r < str.size() && str[l] == str[r]) {
                l--;
                r++;
            }

            l++;
            r--;
            max_len = max(max_len, r - l + 1);
        };

        search(i, i);
        search(i - 1, i);
    }

    cout << max_len << endl;
    return 0;
}