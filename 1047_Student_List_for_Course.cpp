// iostream too slow here
#include <cstdio>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    array<array<char, 5>, 40000> names;
    array<vector<int>, 2500> courses;

    for(int i = 0; i < n; i++) {
        int m;
        scanf("%s%d", names[i].data(), &m);

        while(m--) {
            int c;
            scanf("%d", &c);
            courses[c - 1].push_back(i);
        }
    }

    for(int i = 0; i < k; i++) {
        sort(courses[i].begin(), courses[i].end(), [&] (int a, int b) {
            return strcmp(names[a].data(), names[b].data()) < 0;
        });

        printf("%d %d\n", i + 1, courses[i].size());
        for(int idx : courses[i]) {
            printf("%s\n", names[idx].data());
        }
    }

    return 0;
}