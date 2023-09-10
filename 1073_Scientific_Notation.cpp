#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string sci_not;
    cin >> sci_not;

    int point_idx = sci_not.find_first_of('.');
    int E_idx = sci_not.find_first_of('E');
    int exp = stoi(sci_not.substr(E_idx + 1));

    string sign = sci_not.substr(0, 1);
    string num_d = sci_not.substr(1, point_idx - 1);
    string num_f = sci_not.substr(point_idx + 1, E_idx - point_idx - 1);
    string num = num_d + num_f;

    if(exp < 0) {
        for(int i = 0; i < -exp; i++) {
            num = "0" + num;
        }

        num.insert(num.begin() + 1, '.');
    } else if(exp < num.size() - 1){
        num.insert(num.begin() + exp + 1, '.');
    } else {
        for(int i = num.size() - 1; i < exp; i++) {
            num = num + "0";
        }
    }

    if(sign == "-") {
        num = sign + num;
    }

    cout << num << endl;
    return 0;
}