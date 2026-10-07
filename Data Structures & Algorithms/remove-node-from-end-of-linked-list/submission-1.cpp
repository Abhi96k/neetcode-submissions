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
        if (head == NULL) {
            return head;
        }

 
        int count = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }

        int ith = count - n;

   
        if (ith == 0) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }

   
        ListNode *prev = head;
        for (int i = 1; i < ith; i++) {
            prev = prev->next;
        }

      
        ListNode *nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
        delete nodeToRemove; 

        return head;
    }
};
