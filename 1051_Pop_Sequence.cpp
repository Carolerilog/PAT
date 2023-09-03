#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);

    while(k--) {
        vector<int> seq(n);        
        for(int& s : seq) {
            scanf("%d", &s);
        }

        int i = 0;
        int j = 1;

        bool flag = true;
        int max_s = seq[0];

        while(j < n) {
            while(j < n && seq[j] < seq[j - 1] )
            {
                max_s = max(max_s, seq[j]);               
                j++;
            }

            if(j - i > m) {
                flag = false;
                break;
            }

            if(j < n && seq[j] < max_s) {
                flag = false;
                break;
            }

            i = j;
            max_s = max(max_s, seq[j]);
            j++;
        }

        printf(flag ? "YES\n" : "NO\n");
    }

    return 0;
}