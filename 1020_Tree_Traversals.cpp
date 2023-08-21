#include <cstdio>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

struct node {
    int val;
    node* left{nullptr};
    node* right{nullptr};
};

int main() {
    int n;
    scanf("%d", &n);

    vector<int> post(n);
    vector<int> in(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    function<node*(int,int,int,int)> build_tree;
    build_tree = [&](int post_l, int post_r, int in_l, int in_r) -> node*{
        if(post_l > post_r || in_l > in_r) {
            return nullptr;
        }

        node* root = new node{post[post_r]};

        int root_in_i = 0;
        int left_size = 0;
        for(int i = in_l; i <= in_r; i++) {
            if(in[i] == root->val) {
                root_in_i = i;
                left_size = root_in_i - in_l;
                break;
            }
        }

        root->left = build_tree(post_l, post_l + left_size - 1, in_l, root_in_i - 1);
        root->right = build_tree(post_l + left_size, post_r - 1, root_in_i + 1, in_r);
        return root;
    };

    auto root = build_tree(0, n - 1, 0, n - 1);
    queue<node*> q;
    q.push(root);
    bool flag = false;

    while(!q.empty()) {
        auto n = q.front();
        q.pop();

        if(!flag) {
            printf("%d", n->val);
            flag = true;
        } else {
            printf(" %d", n->val);
        }

        if(n->left) {
            q.push(n->left);
        }

        if(n->right) {
            q.push(n->right);
        }
    }

    printf("\n");
    return 0;
}