// Use dp: the max seq end in i is derived from i - 1.
// There will not be a shorter max seq in i - 1
// as in that case the front seq will be negative
// and this part should not be included in the current max seq.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for(auto& n : num) {
        cin >> n;
    }

    int l = 0, r = 0, sum = 0;
    int max_l = 0, max_r = 0, max_sum = 0x80000000;
    while(r < n) {
        sum += num[r];

        if(sum > max_sum) {
            max_l = l;
            max_r = r;
            max_sum = sum;
        }

        if(sum < 0) {
            l = r + 1;
            sum = 0;
        }

        r++;
    }

    if(max_sum < 0) {
        max_sum = 0;
        max_l = 0;
        max_r = n - 1;
    }

    cout << max_sum << " " << num[max_l] << " " << num[max_r] << endl;
}