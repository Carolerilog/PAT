#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct mooncake {
    float w;
    float p;
};

int main() {
    int n;
    int d;
    scanf("%d%d", &n, &d);

    vector<mooncake> mks(n);
    for(auto& m : mks) {
        scanf("%f", &m.w);
    }
    for(auto& m : mks) {
        scanf("%f", &m.p);
        m.p /= m.w;
    }

    sort(mks.begin(), mks.end(), [] (mooncake const& a, mooncake const& b) {
        return a.p > b.p;
    });

    float s = 0.f;
    for(auto& m : mks) {
        if(d == 0.f) {
            break;
        }

        float w = min(m.w, (float)d);
        d -= w;
        s += m.p * w;
    }
    
    printf("%.2f\n", s);
    return 0;
}