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
        
        int reminder = 0; 
        int sum = l1->val + l2->val;
        if (sum > 9)
        {
            reminder = 1;
            sum = sum - 10;
        }
        
        ListNode* resList= new ListNode(sum);
        ListNode* res_itr = resList;
        
        ListNode* l1_itr = l1->next;
        ListNode* l2_itr = l2->next;
        
        while (l1_itr != NULL || l2_itr != NULL)
        {
            int tmpVal = 0 ;
            if (l1_itr == NULL) 
            {
                tmpVal = l2_itr->val + reminder;
                if (tmpVal > 9)
                {
                    reminder = tmpVal/(int)10;
                    tmpVal = tmpVal - 10; 
                }
                else
                {
                    reminder = 0 ;
                }
            }
            else if (l2_itr == NULL)
            {
                tmpVal = l1_itr->val + reminder;
                if (tmpVal > 9)
                {
                    reminder = tmpVal/(int)10;
                    tmpVal = tmpVal - 10; 
                }
                else
                {
                    reminder = 0 ;
                }
            }
            else
            {
                tmpVal = l1_itr->val + l2_itr->val + reminder;
                if (tmpVal > 9)
                {
                    reminder = tmpVal/(int)10;
                    tmpVal = tmpVal - 10; 
                }
                else
                {
                    reminder = 0 ;
                }
            }
            ListNode* tmpNode = new ListNode(tmpVal);
            res_itr->next = tmpNode;
            res_itr = tmpNode;
            
            if (l1_itr != NULL)
                l1_itr = l1_itr->next;
            
            if (l2_itr != NULL)
                l2_itr = l2_itr->next;
        }
        
        if (reminder != 0)
        {
            ListNode* tmpNode = new ListNode(reminder);
            res_itr->next = tmpNode;
            res_itr = tmpNode;
        }
        
        return resList;
    }
};