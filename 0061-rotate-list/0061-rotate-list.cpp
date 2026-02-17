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
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* temp=head, dummy;
        int n=0;

        while(temp){
            n++;
            temp=temp->next;
        }

        k=k%n;
        if(k==0)
            return head;

        n=n-k-1;
        temp=head;

        while(n--){
            temp=temp->next;
        }

        dummy.next=temp->next;
        temp->next=NULL;

        temp=dummy.next;
        while(temp->next){
            temp=temp->next;
        }

        temp->next=head;

        return dummy.next;
    }
};