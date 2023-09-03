#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    unordered_map<int, int> um;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int c;
            scanf("%d", &c);
            um[c]++;
        }
    }

    int dom_c;
    int max_num = 0;
    for(auto& [c, num] : um) {
        if(num > max_num) {
            max_num = num;
            dom_c = c;
        }
    }

    printf("%d\n", dom_c);
}