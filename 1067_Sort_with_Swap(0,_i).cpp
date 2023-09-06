#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> pos(n);

    for(int i = 0; i < n; i++) {
        int s;
        scanf("%d", &s);
        pos[s] = i;
    }

    int count = 0;
    for(int i = 1; i < n; i++) {
        if(pos[i] != i) {
            while(pos[0] != 0) {
                swap(pos[0], pos[pos[0]]);
                count++;
            }

            if(pos[i] != i) {
                swap(pos[0], pos[i]);
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}