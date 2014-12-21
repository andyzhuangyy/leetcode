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

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    std::deque<TreeNode*> q, lastq;
    vector<vector<int> > ret;
    vector<vector<int> > tmpArr;
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

        tmpArr.push_back(curArr);
        //ret.push_back(curArr);
        q.swap(lastq);
    }

    while (!tmpArr.empty()){
        ret.push_back(tmpArr.back());
        tmpArr.pop_back();
    }
    return ret;
    
}


