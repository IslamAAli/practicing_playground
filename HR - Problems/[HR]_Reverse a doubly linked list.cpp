

// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {

    if (head == NULL)
        return head;
    
    DoublyLinkedListNode* itrNode = head; 
    DoublyLinkedListNode* prvNode = NULL;

    // find last node
    bool done = false; 
    while(!done)
    {
        if (itrNode->next == NULL)
        {
            done = true;
            head = itrNode;
        }
        else
        {
            itrNode = itrNode->next;
        }
    }

    done = false; 
    while (!done)
    {
        prvNode= itrNode->prev;
        itrNode->prev = itrNode->next;
        itrNode->next = prvNode;
        
        if (itrNode->next == NULL)
        {
            done = true;
        }
        else
        {
            itrNode = itrNode->next;
        }
        
    }

    return head; 
}

