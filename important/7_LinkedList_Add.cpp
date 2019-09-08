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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         Storing the head of the result and the writer
        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        int carryOver = 0;
        int val1, val2;

        if(l1==NULL || l2==NULL)
        {
             return result->next;
        }

        while(!(l1==NULL && l2==NULL))
        {

            if(l1!=NULL)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            else val1=0;

            if(l2!=NULL)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            else val2=0;

            curr->next = new ListNode((val1+val2+carryOver)%10);
            carryOver = (val1+val2+carryOver>=10) ? 1 : 0;
            curr = curr->next;
        }

        if(carryOver==1)
        {
            curr->next = new ListNode(1);
        }

        return result->next;
    }
};
