//二叉树的递归思想

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */

class Solution
{
public:
    TreeNode *Mirror(TreeNode *pRoot)
    {
        TreeNode *ptemp;

        if (pRoot == NULL)
        {
            return NULL;
        }

        ptemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = ptemp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
        
        return pRoot;
    }
};