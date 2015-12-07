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
Node* reverseLinkedList(Node* head,Node* newnode)
{
    if(newnode->next == NULL)
    {
        return newnode;
    }
    head = reverseLinkedList(head,newnode->next);
    Node* tempNode = newnode->next;
    tempNode->next = newnode;
    newnode->next = NULL;
    return(head);
}
main()
{
    Node* head = NULL;
    addNewElement(&head,1);
    addNewElement(&head,2);
    addNewElement(&head,3);
    addNewElement(&head,4);
    addNewElement(&head,5);
    addNewElement(&head,6);
    addNewElement(&head,7);
    addNewElement(&head,8);
    head = reverseLinkedList(head,head);
    while(head!=NULL)
    {
        printf("%d ",head->element);
        head = head->next;
    }
}
