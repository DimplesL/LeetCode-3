#链接
------- 

>LeetCode题目：https://leetcode.com/problems/merge-two-sorted-lists
>
>GitHub代码：https://github.com/gatieme/LeetCode
>
>CSDN题解：http://blog.csdn.net/gatieme/article/details/51094742

#题意
-------

>Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

>

>Subscribe to see which companies asked this question


合并两个排序好的链表

#分析
-------
简单题，只要对两个链表中的元素进行比较，然后移动即可，只要对链表的增删操作熟悉，几分钟就可以写出来，代码如下：
·
```c
#include <iostream>

using namespace std;

#define __tmain main



#ifdef __tmain
struct ListNode
{
public :
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
#endif // __tmain

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right)
    {
        if(left == NULL && right == NULL)       //  两个链表均为空
        {
            return NULL;
        }
        else if(left != NULL && right == NULL)  //  left不为空, right为空
        {
            return left;
        }
        else if(left == NULL && right != NULL)  //  left为空, right不为空
        {
            return right;
        }

        //  先生成头结点
        ListNode *head = NULL;
        if(left->val < right->val)
        {
            head = left;
            left = left->next;
            //cout <<left->val <<"in list" <<endl;
        }
        else
        {
            head = right;
            right = right->next;
            //cout <<right->val <<"in list" <<endl;
        }

        //  遍历两个链表
        ListNode *curr = head;
        while(left != NULL && right != NULL)
        {
            //  每次找到一个小的加入新的链表
            //cout <<"left = " <<left->val <<", right = " <<right->val <<endl;
            if(left->val < right->val)
            {
                //cout <<left->val <<"in list" <<endl;

                curr->next = left;
                curr = curr->next;

                left = left->next;
            }
            else
            {
                //cout <<right->val <<"in list" <<endl;

                curr->next = right;
                curr = curr->next;

                right = right->next;
            }
        }

        //  处理较长链表的剩余部分
        if(left != NULL)
        {
            curr->next = left;
        }
        else
        {
            curr->next = right;
        }

        return head;
    }
};


int __tmain( )
{
    ListNode left, right[3];

    left.val = 5;
    left.next = NULL;

    right[0].val = 1;
    right[0].next = &right[1];
    right[1].val = 2;
    right[1].next = &right[2];
    right[2].val = 4;
    right[2].next = NULL;


    Solution solu;
    ListNode *head = solu.mergeTwoLists(&left, right);
    while(head != NULL)
    {
        cout <<head->val;
        head = head->next;
    }

}

```




