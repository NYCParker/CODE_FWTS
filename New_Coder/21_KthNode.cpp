//二叉树第k小
//= =感觉用的方法很呆
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
    //遍历二叉树，把val值存进数组
    TreeNode *x;
    vector<int> vecm;
    int flag = 0;
    int min;

    int treemin(TreeNode *pRoot)
    {
        if (flag == 1)
        {
            if (pRoot->val == min)
            {
                x = pRoot;
            }
        }

        if (pRoot->left != NULL)
        {
            vecm.push_back(treemin(pRoot->left));
        }

        if (pRoot->right != NULL)
        {
            vecm.push_back(treemin(pRoot->right));
        }

        return pRoot->val;
    }

    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL)
        {
            return NULL;
        }

        vecm.push_back(treemin(pRoot));
        sort(vecm.begin(), vecm.end());
        flag = 1;
        min = vecm[k - 1];
        treemin(pRoot);

        return x;
    }
};

//看一下别的版本
//现在有更简单的遍历二叉树版本
//替换上面的 就好了
class Solution
{
public:
    //遍历二叉树，把val值存进数组(从上往下 从左往右 原来貌似是从底往上从左往右)
    vector<int> vecm;
    TreeNode *x;
    int min;
    int flag = 0;

    void doss(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return;
        }

        if (flag == 1)
        {
            if (pRoot->val == min)
            {
                x = pRoot;
            }
        }

        if (flag == 0)
        {
            vecm.push_back(pRoot->val);
        }

        doss(pRoot->left);
        doss(pRoot->right);
    }

    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL)
        {
            return NULL;
        }

        doss(pRoot);
        sort(vecm.begin(), vecm.end());
        flag = 1;
        min = vecm[k - 1];
        doss(pRoot);
        return x;
    }
};