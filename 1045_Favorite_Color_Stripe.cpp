#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int m;
    cin >> m;
    
    vector<int> fav_col(m);
    unordered_map<int, int> fav_col_map;
    for(int i = 0; i < m; i++) {
        cin >> fav_col[i];
        fav_col_map[fav_col[i]] = i;
    }

    int l;
    cin >> l;

    vector<int> stripe;
    for(int i = 0; i < l; i++) {
        int col;
        cin >> col;

        if(fav_col_map.count(col) > 0) {
            stripe.push_back(fav_col_map[col]);
        }
    }

    vector<int> len(stripe.size(), 1);
    for(int i = 1; i < stripe.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(stripe[j] <= stripe[i]) {
                len[i] = max(len[i], len[j] + 1);
            }
        }
    }

    int max_len = 0;
    for(int i = 0; i < len.size(); i++) {
        max_len = max(max_len, len[i]);
    }

    cout << max_len << endl;
    return 0;
}