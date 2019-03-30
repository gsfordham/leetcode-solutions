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
        ListNode *result = NULL;
        ListNode *iter = NULL;
        bool carry = false;
        int current = 0;
        
        //If at least 1 list is not empty
        while (l1 != NULL || l2 != NULL || carry) {
            //If carry is set, add 1 to current value
            current = (carry ?  1 : 0);
            carry = false; //Reset carry
            
            //Add the values from each current
            //node iterator to the current value
            current += this->cval(l1);
            current += this->cval(l2);
            
            //If current exceeds 9, set carry flag
            carry = (current > 9);
            current %= 10; //Modulo 10 to get remainder
            
            /* Create a new ListNode from the values
             * and set iterator value.
             * 
             * If the result is null, set result to
             * iter, and make iter the first ListNode.
             */
            ListNode *n = new ListNode(current);
            if (result == NULL) { //First ListNode
                result = iter = n;
            } else {
                iter->next = n; //Set next node
                iter = iter->next; //Iterate
            }
        }
        
        return result; //Return the new list
    }
    
    /* Accept a ListNode by reference,
     * and change its value to its next,
     * if it is not yet null.
     * 
     * If it is not null, take the current
     * ListNode's value and return it. Else,
     * return 0.
     */
    int cval(ListNode *&cnode) {
        int out = 0; //Set return value
        //Only change anything, if the passed
        //list is no yet null
        if (cnode != NULL) {
            out += cnode->val;
            cnode = cnode->next;
        }
        return out;
    }
};
