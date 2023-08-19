#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    unordered_map<int, vector<int>> tree;
    unordered_set<int> non_root;

    for(int i = 0; i < m; i++) {
        int node_id, k;
        scanf("%d%d", &node_id, &k);

        tree[node_id].resize(k);

        for(auto& child : tree[node_id]) {
            scanf("%d", &child);

            if(tree.count(child) == 0) {
                tree[child] = {};
            }

            non_root.insert(child);
        }
    }

    queue<pair<int, int>> q;

    for(auto& [node_id, _] : tree) {
        if(non_root.count(node_id) == 0) {
            q.emplace(0, node_id);
        }
    }

    vector<int> num;
    while(!q.empty()) {
        auto [level, id] = q.front();
        q.pop();

        if(level == num.size()) {
            num.push_back(0);
        }

        if(tree[id].size() == 0) {
            num[level]++;
        } else {
            for(auto child : tree[id]) {
                q.emplace(level + 1, child);
            }
        }
    }

    bool flag = false;
    for(auto n : num) {
        if (!flag) {
            printf("%d", n);
            flag = true;
        } else {
            printf(" %d", n);
        }
    }

    if (m == 0) {
        printf("%d", n);
    }

    printf("\n");
}