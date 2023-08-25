#include <iostream>
#include <cstdio>
#include <array>
using namespace std;

array<bool, 100000> visited{false}; 
array<int, 100000> next_node{0};

int main() {
    int ns, ne, n;
    cin >> ns >> ne >> n;

    while(n--) {
        int a, nt;
        char d;
        cin >> a >> d >> nt;
        next_node[a] = nt;
    }

    while(ns != -1) {
        visited[ns] = true;
        ns = next_node[ns];
    }

    while(ne != -1) {
        if(visited[ne]) {
            break;
        }

        visited[ne] = true;
        ne = next_node[ne];
    }

    if(ne != -1) {
        printf("%05d\n", ne);
    } else {
        printf("-1\n");
    }

    return 0;
}