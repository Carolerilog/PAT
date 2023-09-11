#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();

    vector<string> lines(n);
    int min_len = 256;
    for(auto& line : lines) {
        getline(cin, line);

        if(line.size() < min_len) {
            min_len = line.size();
        }
    }

    int i = 0;
    int len = lines[0].size() - 1;
    bool flag = true;

    for(; i < min_len; i++) {
        for(int j = 1; j < n; j++) {
            int line_len = lines[j].size() - 1;
            if(lines[j][line_len - i] != lines[0][len - i]) {
                flag = false;
                break;
            }
        }

        if(!flag) {
            break;
        }
    }

    string kuchiguse = lines[0].substr(lines[0].size() - i, i);
    if(kuchiguse.size() == 0) {
        cout << "nai" << endl;
    } else {
        cout << kuchiguse << endl;
    }

    return 0;
}