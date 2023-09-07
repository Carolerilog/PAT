#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> coins(n);
    for(auto& c : coins) {
        scanf("%d", &c);
    }
    sort(coins.begin(), coins.end(), [](int a, int b) {
        return a > b;
    });

    vector<int> dp(m + 1, 0);
    vector<vector<bool>> choice(m + 1, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {
        for(int j = m; j >= coins[i]; j--) {
            if(dp[j] <= dp[j - coins[i]] + coins[i]) {
                dp[j] = dp[j - coins[i]] + coins[i];
                choice[j][i] = true;
            }
        }
    }

    if(dp[m] != m) {
        printf("No Solution\n");
    } else {
        vector<int> choosen;
        int sum = m;
        
        int idx = n - 1;
        while(sum > 0) {
            if(choice[sum][idx]) {
                choosen.push_back(idx);
                sum -= coins[idx];
            }

            idx--;
        }

        for(int i = 0; i < choosen.size(); i++) {
            if(i == 0) {
                printf("%d", coins[choosen[i]]);
            } else {
                printf(" %d", coins[choosen[i]]);
            }
        }

        printf("\n");
    }
    
    return 0;
}