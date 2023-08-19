#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<float> poly[2]{vector<float>(1001, 0.f), vector<float>(1001, 0.f)};

    for(int i = 0; i < 2; ++i){
        int n;
        scanf("%d", &n);


        for(int j = 0; j < n; ++j)
        {
            int expo;
            float coef;
            scanf("%d%f", &expo, &coef);
            poly[i][expo] = coef;
        }
    }

    vector<pair<int, float>> poly_sum;
    
    for(int i = 1000; i>=0; --i) {
        poly[0][i] += poly[1][i];

        if(poly[0][i] != 0.f) {
            poly_sum.emplace_back(i, poly[0][i]);
        }
    }

    printf("%d", poly_sum.size());

    for(auto& item : poly_sum) {
        printf(" %d %.1f", item.first, item.second);
    }

    printf("\n");
    return 0;
}