#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int np, ng;
    scanf("%d%d", &np, &ng);

    vector<int> weight(np);
    for(auto& w : weight) {
        scanf("%d", &w);
    }

    vector<int> order(np);
    for(auto& o : order) {
        scanf("%d", &o);
    }

    vector<vector<int>> loser;
    while(true) {
        vector<int> next_order;
        vector<int> l;
        for(int i = 0; i < order.size(); i += ng) {
            int max_w = 0;
            for(int j = i; j < order.size() && j < i + ng; j++) {
                int w = weight[order[j]];
                if(w > max_w) {
                    max_w = w;
                }
            }

            for(int j = i; j < order.size() && j < i + ng; j++) {
                int w = weight[order[j]];
                if(w == max_w) {
                    next_order.push_back(order[j]);
                } else {
                    l.push_back(order[j]);
                }
            }
        }

        if(l.size() == 0) {
            loser.push_back(std::move(next_order));
            break;
        } else {
            loser.push_back(std::move(l));
            order = std::move(next_order);
        }
    }

    int r = 1;
    vector<int> rank(np);
    for(int i = loser.size() - 1; i >= 0; i--) {
        for(int p : loser[i]) {
            rank[p] = r;
        }

        r += loser[i].size();
    }

    for(int i = 0; i < rank.size(); i++) {
        if(i == 0) {
            printf("%d", rank[i]);
        } else {
            printf(" %d", rank[i]);
        }
    }
    printf("\n");

    return 0;
}