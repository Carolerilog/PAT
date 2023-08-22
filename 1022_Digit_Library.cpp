#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    map<string, set<int>> title;
    map<string, set<int>> author;
    map<string, set<int>> keyword;
    map<string, set<int>> publisher;
    map<int, set<int>> year;

    int n;
    scanf("%d\n", &n);

    while(n--) {
        string id_str;
        getline(cin, id_str);
        int id = atoi(id_str.c_str());

        string t;
        getline(cin, t);
        title[t].insert(id);

        string a;
        getline(cin, a);
        author[a].insert(id);

        string k;
        getline(cin, k);
        int start_idx = 0;
        int end_idx = 0;
        while(end_idx <= k.size()) {
            if(k[end_idx] == ' ' || k[end_idx] == '\0') {
                keyword[k.substr(start_idx, end_idx - start_idx)].insert(id);
                start_idx = end_idx + 1;
            }

            end_idx++;
        }

        string p;
        getline(cin, p);
        publisher[p].insert(id);

        int y;
        scanf("%d\n", &y);
        year[y].insert(id);
    }

    int m;
    scanf("%d\n", &m);
    while(m--) {
        string q;
        getline(cin, q);

        int q_id = atoi(q.substr(0, 1).c_str());
        string q_content = q.substr(3, q.size() - 3);

        puts(q.c_str());
        set<int>* q_set_ptr{nullptr};
        switch(q_id) {
            case 1: q_set_ptr = &title[q_content]; break;
            case 2: q_set_ptr = &author[q_content]; break;
            case 3: q_set_ptr = &keyword[q_content]; break;
            case 4: q_set_ptr = &publisher[q_content]; break;
            case 5: q_set_ptr = &year[atoi(q_content.c_str())]; break;
            default: break;
        }

        set<int>& q_set = *q_set_ptr;
        if(q_set.size() == 0) {
            printf("Not Found\n");
        } else {
            for(auto id : q_set) {
                printf("%07d\n", id);
            }
        }
    }

    return 0;
}