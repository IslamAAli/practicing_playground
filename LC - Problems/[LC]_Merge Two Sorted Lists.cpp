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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        else if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else
        {
            ListNode* res;
            ListNode* res_Itr;
            ListNode* l1_Itr;
            ListNode* l2_Itr;
            
            if (l1->val < l2->val)
            {
                res = l1;
                l1_Itr = l1->next;
                l2_Itr = l2;
            }
            else
            {
                res = l2;
                l1_Itr = l1;
                l2_Itr = l2->next;
            }
            res_Itr = res;
            
            // start the logic of alternation
            while (! (l1_Itr == NULL && l2_Itr == NULL))
            {
                if (l1_Itr == NULL)
                {
                    // deal with l2 only
                    res_Itr-> next = l2_Itr;
                    res_Itr = res_Itr->next;
                    l2_Itr = l2_Itr->next;
                }
                else if (l2_Itr == NULL)
                {
                    // deal with l1 only
                    res_Itr-> next = l1_Itr;
                    res_Itr = res_Itr->next;
                    l1_Itr = l1_Itr->next;
                }
                else
                {
                    // both have elements
                    if (l1_Itr->val < l2_Itr->val)
                    {
                        res_Itr-> next = l1_Itr;
                        l1_Itr = l1_Itr->next;
                    }
                    else
                    {
                        res_Itr-> next = l2_Itr;
                        l2_Itr = l2_Itr->next;
                    }
                    res_Itr = res_Itr->next;
                }
            }
            
            return res;
        }
    }
};