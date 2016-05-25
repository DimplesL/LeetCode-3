#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

struct ListNode
{
public :
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
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

class Comp
{
 public:
    bool operator() (const ListNode* left, const ListNode* right) const
    {
        return (left->val > right->val);
    }
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int length = lists.size();
        if (length == 0)
            return NULL;
        while (lists.size() >1)
        {
            ListNode* p1 = lists.front ();
            lists.erase(lists.begin());
            ListNode* p2 = lists.front();
            lists.erase(lists.begin());
            lists.push_back(mergeTwoLists(p1, p2));
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right)
    {
        if(left == NULL && right == NULL)       //  ���������Ϊ��
        {
            return NULL;
        }
        else if(left != NULL && right == NULL)  //  left��Ϊ��, rightΪ��
        {
            return left;
        }
        else if(left == NULL && right != NULL)  //  leftΪ��, right��Ϊ��
        {
            return right;
        }

        //  ������ͷ���
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

        //  ������������
        ListNode *curr = head;
        while(left != NULL && right != NULL)
        {
            //  ÿ���ҵ�һ��С�ļ����µ�����
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

        //  ����ϳ������ʣ�ಿ��
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
    ListNode list1[2];
    list1[0].val = -1;
    list1[0].next = &list1[1];
    list1[1].val = 1;
    list1[1].next = NULL;

    ListNode list2[3];
    list2[0].val = -3;
    list2[0].next = &list2[1];
    list2[1].val = 1;
    list2[1].next = &list2[2];
    list2[2].val = 4;
    list2[2].next = NULL;

    ListNode list3[4];
    list3[0].val = -2;
    list3[0].next = &list3[1];
    list3[1].val = -1;
    list3[1].next = &list3[2];
    list3[2].val = 0;
    list3[2].next = &list3[3];
    list3[3].val = 2;
    list3[3].next = NULL;

    vector<ListNode *> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution solu;
    ListNode *head = solu.mergeKLists(lists);
    while(head != NULL)
    {
        cout <<" "<<head->val;
        head = head->next;
    }

    return 0;
}
