
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* MakeNode(int val)
{
    TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
    if (tmp == NULL) {
        return NULL;
    }

    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

void InsertNode(struct TreeNode *parent, int val)
{
    if (parent == NULL) {
        return;
    }

    if (val > parent->val) {
        if (parent->right != NULL) {
            InsertNode(parent->right, val);
        } else {
            parent->right = MakeNode(val);
        }
    } else if(val < parent->val) {
        if (parent->left != NULL) {
            InsertNode(parent->left, val);
        } else {
            parent->left = MakeNode(val);
        }
    }
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    if ((preorder == NULL) || (preorderSize == 0)) {
        return NULL;
    }

    TreeNode* root = MakeNode(preorder[0]);
    if (root == NULL) {
        return NULL;
    }
    for (int i = 1; i < preorderSize; i++) {
        InsertNode(root, preorder[i]);
    }

    return root;
}