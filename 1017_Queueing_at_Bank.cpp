#include <cstdio>
#include <vector>
#include <array>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    map<int, int> start_time;
    vector<int> processed_time(n, 0);

    for(int i = 0; i < n; i++) {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);        
        
        int t = h * 3600 + m * 60 + s;
        if(t > 17 * 3600) {
            continue;
        }

        start_time[t] = i;
        processed_time[i] = p * 60;
    }

    vector<int> end_time(k, 8 * 3600);
    int wait_time = 0;

    for(auto& [time, idx] : start_time) {
        int w = 0;

        for(int i = 0; i < k; i++) {
            if(end_time[w] > end_time[i]) {
                w = i;
            }
        }

        if(end_time[w] > time) {
            wait_time += end_time[w] - time;
            end_time[w] += processed_time[idx];
        } else {
            end_time[w] = time + processed_time[idx];
        }
    }

    if(start_time.size() > 0) {
        printf("%.1f\n", wait_time * 1.f / start_time.size() / 60.f);
    }

    return 0;
}