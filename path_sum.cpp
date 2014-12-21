// DFS
// recursive
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
    
    if (NULL != root)
    {
        if(sum == root->val && NULL == root->left && NULL == root->right)
            return true;
        if (hasPathSum(root->left, sum - root->val) 
                || hasPathSum(root->right, sum - root->val))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{

    return 0;
}
