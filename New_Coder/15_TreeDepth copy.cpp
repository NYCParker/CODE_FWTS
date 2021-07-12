//二叉树深度

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    int TreeDepth(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return 0;
        }

        int rtal = TreeDepth(pRoot->left);
        int ltal = TreeDepth(pRoot->right);
        
        return max(rtal,ltal)+1;
    }
};
