#include <iostream>
#include <tuple>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    constexpr int max_int = numeric_limits<int>::max();
    using to_city = tuple<int, int, int>;
    vector<vector<to_city>> g(n);
    vector<vector<to_city>> pre(n);
    vector<bool> visited(n, false);
    vector<int> dist(n, max_int);

    while(m--) {
        int s, e, d, c;
        cin >> s >> e >> d >> c;
        g[s].emplace_back(e, d, c);
        g[e].emplace_back(s, d, c);
    }

    dist[s] = 0;
    for(int i = 0; i < n; i++) {
        int c = -1;
        int d = max_int;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < d) {
                c = j;
                d = dist[j];
            }
        }

        if(c == -1) {
            break;
        }

        visited[c] = true;

        for(auto& [next, dis, cost] : g[c]) {
            if(!visited[next] && d + dis < dist[next]) {
                dist[next] = d + dis;
                pre[next].clear();
                pre[next].emplace_back(c, dis, cost);
            } else if(!visited[next] && d + dis == dist[next]) {
                pre[next].emplace_back(c, dis, cost);
            }
        }
    }
    
    vector<int> path;
    vector<int> best_path;
    int min_cost = max_int;

    function<void(int, int)> dfs;
    dfs = [&](int city, int cost) {
        path.push_back(city);

        if(city == s) {
            if(cost < min_cost) {
                min_cost = cost;
                best_path = path;
            }
        }

        for(auto& [next_city, next_dis, next_cost] : pre[city]) {
            dfs(next_city, cost + next_cost);           
        }

        path.pop_back();
    };

    dfs(d, 0);

    for(int i = best_path.size() - 1; i >= 0; i--) {
        cout << best_path[i] << " ";
    }

    cout << dist[d] << " " << min_cost << endl;
    return 0;
}