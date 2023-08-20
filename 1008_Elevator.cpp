#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int e = 0;
    int t = 0;

    for(int i = 0; i < n; i++) {
        int f;
        cin >> f;

        if(f > e) {
            t += (f - e) * 6 + 5;
        }
        else if(f < e) {
            t += (e - f) * 4 + 5;
        }

        e = f;
    }

    cout << t << endl;
}