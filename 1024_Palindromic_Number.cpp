#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string num;
    int k;
    cin >> num >> k;

    for(int i = 0; i <= k; i++) {
        int l = 0, r = num.size() - 1;
        bool flag = true;
        while(l <= r) {
            if(num[l] != num[r]) {
                flag = false;
                break;
            }

            l++;
            r--;
        }

        if(flag) {
            cout << num << endl;
            cout << i << endl;
            return 0;
        }

        if(i == k) {
            break;
        }

        string inv_num = num;
        reverse(inv_num.begin(), inv_num.end());

        int c = 0;
        for(int j = 0; j < num.size(); j++) {
            int n = num[j] - '0' + inv_num[j] - '0' + c;
            num[j] = n % 10 + '0';
            c = n / 10;
        }

        if(c > 0) {
            num.push_back(c + '0');
        }

        reverse(num.begin(), num.end());        
    }

    cout << num << endl;
    cout << k << endl;

    return 0;
}