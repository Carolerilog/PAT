#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, l;
    scanf("%d%d", &n, &l);

    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        for(int j = 0; j < m; j++) {
            int f;
            scanf("%d", &f);
            f--;
            g[f].push_back(i);
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, 1000));
    vector<int> num_triggered(n, 0);

    for(int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        q.emplace(i, 0);
        dist[i][i] = 0;

        while(!q.empty()) {
            auto [n, d] = q.front();
            q.pop();

            for(int f : g[n]) {
                if(dist[i][f] == 1000) {
                    q.emplace(f, d + 1);
                    dist[i][f] = d + 1;
                }
            }
        }

        for(int j = 0; j < n; j++) {
            if(i != j && dist[i][j] <= l) {
                num_triggered[i]++;
            }
        }
    }

    int k;
    scanf("%d", &k);

    for(int i = 0;i < k; i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", num_triggered[q - 1]);
    }

    return 0;
}