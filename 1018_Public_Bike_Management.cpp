#include <cstdio>
#include <cmath>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    int c_max, n, s_p, m, temp;
    scanf("%d%d%d%d", &c_max, &n, &s_p, &m);

    vector<int> bikes{0};
    temp = n;
    while(temp--) {
        int bike;
        scanf("%d", &bike);
        bikes.push_back(bike);
    }

    vector<vector<pair<int, int>>> g(n + 1);
    temp = m;
    while(temp--) {
        int s_i, s_j, t;
        scanf("%d%d%d", &s_i, &s_j, &t);
        g[s_i].emplace_back(s_j, t);
        g[s_j].emplace_back(s_i, t);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> pre(n + 1);
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[0] = 0;

    for(int i = 0; i < n + 1; i++) {
        int c = 0;
        int d = numeric_limits<int>::max();
        for(int j = 0; j < n + 1; j++) {
            if(!visited[j] && dist[j] < d) {
                c = j;
                d = dist[j];
            }
        }

        if(d == numeric_limits<int>::max()) {
            break;
        }

        visited[c] = true;

        for(auto& [next, e] : g[c]) {
            if(!visited[next] && d + e < dist[next]) {
                dist[next] = d + e;
                pre[next].clear();
                pre[next].push_back(c);
            } else if (!visited[next] && d + e == dist[next]) {
                pre[next].push_back(c);
            }
        }
    }

    vector<int> path;
    vector<int> best_path;
    int best_bikes_sent = numeric_limits<int>::max();
    int best_bikes_back = numeric_limits<int>::max();

    function<void(int)> dfs;   
    dfs = [&](int c) {
        path.push_back(c);

        int bikes_sent = 0;
        int bikes_back = 0;
        if(c == 0) {
            for(int i = path.size() - 2; i >= 0; i--) {
                if(c_max / 2 <= bikes[path[i]]) {
                    bikes_back += bikes[path[i]] - c_max / 2;
                } else if(bikes_back >= c_max / 2 - bikes[path[i]]) {
                    bikes_back -= c_max / 2 - bikes[path[i]];
                } else {
                    bikes_sent += c_max / 2 - bikes[path[i]] - bikes_back;
                    bikes_back = 0;
                }
            }

            if(bikes_sent < best_bikes_sent) {
                best_bikes_sent = bikes_sent;
                best_bikes_back = bikes_back;
                best_path = path;
                reverse(best_path.begin(), best_path.end());
            } else if(bikes_sent == best_bikes_sent && bikes_back < best_bikes_back) {
                best_bikes_back = bikes_back;
                best_path = path;
                reverse(best_path.begin(), best_path.end());
            }
        }

        for(auto p : pre[c]) {
            dfs(p);
        }

        path.pop_back();
    };

    dfs(s_p);

    printf("%d ", best_bikes_sent);
    for(int i = 0; i < best_path.size(); i++) {
        if(i == 0) {
            printf("%d", best_path[i]);
        } else {
            printf("->%d", best_path[i]);
        }
    }
    printf(" %d\n", best_bikes_back);

    return 0;
}