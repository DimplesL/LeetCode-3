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

        /// ��������
        vector<ListNode*>::iterator it = lists.begin();
        while(it != lists.end())
        {
            if(*it == NULL)
            {
                lists.erase(it);
            }
            else
            {
                ++it;
            }
        }
        if(lists.size( ) == 0)
        {
            return NULL;
        }

        ListNode *head = NULL;
        ListNode *curr = NULL;
        //  ���ȹ���һ��С����
        //  ����������lists��ÿ������ĵ�һ��Ԫ����ɵ����н���һ����
        make_heap(lists.begin( ), lists.end( ), Comp( ));
        while(lists.size() > 0)
        {
#ifdef __tmain
            for(int i = 0; i < lists.size( ); i++)
            {
                cout <<"��" <<i <<"���������Ԫ��" <<lists[i]->val <<endl;
            }
#endif // __tmain

            //  �Ѷ���Ԫ�ؾ�����С��Ԫ��
            ListNode *smallNode = lists[0];
#ifdef __tmain
            std::cout <<"��С��Ԫ��" <<smallNode->val <<endl;
#endif // __tmain

            //  ��smallNode���뵽��������
            if(head == NULL)
            {
                curr = smallNode;
                head = smallNode;
            }
            else
            {
                curr->next = smallNode;
                curr = curr->next;
            }

            //  ����С��Ԫ�ص���


            //  BUG, ���ܼ򵥵�ʹ��pop����,
            //  ��Ϊ���ݽṹ������������
            //  �������ָ�뵯����, �ᶪʧ����������
            //  �����ڴ����Ľ��������ָ���ָ��
            //  ��˿�����ô����
            //  ����������Ȼ��Ԫ��ʱ, �����޸���Ԫ��ָ���ָ��
            //  ֻ�е���ǰ����������Ԫ��ʱ, ��ֱ�ӵ���

            //pop_heap�ѶѶ�Ԫ��ȡ�������ŵ������������vector��ĩβ����ԭ��ĩβԪ��ȥ�����
            pop_heap(lists.begin( ), lists.end( ), Comp( ));
            //  ��ʱsmallNode����������ĩβ
#ifdef __tmain
            cout <<bool(smallNode == lists[lists.size( ) - 1]) <<endl;
#endif // __tmain

            if(lists[lists.size( ) - 1]->next == NULL)       //  �����ǰ�����Ѿ�û������Ԫ������ô����ֱ�ӵ���
            {

                lists.pop_back( );               //  ��Ϊָ�뵯�����൱�ڰ������������lists��ɾ��
            }
            else            //  ��ǰ��СԪ�����ڵ�������������Ԫ�أ� �����޸���Ԫ�ص�ָ��
            {
                //  ʹ�ö���ָ���޸���ָ�����ֱ����list[0]�޸�
                //ListNode **node = &lists[0];
                //*node = (*node)->next;
                lists[lists.size( ) - 1] = lists[lists.size( ) - 1]->next;

                push_heap(lists.begin( ), lists.end( ), Comp( ));

            }


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
