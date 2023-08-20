#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string a_str, b_str;
    cin >> a_str >> b_str;

    int tag, radix;
    cin >> tag >> radix;

    if(tag == 2) {
        swap(a_str, b_str);
    }

    auto to_vec = [](string& str) -> vector<long long> {
        vector<long long> res;

        reverse(str.begin(), str.end());
        for(auto ch : str) {
            if(ch >= 'a' && ch <= 'z') {
                res.push_back(ch - 'a' + 10);
            } else {
                res.push_back(ch - '0');
            }
        }

        return res;
    };

    auto a = to_vec(a_str);
    auto b = to_vec(b_str);

    long long radix_10_a = 0;
    for(int i = 0; i < a.size(); i++) {
        radix_10_a += a[i] * pow(radix, i);
    }

    long long radix_b_l = 2;
    for(auto n : b) {
        radix_b_l = max(n + 1, radix_b_l);
    }    

    long long radix_b_r = max(radix_b_l, radix_10_a) + 1;

    long long radix_min = 0;
    while(radix_b_l <= radix_b_r) {
        long long radix_b = (radix_b_l + radix_b_r) >> 1;
        long long radix_10_b = 0;

        for(int i = 0; i < b.size(); i++) {
            radix_10_b += b[i] * pow(radix_b, i);

            if(radix_10_b > radix_10_a || radix_10_b < 0) {
                radix_10_b = radix_10_a + 1;
                break;
            }
        }

        if(radix_10_b == radix_10_a) {
            radix_min = radix_b;
            radix_b_r = radix_b - 1;
        } else if (radix_10_b > radix_10_a) {
            radix_b_r = radix_b - 1;   
        } else {
            radix_b_l = radix_b + 1;
        }
    }

    if (radix_min == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << radix_min << endl;
    }

    return 0;
}