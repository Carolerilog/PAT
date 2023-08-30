#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);
    for(auto& num : nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end(), [](string const& a, string const& b) {
        auto c = a + b;
        auto d = b + a;
        return c < d;
    });

    string cat_num;
    for(auto& num : nums) {
        cat_num += num;
    }

    int first = cat_num.find_first_not_of('0');
    if(first != -1) {
        cout << cat_num.substr(first, cat_num.size() - first) << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}