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


bool is_palindrome(const vector<int > &v, const vector<bool> &vb)
{
    int i, j;

    if(0 == v.size())
        return true;

    for(i = 0, j = v.size() - 1; i < j; )
    {
        if(v[i] != v[j] && vb[i] != vb[j])
            return false;
        ++i; --j; 
    }
    return true;
}



bool isSymmetric(TreeNode *root) {
    std::deque<TreeNode*> q, lastq;
    vector<vector<int> > ret;
    vector<int> curArr;
    vector<bool> vb;
    TreeNode* currNode = NULL;

    if(NULL == root)
        return true;


    q.push_back(root);
    
    for ( ; !q.empty(); ) {
        curArr.clear();
        lastq.clear();
        vb.clear();
        bool allNull = true;
        while(!q.empty()){
            currNode = q.front();
            q.pop_front();
            
            if(NULL != currNode)
            {
                curArr.push_back(currNode->val);
                vb.push_back(true);
                lastq.push_back(currNode->left);
                lastq.push_back(currNode->right);
                allNull = false;
            }
            else
            {
                curArr.push_back(0);
                vb.push_back(false);
                lastq.push_back(NULL);
                lastq.push_back(NULL);
            }

        }

        
        if (!is_palindrome(curArr, vb))
            return false;
        
        if(allNull)
            break;
        q.swap(lastq);
    }
    return true;
    
}


int main()
{
    return 0;
}
