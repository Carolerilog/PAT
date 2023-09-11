#include <cstdio>
#include <vector>

using namespace std;

int main() {
    constexpr int max_size = 20001;
    vector<int> primes;
    vector<bool> prime_mark(max_size, true);

    prime_mark[0] = prime_mark[1] = false;

    for(int i = 2; i <= max_size; i++) {
        if(prime_mark[i]) {
            primes.push_back(i);
        }

        for(auto& p : primes) {
            if(i * p > max_size) {
                break;
            }

            prime_mark[i * p] = false;

            if(i % p == 0) {
                break;
            }
        }
    }

    int m_size, n;
    scanf("%d%d", &m_size, &n);

    while(!prime_mark[m_size]) {
        m_size++;
    }

    vector<int> pos(n, -1);
    vector<bool> pos_mark(m_size, false);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        for(int j = 0; j < m_size; j++) {
            int p = (num + j * j) % m_size;

            if(!pos_mark[p]) {
                pos[i] = p;
                pos_mark[p] = true;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(i != 0) {
            printf(" ");
        }

        if(pos[i] == -1) {
            printf("-");
        } else {
            printf("%d", pos[i]);
        }
    }

    printf("\n");
    return 0;
}