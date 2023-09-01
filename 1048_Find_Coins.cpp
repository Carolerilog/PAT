#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> coins(n);
    for(auto& c : coins) {
        scanf("%d", &c);
    }

    sort(coins.begin(), coins.end());
    for(int i = 0; i < coins.size(); i++) {
        int c = coins[i];
        if(c >= m) {
            printf("No Solution\n");
            return 0;
        }

        int d = m - c;
        int l = 0;
        int r = coins.size() - 1;

        while(l <= r) {
            int m = (l + r) >> 1;
            int e = coins[m];

            if(e == d && i == m) {
                break;
            }

            if(e == d) {
                printf("%d %d\n", c, d);
                return 0;
            } else if(e < d) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    printf("No Solution\n");
    return 0;
}