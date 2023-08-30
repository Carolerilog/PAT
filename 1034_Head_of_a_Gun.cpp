#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<string, unordered_map<string, int>> g;    

    for(int i = 0; i < n; i++) {
        string a, b;
        int t;
        cin >> a >> b >> t;

        if(g[a].count(b) == 0) {
            g[a][b] = 0;
        }

        if(g[b].count(a) == 0) {
            g[b][a] = 0;
        }

        g[a][b] += t;
        g[b][a] += t;
    }

    unordered_set<string> visited;
    map<string, int> gangs;

    for(auto& [name, _] : g) {
        if(visited.count(name) == 0) {
            function<void(string const&)> dfs;
            unordered_map<string, int> gang_weight;
            int total_relation = 0;

            dfs = [&](string const& name) {
                visited.insert(name);
                gang_weight[name] = 0;

                for(auto& [related_name, relation] : g[name]) {
                    gang_weight[name] += relation;
                    total_relation += relation;

                    if(visited.count(related_name) == 0) {
                        dfs(related_name);
                    }
                }
            };
            dfs(name);
            total_relation /= 2;

            if(gang_weight.size() > 2 && total_relation > k) {
                string & head = const_cast<string &>(name);
                int max_weight = gang_weight[name];

                for(auto& [name, weight] : gang_weight) {
                    if(weight > max_weight) {
                        max_weight = weight;
                        head = name;
                    }
                }

                gangs[head] = gang_weight.size();
            }
        }       
    }

    cout << gangs.size() << endl;
    for(auto& [head, num] : gangs) {
        cout << head << ' ' << num << endl;
    }

    return 0;
}