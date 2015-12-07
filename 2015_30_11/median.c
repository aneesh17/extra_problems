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
float medianOfLinkedList(struct node* head)
{
    struct node* temp = head;
    int numOfNodes = 0,counter;
    float result;
    while(temp->next != NULL)
    {
        numOfNodes++;
        temp = temp->next;
    }
    counter = (numOfNodes)/2;

    while(counter>0)
    {
        head = head->next;
        counter--;
    }
    result=(numOfNodes%2==1)?((head->element+head->next->    element)/2.0):(head->element);
    return(result);
}

main()
{
    Node* head = NULL;
    addNewElement(&head,1);
    addNewElement(&head,2);
    addNewElement(&head,3);
    addNewElement(&head,4);
    addNewElement(&head,5);
    printf("Median = %.1f",medianOfLinkedList(head));
}
