#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    using ull = unsigned long long;

    ull n;
    scanf("%llu", &n);

    ull max_prime = sqrt(n);
    vector<bool> is_prime(n + 1, true);
    vector<ull> primes;
    is_prime[0] = is_prime[1] = false;

    for(ull i = 2; i <= max_prime; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }

        for(ull p : primes) {
            if(p * i > max_prime) {
                break;
            }

            is_prime[p * i] = false;

            if(i % p == 0) {
                break;
            }
        }
    }

    vector<pair<ull, ull>> factors;
    int m = n;
    for(ull p : primes) {
        if(m == 1) {
            break;
        }

        if(m % p == 0) {
            int k = 0;
            int pp = p;
            while(m % pp == 0) {
                pp *= p;
                k++;
            }

            m /= pp / p;
            factors.emplace_back(p, k);
        }
    }

    if(factors.size() == 0) {
        factors.emplace_back(n, 1);
    }

    bool flag = false;
    for(auto& [p, k] : factors) {
        if(!flag) {
            printf("%llu=", n);
            flag = true;
        } else {
            printf("*");
        }

        printf("%llu", p);

        if(k > 1) {
            printf("^%llu", k);
        } 
    }

    printf("\n");
    return 0;
}