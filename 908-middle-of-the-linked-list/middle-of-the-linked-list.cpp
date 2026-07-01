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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        int mid;
        if(head == nullptr || head -> next == nullptr)
        {
            return head;
        }
        ListNode* temp = head;
        while(temp != nullptr)
        { 
            length++;
            temp = temp -> next;
        }
        if(length % 2 != 0)
        {
            mid = (length+1)/2;
        }
        else if(length %2 == 0)
        {
            mid  = (length/2) + 1;
        }

        int k = 0;
        ListNode* temp1 = head;
        while(k < mid-1)
        {
            temp1 = temp1 -> next;
            k++;
        }
        head = temp1;
        return head;
        


    }
};