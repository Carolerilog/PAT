#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int num, rad;
    scanf("%d%d", &num, &rad);

    vector<int> pal;
    while(num > 0) {
        pal.push_back(num % rad);
        num /= rad;
    }

    int l = 0;
    int r = pal.size() - 1;
    bool flag = true;
    while(l <= r) {
        if(pal[l] != pal[r]) {
            flag = false;
            break;
        }

        l++;
        r--;
    }

    if(flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for(int i = pal.size() - 1; i >= 0; i--) {
        if(i > 0) {
            printf("%d ", pal[i]);
        } else {
            printf("%d\n", pal[i]);
        }
    }

    return 0;
}