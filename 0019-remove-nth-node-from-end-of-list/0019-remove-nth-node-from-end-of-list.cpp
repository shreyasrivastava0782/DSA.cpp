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
          int len=0;

          ListNode* curr=head;
          while(curr){
            len++;
            curr=curr->next;
          }

           if(n == len){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }


          int pos=len-n-1;
          curr=head;

          while(pos--){
             curr=curr->next;
          }
          ListNode* temp=curr->next;

          curr->next=temp->next;
          delete temp;

          return head;


        
    }
};