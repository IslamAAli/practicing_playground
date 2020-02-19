

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* itr1 = head1;
    SinglyLinkedListNode* itr2 = head2;
    
    bool LS1Adv = true;

    while(itr1 != itr2)
    {
        while(itr1 != itr2)
        {
            if(itr2->next != NULL)
                itr2 = itr2->next;
            else
                break;
                
            if(itr1 == itr2)
                return itr1->data;
        }

        if (itr1->next != NULL)
        {
            itr1 = itr1->next;
            itr2 = head2;
        }
    }

    return itr1->data;
}

