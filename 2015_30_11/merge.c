#include<stdio.h>
#include<malloc.h>

struct node
{
    int element;
    struct node* next;
};
typedef struct node Node;

Node* newNode(int ele)
{
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->element = ele;
    newnode->next = NULL;
    return(newnode);
}

void addNewElement(Node** newnode, int ele)
{
    Node* temp = *newnode;
    if(*newnode == NULL)
    {
        (*newnode) = newNode(ele);
        (*newnode)->next = NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = (Node*) malloc(sizeof(Node));
        temp->next->element = ele;
        temp->next->next = NULL;
    }
}
Node* mergeLinkedLists(Node* head1, Node* head2)
{
    Node* result = NULL;
    while(head1 != NULL && head2 !=NULL )
    {
        if(head1->element<head2->element)
        {
            addNewElement(&result,head1->element);
            head1 = head1->next;
        }
        else
        {
            addNewElement(&result,head2->element);
            head2 = head2->next;
        }
    }
    while(head1 != NULL)
    {
        addNewElement(&result,head1->element);
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        addNewElement(&result,head2->element);
        head2 = head2->next;
    }
    return(result);
}
main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    //Node* result = NULL;
    addNewElement(&head1,21);
    addNewElement(&head1,23);
    addNewElement(&head1,65);
    addNewElement(&head2,42);
    addNewElement(&head2,49);
    addNewElement(&head2,65);
    Node* result = mergeLinkedLists(head1,head2);

   /* while(head1!=NULL)
    {
        printf("%d ",head1->element);
        head1 = head1->next;
    }
    puts("");

    while(head2!=NULL)
    {
        printf("%d ",head2->element);
        head2 = head2->next;
    }
    puts("");*/

    while(result!=NULL)
    {
        printf("%d ",result->element);
        result = result->next;
    }
    puts("");
}
