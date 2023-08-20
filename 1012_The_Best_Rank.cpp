#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >>m;

    vector<pair<string, int>> C;
    vector<pair<string, int>> M;
    vector<pair<string, int>> E;
    vector<pair<string, int>> A;
    unordered_map<string, vector<pair<string, int>>> um;

    while(n--) {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        C.push_back({id, c});
        M.push_back({id, m});
        E.push_back({id, e});
        A.push_back({id, (c + m + e) / 3});
    }

    auto cmp = [](pair<string, int> const& a, pair<string, int> const& b) {
        return a.second > b.second;
    };

    sort(C.begin(), C.end(), cmp);
    sort(M.begin(), M.end(), cmp);
    sort(E.begin(), E.end(), cmp);
    sort(A.begin(), A.end(), cmp);

    auto find_rk = [](vector<pair<string, int>> const& course, int idx) -> int {
        if (idx > 0) {
            while(course[idx].second == course[idx - 1].second) {
                idx--;
            }
        }

        return idx + 1;
    };

    for(int i = 0; i < A.size(); i++) {
        um[C[i].first].push_back({"C", find_rk(C, i)});
        um[M[i].first].push_back({"M", find_rk(M, i)});
        um[E[i].first].push_back({"E", find_rk(E, i)});
        um[A[i].first].push_back({"A", find_rk(A, i)});
    }

    auto cmp_rk = [](pair<string, int> const& a, pair<string, int> const& b) {
        if(a.second < b.second) {
            return true;
        } else if(a.second == b.second) {
            static unordered_map<string, int> rk = {
                {"A", 4}, {"C", 3}, {"M", 2}, {"E", 1}
            };

            return rk[a.first] > rk[b.first];
        } else {
            return false;
        }
    };

    for(auto& [key, val] : um) {
        sort(val.begin(), val.end(), cmp_rk);
    }

    while(m--) {
        string id;
        cin >> id;

        if(um.count(id) == 0) {
            cout << "N/A" << endl;
        } else {
            cout << um[id][0].second << " " << um[id][0].first << endl;
        }
    }

    return 0;
}