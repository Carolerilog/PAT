#include <iostream>
#include <functional>
#include <memory>

using namespace std;

struct node {
    node(int val) {
        this->val = val;
    }

    int val;
    unique_ptr<node> left{};
    unique_ptr<node> right{};
};

int main() {
    int n;
    cin >> n;

    vector<int> tree(n);
    for(auto& t : tree) {
        cin >> t;
    }

    int count;

    function<unique_ptr<node>(int, int)> build_bfs;
    build_bfs = [&] (int l, int r) -> unique_ptr<node> {
        if(l > r) {
            return {};
        }

        count++;

        if(l == r) {
            return make_unique<node>(tree[l]);
        }

        int lp = l + 1;
        int rp = r;

        while(lp < tree.size() && tree[lp] < tree[l]) {
            lp++;
        }
        lp--;

        while(rp > l && tree[rp] >= tree[l]) {
            rp--;
        }
        rp++;

        auto n = make_unique<node>(tree[l]);
        if(rp - lp == 1) {
            n->left = build_bfs(l + 1, lp);
            n->right = build_bfs(rp, r);
        }

        return n;
    };

    function<unique_ptr<node>(int, int)> build_bfs_mirror;
    build_bfs_mirror = [&] (int l, int r) -> unique_ptr<node> {
        if(l > r) {
            return {};
        }

        count++;

        if(l == r) {
            return make_unique<node>(tree[l]);
        }

        int lp = l + 1;
        int rp = r;

        while(lp < tree.size() && tree[lp] >= tree[l]) {
            lp++;
        }
        lp--;

        while(rp > l && tree[rp] < tree[l]) {
            rp--;
        }
        rp++;

        auto n = make_unique<node>(tree[l]);
        if(rp - lp == 1) {
            n->left = build_bfs_mirror(l + 1, lp);
            n->right = build_bfs_mirror(rp, r);
        }

        return n;
    };

    bool flag = false;
    function<void(node*)> post_order;
    post_order = [&](node* root) -> void {
        if(!root) {
            return;
        }

        post_order(root->left.get());
        post_order(root->right.get());

        if(!flag) {
            cout << root->val;
            flag = true;
        } else {
            cout << ' ' << root->val;
        }
    };

    count = 0;
    auto root = build_bfs(0, tree.size() - 1);
    if(count == tree.size()) {
        cout << "YES" << endl;
        post_order(root.get());
        cout << endl;
        return 0;
    }

    count = 0;
    auto root_mirror = build_bfs_mirror(0, tree.size() - 1);
    if(count == tree.size()) {
        cout << "YES" << endl;
        post_order(root_mirror.get());
        cout << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}