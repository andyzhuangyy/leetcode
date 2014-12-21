// 层序遍历
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

vector<vector<int> > levelOrder(TreeNode *root) {
    std::deque<TreeNode*> q, lastq;
    vector<vector<int> > ret;
    vector<int> curArr;
    TreeNode* currNode = NULL;

    if(NULL == root)
        return ret;

    q.push_back(root);
    
    for ( ; !q.empty(); ) {
        curArr.clear();
        lastq.clear();
        
        while(!q.empty()){
            currNode = q.front();
            q.pop_front();
            
            curArr.push_back(currNode->val);

            if(NULL != currNode->left)
                lastq.push_back(currNode->left);
            if(NULL != currNode->right)
                lastq.push_back(currNode->right);
        }

        ret.push_back(curArr);
        q.swap(lastq);
    }
        
    return ret;
    
}


int main()
{
    return 0;
}
