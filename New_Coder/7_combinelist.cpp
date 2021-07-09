//合并两个排序的链表
//我的思路是一个链表不动只增加 一个只减少
//把删的链表往增的链表里填 

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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *pl;   //填组头指针
        ListNode *plt;  //删组头指针
        ListNode *plc;  //临时储存指针
        ListNode *plr;  //返回指针
        
        if(pHead1 == NULL)
        {
            return pHead2;
        }
        
        if(pHead2 == NULL)
        {
            return pHead1;
        }
        //谁的头节点小，以谁为基础插，如果一样就用第一个链表
        if (pHead2->val < pHead1->val)
        {
            pl = pHead2;
            plt = pHead1;
            plr = pHead2;
        }

        else
        {
            pl = pHead1;
            plt = pHead2;
            plr = pHead1;
        }

        while (plt != NULL)
        {
            if(pl->next == NULL)
            {
                //说明把plt剩下的直接插到pl->next即可 pl->next = plt
                pl->next = plt;
                break;
            }

            if (plt->val < pl->next->val || plt->val == pl->next->val)
            {
                //plt插到pl后面,更新pl和plt
                plc = plt->next;  
                plt->next = pl->next;
                pl->next = plt;

                pl = plt;
                plt = plc;
            }

            else
            {
                //pl右移
                pl = pl->next;
            }
        }


        return plr;
    }
};