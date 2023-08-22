#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string num;
    cin >> num;
    reverse(num.begin(), num.end());
    
    string inv_num;
    int c = 0;
    for(auto n : num) {
        int d = n - '0';
        d = d * 2 + c;
        inv_num.push_back(d % 10 + '0');
        c = d / 10;
    }

    if(c > 0) {
        inv_num.push_back(c + '0');
    }

    vector<int> freq(10, 0);
    for(auto ch : num) {
        freq[ch - '0']++;
    }

    for(auto ch : inv_num) {
        freq[ch - '0']--;
    }

    bool flag = true;
    for(auto f : freq) {
        if(f != 0) {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    reverse(inv_num.begin(), inv_num.end());
    cout << inv_num << endl;

    return 0;
}