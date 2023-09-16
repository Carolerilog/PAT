#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct pat {
    int next;
    int s;
    int d;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<pat>> graph(n + 1);
    vector<int> degree(n, 0);

    for(int i = 0; i < m; i++) {
        int t1, t2, s, d;
        scanf("%d%d%d%d", &t1, &t2, &s, &d);

        graph[t1].push_back({t2, s, d});
        degree[t2]++;
    }

    unordered_set<int> direct;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) {
            graph[n].push_back({i, 0, 0});
            direct.emplace(i);
        }
    }

    bool consistent = true;
    queue<int> q;

    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        count++;
        
        for(auto& p : graph[f]) {
            degree[p.next]--;
            if(degree[p.next] == 0) {
                q.push(p.next);
            }
        }
    }
    consistent = (count == n);

    constexpr int max_s = 0x3fffffff;
    vector<bool> visited(n + 1, false);
    vector<int> pre(n + 1, -1);
    vector<int> min_s(n + 1, max_s);
    vector<int> max_d(n + 1, -1);

    min_s[n] = 0;
    max_d[n] = 0;
    
    for(int i = 0; i <= n; i++) {
        int cur = -1;
        int min_s_val = max_s;
        for(int j = 0; j <= n; j++) {
            if(!visited[j] && min_s[j] < min_s_val) {
                cur = j;
                min_s_val = min_s[j];
            }
        }

        if(cur == -1) {
            break;
        }
        visited[cur] = true;

        for(auto& p : graph[cur]) {
            if(!visited[p.next]) {
                int s_to_next = min_s[cur] + p.s;
                int d_to_next = max_d[cur] + p.d;

                if(s_to_next < min_s[p.next]) {
                    min_s[p.next] = s_to_next;
                    max_d[p.next] = d_to_next;
                    pre[p.next] = cur;
                } else if(s_to_next == min_s[p.next] && d_to_next > max_d[p.next]) {
                    max_d[p.next] = d_to_next;
                    pre[p.next] = cur;
                }
            }
        }
    }

    if(consistent) {
        printf("Okay.\n");
    } else {
        printf("Impossible.\n");
    }

    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; i++) {
        int q;
        scanf("%d", &q);

        if(direct.count(q) > 0) {
            printf("You may take test %d directly.\n", q);
        } else if(!consistent) {
            printf("Error.\n");
        } else {
            vector<int> path;
            int j = q;
            while(j != n) {
                path.push_back(j);
                j = pre[j];
            }

            for(int j = path.size() - 1; j >= 0; --j) {
                printf("%d", path[j]);
                if(j != 0) {
                    printf("->");
                }
            }
            printf("\n");
        }
    }

    return 0;
}