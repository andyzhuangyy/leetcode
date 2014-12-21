// DFS
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unsigned int TreeHight(TreeNode *root){
    if (NULL == root)
        return 0;
    unsigned int left = 1;
    unsigned int right = 1;
    left += TreeHight(root->left);
    right += TreeHight(root->right);
    return left > right ? left : right;

}

bool isBalanced(TreeNode *root){ 

    unsigned int lh, rh;
    if(NULL == root)
        return true;
    if(isBalanced(root->left) && isBalanced(root->right))
    {
        lh = TreeHight(root->left);
        rh = TreeHight(root->right);
        if(lh > rh) 
        {
            if(lh - rh <= 1)
                return true;
        }
        else
        {
            if(rh - lh <= 1)
                return true;
        }
    }
        
    return false;    
}




int main()
{
    return 0;
}
