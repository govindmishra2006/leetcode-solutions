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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        if(head == nullptr || head -> next == nullptr)
        {
            return false;
        }
        int j =0;
        while(j <= 10000 && temp->next != nullptr)
        {
            temp = temp -> next;
            j++;
        }
        if(temp -> next == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
};