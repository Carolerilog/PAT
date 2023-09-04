#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int s;
    string a, b;
    cin >> s >> a >> b;

    auto get_significant_numbers = [&] (string& str, int& k) {
        k = str.find_first_of('.');
        int i = 0;
        while(i < str.size() && (str[i] == '0' || str[i] == '.')) {
            i++;
        }

        str = str.substr(i, str.size() - i);

        string ret;
        for(int i = 0; i < str.size() && ret.size() < s; i++) {
            char ch = str[i];
            if(isdigit(ch)) {
                ret.push_back(ch);
            }
        }

        if(ret.size() < s) {
            ret.resize(s, '0');
        }

        if(k == -1 || str.size() == 0) {
            k = str.size();
        } else if (k > i) {
            k = k - i;
        } else {
            k = k - i + 1;
        }

        return ret;
    };

    int n_a;
    string s_a = get_significant_numbers(a, n_a);
    int n_b;
    string s_b = get_significant_numbers(b, n_b);

    if(s_a == s_b && n_a == n_b) {
        cout << "YES 0." << s_a << "*10^" << n_a << endl;
    } else {
        cout << "NO 0." << s_a << "*10^" << n_a << " 0." << s_b << "*10^" << n_b << endl;
    }

    return 0;
}