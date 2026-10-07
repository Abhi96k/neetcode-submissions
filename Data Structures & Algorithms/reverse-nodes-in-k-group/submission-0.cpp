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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head == nullptr || k == 1) {
            return head;
        }


        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;

        while (true) {
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *groupEnd = prevGroupEnd;
            
            for (int i = 0; i < k ; ++i) {
                if(groupEnd!=nullptr){
                    groupEnd = groupEnd->next;
                }
                
            }
            if (groupEnd == nullptr) {
                break; 
            }
            
            ListNode *nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;

            ListNode *prev = nullptr;
            ListNode *curr = groupStart;

            while (curr != nullptr) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = prev;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        ListNode *newHead = dummy->next;
        delete dummy;  
        return newHead;
    }
};
