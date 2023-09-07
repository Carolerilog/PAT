#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num;
    scanf("%d", &num);

    do {
        vector<int> n(4);
        for(int i = 0; i < 4; i++) {
            n[i] = num % 10;
            num /= 10;
        }
        sort(n.begin(), n.end());
        vector<int> r(n.rbegin(), n.rend());
        
        int a = 0;
        int b = 0;
        for(int i = 0; i < 4; i++) {
            a += n[i];
            b += r[i];

            if(i < 3) {
                a *= 10;
                b *= 10;
            }
        } 

        num = b - a;
        printf("%04d - %04d = %04d\n", b, a, num);
    } while(num != 6174 && num != 0);

    return 0;
}