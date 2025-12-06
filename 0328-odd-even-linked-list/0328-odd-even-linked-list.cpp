class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;              // pointer for odd index nodes
        ListNode* even = head->next;       // pointer for even index nodes
        ListNode* evenHead = even;         // store start of even list

        while (even && even->next) {
            odd->next = even->next;        // link next odd
            odd = odd->next;

            even->next = odd->next;        // link next even
            even = even->next;
        }

        odd->next = evenHead;              // concatenate odd list + even list
        return head;
    }
};
