#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lot(n);
    unordered_multiset<int> count;
    for(auto& l : lot) {
        cin >> l;
        count.insert(l);
    }

    for(auto& l : lot) {
        if(count.count(l) == 1) {
            cout << l << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}