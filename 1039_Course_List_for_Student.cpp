#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<string, vector<int>> stu;

    for(int i = 0; i < k; i++) {
        int id, num;
        cin >> id >> num;

        for(int j = 0; j < num; j++) {
            string name;
            cin >> name;
            stu[name].push_back(id);
        }
    }

    for(auto& [name, courses] : stu) {
        sort(courses.begin(), courses.end());
    }

    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << name << ' ' << stu[name].size();

        for(auto& id : stu[name]) {
            cout << ' ' << id;
        }

        cout << endl;
    }

    return 0;
}