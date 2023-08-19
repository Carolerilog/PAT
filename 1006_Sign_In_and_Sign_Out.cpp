#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool operator < (const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

bool operator > (const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

struct sign_greater {
    auto operator()(pair<string, int> const& x, pair<string, int> const& y) -> bool {
        return x.second > y.second;
    }
};

struct sign_less {
    auto operator()(pair<string, int> const& x, pair<string, int> const& y) -> bool {
        return x.second < y.second;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<pair<string, int>, vector<pair<string, int>>, sign_greater> sign_in_pq;
    priority_queue<pair<string, int>, vector<pair<string, int>>, sign_less> sign_out_pq;
    

    for(int i = 0; i < n; i++) {
        string id, sign_in_time, sign_out_time;
        cin >> id >> sign_in_time >> sign_out_time;

        auto to_sec = [](const string& time) -> int {
            auto h = atoi(time.substr(0, 2).c_str());
            auto m = atoi(time.substr(3, 2).c_str());
            auto s = atoi(time.substr(6, 2).c_str());

            return h * 3600 + m * 60 + s;
        };

        sign_in_pq.emplace(id, to_sec(sign_in_time));
        sign_out_pq.emplace(id, to_sec(sign_out_time));
    }

    printf("%s %s\n", sign_in_pq.top().first.c_str(), sign_out_pq.top().first.c_str());
}