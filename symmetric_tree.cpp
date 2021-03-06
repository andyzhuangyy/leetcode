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





bool isSymmetric(TreeNode *root) {
   deque<TreeNode*> left, right;

   TreeNode* leftN, *rightN;
   if (NULL == root)
       return true;

   //if (NULL == root->left && NULL == root->right)
       //return true;
   //else if(NULL == root->left || NULL == root->right)
       //return false;

   left.push_back(root->left);
   right.push_back(root->right);

   for ( ; !left.empty() && !right.empty(); ) {
      leftN = left.front();
      rightN = right.front();
      left.pop_front();
      right.pop_front();

      if (NULL == leftN && NULL == rightN) {
          //left.push_back(NULL);
          //left.push_back(NULL);
          //right.push_back(NULL);
          //right.push_back(NULL);
          continue;
      }
      else if(NULL == leftN || NULL == rightN)
          return false;
      else if (leftN->val != rightN->val)
          return false;

      left.push_back(leftN->left);
      left.push_back(leftN->right);

      right.push_back(rightN->right);
      right.push_back(rightN->left);
   }
   return true;
}


int main()
{
    return 0;
}
