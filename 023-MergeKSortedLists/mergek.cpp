#include <iostream>
#include <vector>

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
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode *head = NULL;
        ListNode *curr = NULL;
        ListNode maxNode(INT_MAX);

        while(lists.size() > 0)
        {
            //  Ѱ�ҵ�ǰ��С���Ǹ�������
            ListNode *smallNode = &maxNode;
            int smallIndex = -1;
            for(int i = 0; i < lists.size(); i++)
            {
                ListNode *indexNode = lists[i];
                if(indexNode == NULL)       //  ��ǰ�����Ѿ���������
                {
#ifdef __tmain
                    std::cout <<"��i�������Ѿ�����" <<endl;
#endif
                }
                else if(indexNode->val < smallNode->val)    //  ��ǰ�ڵ�ȵ�ǰ��С��ҪС
                {
                    //  ������С�Ľڵ����С�ڵ��λ��
                    smallNode = indexNode;
                    smallIndex = i;
                }
            }
            if(smallIndex == -1)
            {
#ifdef __tmain
                cout <<"�����Ѿ�ΪNULL" <<endl;
#endif
                break;
            }
            else
            {
#ifdef __tmain
                cout <<"��С�Ľ��λ��" <<smallIndex <<", ֵΪ" <<smallNode->val <<endl;
#endif

            }

            //  ѭ��������, ��С�ڵ�λ�ڵ�i�������smallNodeλ��
            //  �������뵽������,ͬʱ��Ҫ���������ָ�������һλ


            //  ��smallNode���뵽��������
            if(curr == NULL)
            {
                curr = smallNode;
                head = smallNode;
            }
            else
            {
                curr->next = smallNode;
                curr = curr->next;
            }

            //  ��smallNode��ָ�������ָ�����һλ
            ListNode **node = &lists[smallIndex];       //  Ҫ�޸�ָ���ָ����Ҫָ���ָ��
            *node = (*node)->next;
        }

        return head;

    }
};



int __tmain( )
{
    ListNode list1[2];
    list1[0].val = 1;
    list1[0].next = &list1[1];
    list1[1].val = 3;
    list1[1].next = NULL;

    ListNode list2[3];
    list2[0].val = 2;
    list2[0].next = &list2[1];
    list2[1].val = 4;
    list2[1].next = &list2[2];

    list2[2].val = 5;
    list2[2].next = NULL;


    vector<ListNode *> lists;
    lists.push_back(list1);
    lists.push_back(list2);

    Solution solu;
    ListNode *head = solu.mergeKLists(lists);
    while(head != NULL)
    {
        cout <<" "<<head->val;
        head = head->next;
    }

    return 0;
}
