#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct stu {
    string name;
    string gender;
    string id;
    int grade;

    bool operator<(stu const& rhs) const {
        return grade > rhs.grade;
    }
};

int main() {
    vector<stu> m;
    vector<stu> f;

    int n;
    cin >> n;

    while(n--) {
        stu s;
        cin >> s.name >> s.gender >> s.id >> s.grade;

        if(s.gender == "M") {
            m.push_back(s);
        } else {
            f.push_back(s);
        }
    }

    sort(m.begin(), m.end());
    sort(f.begin(), f.end());

    if(f.size() > 0) {
        cout << f.front().name << " " << f.front().id << endl;
    } else {
        cout << "Absent" << endl;
    }

    if(m.size() > 0) {
        cout << m.back().name << " " << m.back().id << endl;
    } else {
        cout << "Absent" << endl;
    }

    if(f.size() > 0 && m.size() > 0) {
        cout << f.front().grade - m.back().grade << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}