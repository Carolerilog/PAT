#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num = 0, d = 0;
    while(true) {
        cin >> num;

        if(num < 0) {
            break;
        }

        cin >> d;

        vector<int> num_bit;
        int temp = num;

        while(temp > 0) {
            num_bit.push_back(temp % d);
            temp /= d;
        }

        reverse(num_bit.begin(), num_bit.end());
        int rev_num = 0;

        for(int i = 0; i < num_bit.size(); i++) {
            rev_num += num_bit[i] * pow(d, i);
        }

        auto is_prime = [](int num) {
            if (num == 1) {
                return false;
            }

            for(int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }

            return true;
        };

        if(is_prime(num) && is_prime(rev_num)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}