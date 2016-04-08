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
