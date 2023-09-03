#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
    int addr;
    int val;
    int next;

    bool operator<(node const& rhs) const {
        return val < rhs.val;
    }
};

int main() {
    int n;
    int head;
    scanf("%d%d", &n, &head);    

    unordered_map<int, node> list;
    for(int i = 0; i < n; i++) {
        node l;
        scanf("%d%d%d", &l.addr, &l.val, &l.next);
        list[l.addr] = l;
    }

    if(list.count(head) == 0) {
        printf("0 -1\n");
        return 0;
    }

    vector<node> linked_list;
    node& l = list[head];

    while(true) {
        linked_list.push_back(l);

        if(l.next <= 0) {
            break;
        }

        l = list[l.next];
    }

    sort(linked_list.begin(), linked_list.end());

    printf("%lu %05d\n", linked_list.size(), linked_list[0].addr);
    for(int i = 0; i < linked_list.size(); i++) {
        if(i < linked_list.size() - 1) {
            printf("%05d %d %05d\n", linked_list[i].addr, linked_list[i].val, linked_list[i + 1].addr);
        } else {
            printf("%05d %d -1\n", linked_list[i].addr, linked_list[i].val);
        }
    }
    
    return 0;
}