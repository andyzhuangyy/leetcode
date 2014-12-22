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

bool isSameTree(TreeNode *p, TreeNode *q) {
   deque<TreeNode*> left, right;
   TreeNode* leftN, *rightN;

   left.push_back(p);
   right.push_back(q);

   for ( ; !left.empty() && !right.empty(); ) {
      leftN = left.front();
      rightN = right.front();
      left.pop_front();
      right.pop_front();

      if (NULL == leftN && NULL == rightN) {
          continue;
      }
      else if(NULL == leftN || NULL == rightN)
          return false;
      else if (leftN->val != rightN->val)
          return false;

      left.push_back(leftN->left);
      left.push_back(leftN->right);

      right.push_back(rightN->left);
      right.push_back(rightN->right);
   }
   return true;
    
}





int main()
{
    return 0;
}
