#include <cstdio>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    using stu = tuple<int, string, int>;
    vector<stu> stus;

    while(n--) {
        int id;
        string name;
        int grade;
        cin >> id >> name >> grade;
        stus.emplace_back(id, name, grade);
    }

    sort(stus.begin(), stus.end(), [&](stu const& a, stu const& b){
        auto& [id_a, name_a, grade_a] = a;
        auto& [id_b, name_b, grade_b] = b;

        if(c == 1) {
            return id_a < id_b;
        } else if(c == 2) {
            return name_a < name_b || (name_a == name_b && id_a < id_b);
        } else {
            return grade_a < grade_b || (grade_a == grade_b && id_a < id_b);
        }
    });

    for(auto& [id, name, grade] : stus) {
        printf("%06d %s %d\n", id, name.data(), grade);
    }

    return 0;
}