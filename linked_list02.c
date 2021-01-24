#include <stdio.h>
#include <stdlib.h>

// Define a node struct - base elements of a linked list
typedef struct node
{
    int number;         // variables storing values
    struct node *next;  // pointer indicates the address of the next node
}
node;

int main(void)
{
    // Define a node pointer, which name is 'list'. It indicates the first node of the linked list
    node *list = NULL;  // initiate null (because is is indicating nothing now)

    // Allocate memories for a new node, and indicate by pointer *n
    node *n = malloc(sizeof(node));
    if (n == NULL)  //if the pointer(adress) is null, it means the list had over or there's some problem with memory
    {
        return 1;
    }


    // Store 1 to the 'number' field of n
    n->number = 1;   // same as : (*n).number
    // Initialize
    n->next = NULL;

    // Make list pointer indicate n
    list = n;   // null to *n


    // Link a new node
    // Allocate memories
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    // Store
    n->number = 2;
    n->next = NULL;

    // Make list pointer indicate a new node
    list->next = n;


    // Repeat for node3
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    // Now, list is indicating the 1st node, and the 1st node is linked to the 2nd node.
    // So, to link another node(3rd one), the next of the list is going to be n pointer(the next next node).
    list->next->next = n;

    // Print
    for(node *tmp = list; tmp!=NULL ;tmp = tmp->next)
    {
        printf("%i\n",tmp->number);
    }

    // Freeing memories
    while(list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
