#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> diamonds(n);
    for(auto& d : diamonds) {
        cin >> d;
    }

    queue<int> pay;
    int min_pay = numeric_limits<int>::max();
    vector<pair<int, int>> subchains;

    int count = 0;
    int front = 0;

    for(int i = 0; i < diamonds.size(); i++) {
        count += diamonds[i];
        pay.push(diamonds[i]);

        while(count - pay.front() >= m) {
            count -= pay.front();
            front++;
            pay.pop();
        }

        if(count >= m) {
            if(count < min_pay) {
                min_pay = count;
                subchains.clear();
                subchains.emplace_back(front + 1, i + 1);
            } else if(count == min_pay) {
                subchains.emplace_back(front + 1, i + 1);
            }
        }
    }

    bool flag = false;
    for(auto [l, r] : subchains) {
        if (!flag) {
            cout << l << '-' << r;
            flag = true;
        } else {
            cout << endl << l << '-' << r;
        }
    }

    return 0;
}