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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 1;
        if(head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        while(temp->next != nullptr)
        {
            length++;
            temp = temp->next;
        }
        int nthfromstart = length - n;
        if(length == n)
        {
            return head->next;
        }
        ListNode* temp0 = head;
        ListNode* temp1 = temp0->next;
        int k = 0;

        while(k < nthfromstart - 1)
        {
            temp0 = temp0->next;
            temp1 = temp1 -> next;
            k++;
        }
        temp0->next = temp1->next;
        return head;

    }
};