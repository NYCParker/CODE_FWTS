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

// class Solution
// {
// public:
//     int TreeDepth_Max(TreeNode *pRoot)
//     {
//         if (pRoot == NULL)
//         {
//             return 0;
//         }

//         int rtal = TreeDepth_Max(pRoot->left);
//         int ltal = TreeDepth_Max(pRoot->right);

//         return max(rtal, ltal) + 1;
//     }

//     int TreeDepth_Min(TreeNode *pRoot)
//     {
//         static int depth = 0;
//         if (pRoot == NULL)
//         {
//             return 0;
//         }
//         int i = TreeDepth_Min(pRoot->left);
//         int j = TreeDepth_Min(pRoot->right);

//         return min(i, j) + 1;
//     }

//     bool IsBalanced_Solution(TreeNode *pRoot)
//     {
//         if (pRoot == NULL)
//         {
//             return true;
//         }

//         else
//         {
//             int k = TreeDepth_Max(pRoot);
//             int kk = TreeDepth_Min(pRoot);
//             if(k-kk<2)
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
// };

class Solution
{
public:
    int flag = 0;

    int TreeDepth_Max(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return 0;
        }

        int rtal = TreeDepth_Max(pRoot->left);
        int ltal = TreeDepth_Max(pRoot->right);

        if (rtal - ltal > 1 || rtal - ltal < -1)
        {
            flag = 1;
        }

        return max(rtal, ltal) + 1;
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        TreeDepth_Max(pRoot);
        
        if(flag == 1)
        {
            return false;
        }
        return true;
    }
};