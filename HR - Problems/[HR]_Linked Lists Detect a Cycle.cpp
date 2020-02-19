/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    
    // early stop in case of empty list
    if (head == NULL)
        return false;
    
    Node** visited = new Node*[100];
    
    Node* itr = head;
    int visited_count = 0 ;
    while(itr != NULL)
    {
        // check if visited before
        for (int i=0; i<visited_count; i++)
        {
            if (visited[i] == itr)
                return true;
        }
        
        // add to visited list
        visited[visited_count] = itr;
        
        // increment the counter
        itr = itr->next;
        visited_count ++; 
    }
    
    
    return false;
}