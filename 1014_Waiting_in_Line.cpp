#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);

    vector<int> finish_time(k);
    vector<int> pop_time(n, 0);
    vector<int> end_time(n, 0);
    vector<queue<int>> window(n);

    int num = min(n * m, k);
    for(int i = 0; i < num; i++) {
        int proc;
        scanf("%d", &proc);
        window[i % n].push(proc);
        
        if(i / n == 0) {
            pop_time[i % n] = proc;
        }

        if (end_time[i % n] >= 540) {
            finish_time[i] = -1;
        } else {
            end_time[i % n] += proc;
            finish_time[i] = end_time[i % n];
        }
    }
    
    for(int i = num; i < k; i++) {
        int proc;
        scanf("%d", &proc);

        int min_pop = 0;
        for(int j = 1; j < n; j++) {
            if(pop_time[min_pop] > pop_time[j]) {
                min_pop = j;
            }
        }
        
        window[min_pop].pop();
        window[min_pop].push(proc);
        pop_time[min_pop] += window[min_pop].front();

        if(end_time[min_pop] >= 540) {
            finish_time[i] = -1;
        } else {
            end_time[min_pop] += proc;
            finish_time[i] = end_time[min_pop];
        }
    }

    while(q--) {
        int query;
        scanf("%d", &query);
        query--;

        if(finish_time[query] == -1) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", 8 + finish_time[query] / 60, finish_time[query] % 60);
        }
    }

    return 0;
}