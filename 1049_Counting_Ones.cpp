#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    using ull = unsigned long long;

    ull n;
    scanf("%llu", &n);

    ull level = 0;
    ull base = 1;
    ull temp = n;
    ull count = 0;

    while(temp > 0) {
        ull i = temp % 10;
        ull last_count = count;

        if (i > 1) {
            count = i * level * base / 10 + base + last_count;
        } else if(i == 1) {
            count = level * base / 10 + (n % base + 1) + last_count;
        } else {
            count = last_count;
        }

        temp /= 10;
        level++;
        base *= 10;
    }

    printf("%llu\n", count);
    return 0;
}