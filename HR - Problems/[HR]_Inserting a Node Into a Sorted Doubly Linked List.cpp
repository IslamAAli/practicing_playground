

// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    DoublyLinkedListNode* it = head;
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    DoublyLinkedListNode* prev = it->prev;
    bool done = false;
    while(it != NULL && !done)
    {
        prev = it->prev;
        if (data <= it->data )
        {
            newNode->next = it;
            
            if (prev != NULL)
            {
                prev->next = newNode; 
            }
            else
            {
                head = newNode;
                newNode->prev = prev;
            }

            it->prev = newNode; 
            done = true;
        }
        it = it->next;
    }

    if (!done)
    {
        prev->next->next = newNode;
        newNode->prev = prev->next;
    }
    

    return head; 
}

