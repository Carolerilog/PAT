#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<int, float> poly[2];
    map<int, float, greater<int>> poly_prod;

    for(auto& p : poly) {
        int k;
        scanf("%d", &k);

        while(k--) {
            int n;
            float num;
            scanf("%d%f", &n, &num);
            p[n] = num;
        }
    }

    for(auto& [n0, num0] : poly[0]) {
        for(auto& [n1, num1] : poly[1]) {
            int n = n0 + n1;
            float num = num0 * num1;

            poly_prod[n] += num;
        }
    }

    for(auto& [key, val] : poly_prod) {
        if (val == 0.f) {
            poly_prod.erase(key);
        }
    }

    printf("%lu", poly_prod.size());

    for(auto& [n, num] : poly_prod) {
        printf(" %d %.1f", n, num);
    }

    printf("\n");    
    return 0;
}