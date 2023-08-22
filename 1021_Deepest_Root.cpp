#include <cstdio>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> g(n + 1);

    for(int i = 1; i <= n - 1; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }

    vector<bool> visited(n, false);
    int count = 0;

    function<void(int)> dfs;
    dfs = [&](int node) {
        visited[node] = true;

        for(auto next : g[node]) {
            if(!visited[next]) {
                dfs(next);
            }
        }
    };

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            count++;
            dfs(i);
        }
    }

    if(count > 1) {
        printf("Error: %d components\n", count);
    } else {
        vector<int> deepest_roots;
        int deepest_depth = 0;

        for(int i = 1; i <= n; i++) {
            vector<bool> visited(n, false);
            int max_depth = 0;
            queue<pair<int, int>> q;
            q.push({i, 1});

            while(!q.empty()) {
                auto [node, depth] = q.front();
                q.pop();
                visited[node] = true;

                if(depth > max_depth) {
                    max_depth = depth;
                }

                for(auto next : g[node]) {
                    if(!visited[next]) {
                        q.push({next, depth + 1});
                    }
                }
            }

            if(max_depth > deepest_depth) {
                deepest_roots.clear();
                deepest_roots.push_back(i);
                deepest_depth = max_depth;
            } else if(max_depth == deepest_depth) {
                deepest_roots.push_back(i);
            }
        }

        for(auto root : deepest_roots) {
            printf("%d\n", root);
        }
    }

    return 0;
}