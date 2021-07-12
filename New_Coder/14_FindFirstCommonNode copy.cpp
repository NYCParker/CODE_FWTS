//找到链表的第一个公共节点

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

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *ps = NULL;
        ListNode *ptemp;

        int flag = 0;
        ptemp = pHead1;

        while (pHead2 != NULL)
        {
            //复位phead1；
            pHead1 = ptemp;

            while (pHead1 != NULL)
            {
                if (pHead1->val == pHead2->val)
                {
                    if (flag == 0)
                    {
                        ps = pHead1;
                    }
                    pHead1 = pHead1->next;
                    pHead2 = pHead2->next;
                    flag++;
                }
                else
                {
                    if (flag > 0)
                    {
                        //说明第一个公共结点结束，把pHead1自身指向NULL
                        pHead1 = NULL;
                    }

                    pHead1 = pHead1->next;
                    ;
                }
            }

            if (flag == 0)
            {
                pHead2 = pHead2->next;
            }
        }

        return ps;
    }
};


//看下牛客解法
//对题目的理解出现了偏差 虽然我的代码能通过
//他这里的公共节点意思不仅仅是值一样 两个链表直接汇集到了一个公共节点,简化一下原代码
//两个循环 空间复杂度有点高
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *ps = NULL;
        ListNode *ptemp;

        int flag = 0;
        ptemp = pHead1;

        while (pHead2 != NULL)
        {
            //复位phead1；
            if(flag == 1)
            {
                break;
            }
            pHead1 = ptemp;

            while (pHead1 != NULL)
            {
                if (pHead1->val == pHead2->val)
                {
                    ps = pHead1;
                    flag = 1;
                    break;
                }
                else
                {
                    pHead1 = pHead1->next;
                }
            }
            pHead2 = pHead2->next;

        }

        return ps;
    }
};

//牛客网提供了一个双指针法思路
//补全更短的那个链表 然后就可以从头开始 一起移动了
//复杂度好一点
