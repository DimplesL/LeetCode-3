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

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // ʹ�ö�����,
        // 1. ѡ��ÿ�������ͷ������С�����У�
        // 2. �ٰѶѶ�����ϲ������У�
        // 3. ��ѡ����ָ������ټ���С������,�ص�2
        // 4. �����������Ϊ��ʱ�����غϲ������ͷָ��
        if(lists.empty()) return nullptr;
        vector<ListNode* > heap;
        // 1. ѡ��ÿ�������ͷ������С�����У�
        for(int i = 0; i != lists.size(); i ++)
        {
            if(lists[i])
            {
                heap.push_back(lists[i]);
            }
        }
        makeHeap(heap);
        // 2. �ٰѶѶ�����ϲ������У�
        ListNode head(-1); // �ϲ�����ı�ͷ
        ListNode* p = &head;
        while(!heap.empty())
        {
            auto minNode = popHeap(heap);
            p->next = minNode; // ��������
            p = p->next;
            // 3. ��ѡ����ָ������ټ���С������,�ص�2
            auto next = minNode->next;
            if(next) pushHeap(heap, next);
        }
        // 4. �����������Ϊ��ʱ�����غϲ������ͷָ��
        return head.next;
    }

    // ����С����
    // �Ե�����
    void makeHeap(vector<ListNode*> &heap){
        // �����һ��Ԫ�صĸ��ڵ㿪ʼ����С����
        for(int i = heap.size()/2; i >0 ; i --)
        {
            minHeap(heap, i);
        }
    }
    // ����С����,�Ե�i��Ԫ��Ϊ������С����
    //λ�ô�1��ʼ��ȡԪ��ʱ�ǵ�-1
    // �Զ�����
    void minHeap(vector<ListNode*> &heap, int i){
        int l = i*2;
        int r = l+1;
        int least(i);
        // �����СԪ�ص�λ��
        if((l< heap.size()+1) && heap[l-1]->val<heap[i-1]->val )
        {
            // ���û�г����߽粢�����ӱȸ���С����
            least = l;
        }
        if(r<heap.size()+1 && heap[r-1]->val<heap[least-1]->val)
        {
            // ���û�г����߽粢���Һ�����С����
            least = r;
        }
        if(least != i)
        {
            swap(heap[i-1], heap[least-1]);
            minHeap(heap, least);
        }
    }
    // ��С�����в���һ��Ԫ��
    // �Ե�����
    void pushHeap(vector<ListNode*> &heap, ListNode* p)
    {
        heap.push_back(p);
        int child = heap.size();
        int parent = child/2;
        for(int child = heap.size(),parent = child/2; parent; child--, parent = child/2)
        {
            if(heap[child-1]->val < heap[parent-1]->val)
                {
                swap(heap[child-1], heap[parent-1]);
            }
        }
    }
    // �����Ѷ�
    ListNode* popHeap(vector<ListNode*> &heap)
    {
        swap(heap[0], heap[heap.size()-1]);
        auto p = heap.back();
        heap.pop_back();
        minHeap(heap, 1);
        return p;
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
