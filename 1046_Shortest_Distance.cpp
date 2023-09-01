#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hightway(n);
    for(auto& hw : hightway) {
        cin >> hw;
    }

    vector<int> forward(n, 0);
    for(int i = 1; i < n; i++) {
        forward[i] = forward[i - 1] + hightway[i - 1];
    }

    vector<int> backward(n, hightway[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        backward[i] = backward[i + 1] + hightway[i];
    }

    int m;
    cin >> m;
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if(a > b) {
            swap(a, b);
        }

        cout << min(forward[b] - forward[a], forward[a] + backward[b]) << endl;
    }

    return 0;
}