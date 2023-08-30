#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> modified;
    unordered_map<char, char> confusing{{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};

    for(int i = 0; i < n; i++) {
        string team, passwd;
        cin >> team >> passwd;

        bool flag{false};
        for(int i = 0; i < passwd.size(); i++) {
            if(confusing.count(passwd[i]) > 0) {
                flag = true;
                passwd[i] = confusing[passwd[i]];
            }
        }

        if(flag) {
            modified.emplace_back(team, passwd);
        }
    }

    if(modified.size() == 0) {
        cout << "There " << (n > 1 ? "are " : "is ") << n << (n > 1 ? " accounts " : " account ") << "and no account is modified" << endl;
    } else {
        cout << modified.size() << endl;
        for(auto& [team, passwd] : modified) {
            cout << team << " " << passwd << endl;
        }
    }

    return 0;
}