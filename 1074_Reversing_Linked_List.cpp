#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int head_addr, n, k;
    scanf("%d%d%d", &head_addr, &n, &k);

    using node = pair<int, int>;
    unordered_map<int, node> linked_list;
    for(int i = 0; i < n; i++) {
        int addr, val, next;
        scanf("%d%d%d", &addr, &val, &next);
        linked_list.emplace(addr, node{val, next});
    }

    int reverse_head_addr = -1;
    int prev_tail_addr = -1;

    while(head_addr != -1) {
        int tail_addr = head_addr;
        int temp_addr = head_addr;
        int count = 0;
        for(; count < k && temp_addr != -1; count++) {
            tail_addr = linked_list.at(temp_addr).second;
            temp_addr = tail_addr;
        }

        if(count < k) {
            break;
        }

        int next_head_addr = tail_addr;
        int next_prev_tail_addr = head_addr;

        for(int i = 0; i < k && head_addr != -1; i++) {
            int temp = linked_list.at(head_addr).second;
            linked_list.at(head_addr).second = tail_addr;
            tail_addr = head_addr;

            if(i == k - 1 && prev_tail_addr != -1) {
                linked_list.at(prev_tail_addr).second = head_addr;
            }

            if(i == k - 1 && reverse_head_addr == -1) {
                reverse_head_addr = head_addr;
            }

            head_addr = temp;
        }

        head_addr = next_head_addr;
        prev_tail_addr = next_prev_tail_addr;
    }

    head_addr = reverse_head_addr;
    for(int i = 0;i < n && head_addr != -1; i++) {
        auto& [val, next_addr] = linked_list.at(head_addr);

        if(next_addr != -1) {
            printf("%05d %d %05d\n", head_addr, val, next_addr);
        } else {
            printf("%05d %d %d\n", head_addr, val, next_addr);
        }
        head_addr = next_addr;
    }

    return 0;
}