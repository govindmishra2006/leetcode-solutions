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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int length = 0;
        while(temp != nullptr)
        {
            length++;
            temp = temp -> next;
        }
        k = k%length;
        if(k==0)
        {
            return head;
        }
        int indexToNull = length - k - 1 ;
        ListNode* temp1 = head;
        int i = 0;
        while(i < indexToNull)
        {
            temp1 = temp1->next;
            i++;
        }
        ListNode* temp2 = temp1 -> next;
        ListNode* temp3 = temp2;
        temp1->next = nullptr;
        while(temp3->next != nullptr)
        {
            temp3 = temp3 -> next;
        }
        temp3 ->next = head;
        head = temp2;   
        return head;
    }   
};