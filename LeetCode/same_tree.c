
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Both trees are empty
    if (p == NULL && q == NULL)
        return true;

    // Only one tree is empty
    if (p == NULL || q == NULL)
        return false;

    // Check values and subtrees
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
