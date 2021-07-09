//从头遍历链表，一直在找next for 的中止条件设置为pln = NULL 而不是 pln->next = NULL 不然会少遍历一个链表节点
//reverse(v.begin(),v.end()); 反转vector

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// class Solution
// {
// public:
//     vector<int> printListFromTailToHead(ListNode *head)
//     {
//         vector<int> v, vrev;
//         ListNode *pln;
//         vector<int>::iterator ivec;

//         if (head == NULL)
//         {
//             return v;
//         }

//         for (pln = head; pln->next != NULL; pln = pln->next)
//         {
//             v.push_back(pln->val);
//         }
//         v.push_back(pln->val);

//         //反转vector
//         for (ivec = v.end() - 1; ivec != v.begin(); ivec--)
//         {
//             vrev.push_back(*ivec);
//         }
//         vrev.push_back(*ivec);

//         return vrev;
//     }
// };

//效率更高的办法 看答案改进   //其实用reverse算法貌似效率不高= = 而且刷题不推荐 不如上面的
class Solution2
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> v;

        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        reverse(v.begin(), v.end());

        return v;
    }
};
