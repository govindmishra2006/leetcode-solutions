/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* t0 = head;
        ListNode* t1 = t0->next;
        ListNode* evenHead = t1;
        ListNode* t2 = t1->next;
        ListNode* t3 = (t2 != nullptr) ? t2->next : nullptr;

        while(t2 != nullptr || t3 != nullptr)
        {
            if(t2 != nullptr)
            {
                t0 ->next = t2;
                t0 = t0 ->next;
                if(t2 ->next != nullptr)
                {
                    t2 = t2 ->next->next;
                }
                else{
                    t2 = nullptr;
                }
            }
            if(t3 != nullptr)
            {
                t1 ->next = t3;
                t1 = t1 ->next;
                if(t3 ->next != nullptr)
                {
                    t3 = t3 ->next->next;
                }
                else{
                    t3 = nullptr;
                }
            }
        }
        t0->next = evenHead;
        t1->next = nullptr;
        return head;
    }
};