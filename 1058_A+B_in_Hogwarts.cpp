#include <cstdio>

using namespace std;

int main() {
    int g[3]{0};
    int s[3]{0};
    int k[3]{0};

    for(int i = 0; i < 2; i++) {
        scanf("%d.%d.%d", g + i, s + i, k + i);
    }

    k[2] += k[0] + k[1];
    s[2] += k[2] / 29;
    k[2] = k[2] % 29;
    s[2] += s[0] + s[1];
    g[2] += s[2] / 17;
    s[2] =  s[2] % 17;
    g[2] += g[0] + g[1];

    printf("%d.%d.%d\n", g[2], s[2], k[2]);
    return 0;
}