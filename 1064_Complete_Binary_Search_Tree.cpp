#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);   

    vector<int> keys(n);
    for(auto& k : keys) {
        scanf("%d", &k);
    }
    sort(keys.begin(), keys.end());

    int count = 0;
    vector<int> level(n);

    function<void(int)> in_order;
    in_order = [&] (int root) {
        if(root >= level.size()) {
            return;
        }
        
        in_order(root * 2 + 1);
        level[root] = keys[count++];
        in_order(root * 2 + 2);
    };
    in_order(0);

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            printf("%d", level[i]);
        } else {
            printf(" %d", level[i]);
        }
    }
    printf("\n");

    return 0;
}