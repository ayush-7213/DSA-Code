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
    if(head == NULL){
        return NULL;
    }

    ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) {
            return head; // Not enough nodes to reverse
        }


    //step1:reverse the first k group of nodes......
    ListNode* next=NULL;
    ListNode* curr=head;
    ListNode* prev=NULL;
    count =0;

    while(curr != NULL && count < k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    //recursion work again and again..
    if(next!=NULL){
        head->next=reverseKGroup(next,k);
    }
    return prev;
}
};