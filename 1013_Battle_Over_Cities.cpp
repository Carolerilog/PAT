// Compute the number of trees
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<int, vector<int>> um;
    while(m--) {
        int s, e;
        cin >> s >> e;
        um[s].push_back(e);
        um[e].push_back(s);
    }

    while(k--) {
        int check;
        cin >> check;

        unordered_set<int> visited;
        visited.insert(check);

        function<void(int)> dfs;
        dfs = [&](int city) {
            visited.insert(city);

            if (um.count(city) == 0) {
                return;
            }

            for(auto& next : um[city]) {
                if(visited.count(next) == 0) {
                    dfs(next);
                }
            }
        };

        int tree_count = 0;
        for(int i = 1; i <= n; i++ ) {
            if(visited.count(i) == 0) {
                tree_count += 1;
                dfs(i);
            }
        }

        cout << tree_count - 1 << endl;
    }

    return 0;
}