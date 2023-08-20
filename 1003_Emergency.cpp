// Undirected graph.
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, c1, c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);

    vector<int> num_teams(n);
    for(auto& num : num_teams) {
        scanf("%d", &num);
    }

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int start, end, len;
        scanf("%d%d%d", &start, &end, &len);
        g[start].emplace_back(end, len);
        g[end].emplace_back(start, len);
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, 0x7fffffff);
    vector<int> num_sp(n);
    vector<int> max_gathered(n);

    dist[c1] = 0;
    num_sp[c1] = 1;
    max_gathered[c1] = num_teams[c1];

    for (int i = 0; i < n; ++i) {
        int c;
        int d = 0x7ffffff;

        for(int j = 0; j < n; ++j) {
            if(!visited[j] && dist[j] < d) {
                c = j;
                d = dist[j];
            }
        }

        visited[c] = true;

        for(auto& start : g[c]) {
            auto& [end, len] = start;
            auto sp_dist = d +len;

            if (visited[end]) {
                continue;
            }

            if (sp_dist < dist[end]) {
                dist[end] = sp_dist;
                num_sp[end] = num_sp[c];
                max_gathered[end] = max_gathered[c] + num_teams[end];
            } else if (sp_dist == dist[end]) {
                num_sp[end] += num_sp[c];
                max_gathered[end] = max(max_gathered[end], max_gathered[c] + num_teams[end]);
            }
        }
    }

    printf("%d %d\n", num_sp[c2], max_gathered[c2]);

    return 0;
}