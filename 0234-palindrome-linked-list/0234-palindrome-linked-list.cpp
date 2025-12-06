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

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=NULL;
        ListNode* curr=slow;

        while(curr){
            ListNode* fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }

        ListNode *reversed=prev;
        ListNode* original=head;

        while(reversed){
            if(original->val != reversed->val)   return false;
                
                original=original->next;
                reversed=reversed->next;
        }

        return true;
    }
};