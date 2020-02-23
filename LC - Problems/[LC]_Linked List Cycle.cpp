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
    bool hasCycle(ListNode *head) {
        vector<ListNode*> pointers;
        vector<ListNode*>::iterator vecItr;
        
        ListNode* itr = head;
        while (itr != NULL)
        {
            if (find(pointers.begin(), pointers.end(), itr) != pointers.end())
                return true;
            else
                pointers.push_back(itr);
            itr = itr->next;
        }
        return false;
    }
};