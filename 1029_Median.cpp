#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> seq[2];
    for(auto& s : seq) {
        int n;
        cin >> n;
        s.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    vector<int> merged_seq(seq[0].size() + seq[1].size());
    int i = 0;
    int j = 0;
    for(int& element : merged_seq) {
        if(i >= seq[0].size()) {
            element = seq[1][j++];
        } else if(j >= seq[1].size()) {
            element = seq[0][i++];
        } else if(seq[0][i] < seq[1][j]) {
            element = seq[0][i++];
        } else {
            element = seq[1][j++];
        }
    }

    cout << merged_seq[floor((merged_seq.size() - 1) / 2.f)] << endl;
}