#include <cstdio>
#include <tuple>

using namespace std;

int main() {
    float w[3], t[3], l[3];

    for(int i = 0; i < 3; i++) {
        scanf("%f%f%f", w + i, t + i, l + i);
    }

    auto find_max = [&](int idx) ->  tuple<char, float> {
        if(w[idx] >= t[idx]) {
            if(t[idx] >= l[idx]) {
                return {'W', w[idx]};
            } else if (w[idx] >= l[idx]) {
                return {'W', w[idx]};
            } else {
                return {'L', l[idx]};
            }
        } else {
            if(w[idx] >= l[idx]) {
                return {'T', t[idx]};
            } else if(t[idx] >= l[idx]) {
                return {'T', t[idx]};
            } else {
                return {'L', l[idx]};
            }
        }
    };

    float profit = 1.f;

    for(int i = 0; i < 3; i++) {
        auto [o, p] = find_max(i);
        printf("%c ", o);        
        profit *= p;
    }

    printf("%.2f\n", (profit * .65f - 1.f) * 2.f);
    return 0;
}