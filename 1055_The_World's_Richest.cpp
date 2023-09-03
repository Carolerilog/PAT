#include <cstdio>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct forbes {
    string name;
    int age;
    int wealth;
};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    vector<forbes> f(n);
    for(int i = 0; i < n; i++) {
        f[i].name.resize(9);
        scanf("%s%d%d", f[i].name.data(), &f[i].age, &f[i].wealth);
    }

    sort(f.begin(), f.end(), [](forbes const& a, forbes const& b){
        if(a.wealth > b.wealth) {
            return true;
        } else if(a.wealth == b.wealth) {
            if(a.age < b.age) {
                return true;
            } else if(a.age == b.age) {
                if(a.name < b.name) {
                    return true;
                }
            }
        }

        return false;
    });

    for(int i = 0; i < k; i++) {
        int max_output;
        int min_age;
        int max_age;
        scanf("%d%d%d", &max_output, &min_age, &max_age);

        printf("Case #%d:\n", i + 1);
        int count = 0;
        for(auto& s : f) {
            if(count >= max_output) {
                break;
            }

            if(s.age >= min_age && s.age <= max_age) {
                printf("%s %d %d\n", s.name.c_str(), s.age, s.wealth);
                count++;
            }
        }

        if(count == 0) {
            printf("None\n");
        }
    }

    return 0;
}