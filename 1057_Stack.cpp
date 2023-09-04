#include <iostream>
#include <vector>
#include <array>

using namespace std;
constexpr int max_n = 100000;

struct stack {
    void push(int n) {
        stack.push_back(n);
        update(n, 1);
    }

    int pop() {
        int ret;
        if(stack.size() > 0) {
            ret = stack.back();
            stack.pop_back();
            update(ret, -1);
        } else {
            ret = -1;
        }
        return ret;
    }

    int peak_median() {
        int l = 1, r = max_n, k = (stack.size() + 1) / 2;

        while(l <= r) {
            int m = (l + r) / 2;
            int sum_a = get_sum(m - 1);
            int sum_b = get_sum(m);

            if(sum_a < k && sum_b >= k) {
                return m;
            } else if(sum_a >= k) {
                r = m - 1;
            } else if(sum_b < k) {
                l = m + 1;
            }
        }

        return -1;
    }
private:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int n, int val) {
        while(n <= max_n) {
            tree_array[n] += val;
            n += lowbit(n);
        }
    }

    int get_sum(int n) {
        int sum = 0;
        while(n >= 1) {
            sum += tree_array[n];
            n -= lowbit(n);
        }

        return sum;
    }

    vector<int> stack;
    array<int, max_n + 5> tree_array{0};
};

int main() {
    stack s;
    int n;
    cin >> n;
    
    while(n--) {
        string op;
        cin >> op;

        if(op == "Push") {
            int num;
            cin >> num;
            s.push(num);
        } else{
            int ret;

            if(op == "Pop") {
                ret = s.pop();
            } else {
                ret = s.peak_median();
            }

            if(ret == -1) {
                cout << "Invalid" << endl;
            } else {
                cout << ret << endl;
            }
        }
    }

    return 0;
}