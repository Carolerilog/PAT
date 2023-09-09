#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    int n, m, k, ds;
    cin >> n >> m >> k >> ds;

    vector<vector<pair<int, int>>> g(n + m + 1);
    while(k--) {
        string s_str, e_str;
        int c;
        cin >> s_str >> e_str >> c;

        auto to_idx = [&n] (string const& str) -> int {
            if(str[0] == 'G') {
                return str[1] - '0' + n;
            } else {
                return stoi(str);
            }
        };
        
        int s = to_idx(s_str);
        int e = to_idx(e_str);

        g[s].emplace_back(e, c);
        g[e].emplace_back(s, c);
    }

    constexpr int max_d = numeric_limits<int>::max();
    constexpr float max_s = numeric_limits<float>::max();

    float max_serv = -1.f;
    float min_serv_avg = max_s;
    int min_serv_g = n + 1;

    for(int i = n + 1; i <= n + m; i++) {
        vector<int> dist(n + m + 1, max_d);
        vector<bool> visited(n + m + 1, false);
        dist[i] = 0;

        for(int j = 1; j <= n + m; j++) {
            int c = -1;
            int d = max_d;

            for(int k = 1; k <= n + m; k++) {
                if(!visited[k] && dist[k] < d) {
                    d = dist[k];
                    c = k;
                }
            }

            if(d == max_d) {
                break;
            }
            visited[c] = true;

            for(auto& [next, cost] : g[c]) {
                if(!visited[next] && dist[next] > dist[c] + cost) {
                    dist[next] = dist[c] + cost;
                }
            }
        }

        float serv = max_s;
        float serv_avg = 0.f;

        for(int j = 1; j <= n; j++) {
            if(dist[j] > ds) {
                serv = -1.f;
                break;
            }

            serv = min(serv, (float)dist[j]);
            serv_avg += dist[j];
        }
        serv_avg /= n;

        if(serv != -1.f 
        && ((serv > max_serv)
            || (serv == max_serv && serv_avg < min_serv_avg))) {
            max_serv = serv;
            min_serv_avg = serv_avg;
            min_serv_g = i;
        }
    }

    if(max_serv == -1.f) {
        cout << "No Solution" << endl;
    } else {
        cout << "G" << min_serv_g - n << endl;
        cout << fixed << setprecision(1) << max_serv << " " << min_serv_avg << endl;
    }

    return 0;
}