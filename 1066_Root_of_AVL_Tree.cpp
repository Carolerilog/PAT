#include <cstdio>
#include <algorithm>

using namespace std;

struct AVL {
    void insert(int val) {
        root = insert(root, val);
    }

    int get_root() {
        return root->val;
    }

private:
    struct node {
        int val;
        node* left{nullptr};
        node* right{nullptr};
    } *root{nullptr};

    node* insert(node* n, int val) {
        if(!n) {
            n = new node{val};
            return n;   
        } else if(n->val > val) {
            n->left = insert(n->left, val);

            if(get_height(n->left) - get_height(n->right) > 1) {
                if(val < n->left->val) {
                    return right(n);
                } else {
                    return left_right(n);
                }
            }
        } else {
            n->right = insert(n->right, val);

            if(get_height(n->right) - get_height(n->left) > 1) {
                if(val > n->right->val) {
                    return left(n);
                } else {
                    return right_left(n);
                }
            }
        }

        return n;
    }

    int get_height(node* n) {
        if(!n) {
            return 0;
        } else {
            return max(get_height(n->left), get_height(n->right)) + 1;
        }
    }

    node* left(node* root) {
        node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        return temp;
    }

    node* right(node* root) {
        node* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        return temp;
    }

    node* left_right(node* root) {
        root->left = left(root->left);
        return right(root);
    }

    node* right_left(node* root) {
        root->right = right(root->right);
        return left(root);
    }
};

int main() {
    int n;
    scanf("%d", &n);

    AVL avl;
    while(n--) {
        int num;
        scanf("%d", &num);
        avl.insert(num);
    }

    printf("%d\n", avl.get_root());
    return 0;
}
