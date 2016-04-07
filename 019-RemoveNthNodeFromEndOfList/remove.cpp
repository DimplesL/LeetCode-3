#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define __tmain main


#ifdef __tmain

struct ListNode
{
public :
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {};
};

#endif // __tmain

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first = head;
        ListNode *second = head;
        int i;

        //  �սڵ�����
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }

        //  firstָ������N��
        for(i = 0; i < n && first != NULL; i++)
        {
            first = first->next;
        }

        if(first == NULL && i < n)      //  ��㳤�Ȳ���
        {
            return head;
        }
        else if(first == NULL && i == n)
        {
            //cout <<"�ҵ���β��" <<endl;
            // ������N�����������ͷ���
            second = head;
            delete second;
            head = head->next;
            return head;
        }

        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        //  ��ʱsecond���ǵڵ���N+1�����
        //  ��������N���ڵ��ǰһ�����

        //  ����ɾ����N�����
        ListNode *p = second->next;
        second->next = p->next;
        delete p;
        return head;

    }
};

int __tmain()
{
    ListNode list[2];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = NULL;

    Solution solu;
    solu.removeNthFromEnd(list, 2);
    return 0;
}
