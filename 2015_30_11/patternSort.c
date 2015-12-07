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
Node* reverse(Node* head,Node* newnode)
{
    if(newnode->next == NULL)
    {
        return newnode;
    }
    head = reverse(head,newnode->next);
    Node* tempNode = newnode->next;
    tempNode->next = newnode;
    newnode->next = NULL;
    return(head);
}

void patternSort(Node* head)
{
    int counter = 0;
    while(head->next->next != NULL)
    {
        //printf("%d",++counter);
        if(head->next->element > head->next->next->element)
        {
            head->next = reverse(head->next,head->next);
        }
        head = head->next;
    }
}

main()
{
    Node* head = NULL;
    addNewElement(&head,1);
    addNewElement(&head,2);
    addNewElement(&head,7);
    addNewElement(&head,20);
    addNewElement(&head,15);
    addNewElement(&head,10);

    patternSort(head);
    while(head!=NULL)
    {
        printf("%d ",head->element);
        head = head->next;
    }
}

