#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<tuple<long long, int, int, int, int>> global;

    for(int i = 0; i < n; i++) {
        vector<tuple<long long, int, int, int>> local;
        int m;
        scanf("%d", &m);

        if(m == 0) {
            continue;
        }

        for(int j = 0; j < m; j++) {
            long long id;
            int score;
            scanf("%lld%d", &id, &score);

            local.emplace_back(id, score, i, 0);
        }

        using ta = tuple<long long, int, int, int>;
        sort(local.begin(), local.end(), [](ta const& a, ta const& b) -> bool {
            auto& [id_a, s_a, num_a, rank_a] = a;
            auto& [id_b, s_b, num_b, rank_b] = b;
            return s_a > s_b;
        });

        auto& [id, s, num, rank] = local[0];
        rank = 0;
        global.emplace_back(id, s, num, rank, 0);

        for(int j = 1; j < m; j++) {
            auto& [id_0, s_0, num_0, rank_0] = local[j];
            auto& [id_1, s_1, num_1, rank_1] = local[j - 1];

            if(s_0 == s_1) {
                rank_0 = rank_1;
            } else {
                rank_0 = j;
            }

            global.emplace_back(id_0, s_0, num_0, rank_0, 0);
        }
    }

    using tb = tuple<long long, int, int, int, int>;
    sort(global.begin(), global.end(), [](tb const& a, tb const& b) -> bool {
        auto& [id_a, s_a, num_a, rankl_a, rankg_a] = a;
        auto& [id_b, s_b, num_b, rankl_b, rankg_b] = b;
        return s_a > s_b || (s_a == s_b && id_a < id_b);
    });

    printf("%ld\n", global.size());

    if(global.size() == 0) {
        return 0;
    }

    auto& [id, s, num, rankl, rankg] = global[0];
    rankg = 0;
    printf("%013lld %d %d %d\n", id, rankg + 1, num + 1, rankl + 1);

    for(int j = 1; j < global.size(); j++) {
        auto& [id_0, s_0, num_0, rankl_0, rankg_0] = global[j];
        auto& [id_1, s_1, num_1, rankl_1, rankg_1] = global[j - 1];

        if(s_0 == s_1) {
            rankg_0 = rankg_1;
        } else {
            rankg_0 = j;
        }

        printf("%013lld %d %d %d\n", id_0, rankg_0 + 1, num_0 + 1, rankl_0 + 1);
    }

    return 0;
}