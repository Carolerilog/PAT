#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    double c_max, dest, d_avg;
    int n;
    cin >> c_max >> dest >> d_avg >> n;

    vector<pair<double, double>> stations(n);
    for(int i = 0; i < n; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    sort(stations.begin(), stations.end(), [](pair<double, double> const& a, pair<double, double> const& b) {
        return a.second < b.second;
    });

    if(stations[0].second > 0) {
        cout << "The maximum travel distance = 0" << endl;
        return 0;
    }

    vector<double> station_dist(n + 1, 0);
    vector<double> station_cost(n, 0.f);
    for(int i = 0; i < n; i++) {
        station_dist[i] = stations[i].second;
        station_cost[i] = stations[i].first;
    }
    station_dist[n] = dest;
    station_cost[n] = 0.f;

    constexpr double inf = numeric_limits<double>::max();
    
    double now_dist = 0;
    double now_cost = station_cost[0];
    double total_cost = 0.f;
    double left_dist = 0.f;

    while(now_dist < dest) {
        double min_cost_dist = 0;
        double min_cost = inf;
        double max_travel_dist = now_dist + c_max * d_avg;
        bool flag = false;

        for(int i = 0; i <= n && station_dist[i] <= max_travel_dist; i++) {
            if(station_dist[i] <= now_dist) {
                continue;
            }

            if(station_cost[i] < now_cost) {
                total_cost += (station_dist[i] - now_dist - left_dist) / d_avg * now_cost;
                left_dist = 0.f;
                now_dist = station_dist[i];
                now_cost = station_cost[i];
                flag = true;
                break;
            }

            if(station_cost[i] < min_cost) {
                min_cost_dist = station_dist[i];
                min_cost = station_cost[i];
            }
        }

        if(!flag && min_cost != inf) {
            total_cost += (c_max - left_dist / d_avg) * now_cost;
            left_dist = c_max * d_avg - (min_cost_dist - now_dist);
            now_dist = min_cost_dist;
            now_cost = min_cost;
        }

        if(!flag && min_cost == inf) {
            printf("The maximum travel distance = %.2f\n", now_dist + c_max * d_avg);
            return 0;
        }
    }

    printf("%.2f\n", total_cost);
    return 0;
}