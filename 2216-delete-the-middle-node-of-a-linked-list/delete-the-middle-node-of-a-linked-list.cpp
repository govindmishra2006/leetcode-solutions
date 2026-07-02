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
    ListNode* deleteMiddle(ListNode* head) {
        int length = 1;
        int mid;
        if(head == nullptr || head ->next == nullptr)
        {
            return nullptr;
        }
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
            length++;
        }
        if(length % 2 != 0)
        {
            mid = (length - 1)/2;
        }
        else
        {
            mid = (length)/2;
        }
        ListNode* temp0 = head;
        ListNode* temp1 = head->next;
        int k = 0;
        while(k < mid-1)
        {
            temp0 = temp0 ->next;
            temp1 = temp1->next;
            k++;
        }
        temp0 ->next = temp1 -> next;
        return head;
        
        
    }
};