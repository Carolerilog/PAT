#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);

    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int node, num;
        scanf("%d%d", &node, &num);

        g[node].resize(num);
        for(int j = 0; j < num; j++) {
            scanf("%d", &g[node][j]);
        }
    }

    vector<vector<int>> paths;
    vector<int> path;
    int count  = 0;

    function<void(int)> dfs;
    dfs = [&](int i) {
        count += w[i];
        path.push_back(w[i]);

        if(g[i].size() == 0 && count == s) {
            paths.push_back(path);
        }

        for(int j = 0; j < g[i].size(); j++) {
            dfs(g[i][j]);
        }

        path.pop_back();
        count -= w[i];
    };
    dfs(0);

    sort(paths.begin(), paths.end(), [](vector<int> const& a, vector<int> const& b) {
        for(int i = 0; i < min(a.size(), b.size()); i++) {
            if(a[i] == b[i]) {
                continue;
            }

            return a[i] > b[i];
        }

        return false;
    });
    
    for(auto& path : paths) {
        for(int i = 0; i < path.size(); i++) {
            if(i == 0) {
                printf("%d", path[i]);
            } else {
                printf(" %d", path[i]);
            }
        }

        printf("\n");
    }

    return 0;
}