#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<unordered_set<int>> sets(n);
    for(auto& s : sets) {
        int m;
        scanf("%d", &m);

        while(m--) {
            int t;
            scanf("%d", &t);
            s.insert(t);
        }
    }

    int k;
    scanf("%d", &k);
    while(k--) {
        int a, b;
        scanf("%d%d", &a, &b);

        a--;
        b--;
        unordered_set<int> s = sets[a];

        int count = 0;
        for(auto& i : sets[b]) {
            if(s.count(i) > 0) {
                count++;
            }
        }

        s.insert(sets[b].begin(), sets[b].end());
        printf("%.1f%%\n", count * 100.f / s.size());
    }

    return 0;
}