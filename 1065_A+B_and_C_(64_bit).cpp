#include <cstdio>
#include <vector>

using namespace std;

int main() {
    using ll = long long;
    using ull = unsigned long long;

    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        c = -c;

        ull aa, bb, cc;
        aa = (ull) a;
        bb = (ull) b;
        cc = (ull) c;

        vector<int> aaa(64), bbb(64), ccc(64);
        for(int i = 0; i < 64; i++) {
            aaa[i] = aa % 2ull;
            bbb[i] = bb % 2ull;
            ccc[i] = cc % 2ull;

            aa /= 2;
            bb /= 2;
            cc /= 2;
        }
        
        aaa.resize(128, aaa[63]);
        bbb.resize(128, bbb[63]);
        ccc.resize(128, ccc[63]);

        vector<int> d(128);
        int rest = 0;

        for(int i = 0; i < 128; i++) {
            d[i] = aaa[i] + bbb[i] + ccc[i] + rest;
            rest = d[i] / 2;
            d[i] = d[i] % 2;
        }

        bool flag = false;
        for(auto i : d) {
            if(i == 1) {
                flag = true;
                break;
            }
        }

        if(!flag) {
            d[127] = 1;
        }

        printf("Case #%d: ", i + 1);
        printf(d[127] == 0 ? "true\n" : "false\n");
    }
    return 0;
}