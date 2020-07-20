/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        while(head && head->val == val)
        {
            ListNode* p = head;
            head = head->next;
            delete p;
        }
        ListNode* p = head;
        while(p && p->next)
        {
            if(p->next->val == val)
            {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
            {
                p=p->next;
            }
        }
        return head;
    }
};
