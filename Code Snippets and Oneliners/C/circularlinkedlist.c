#include <stdio.h>
#include<stdlib.h>
typedef struct n
{
    int data;
    struct n *next;
} node;

void printlist(node *head){
    if(head==NULL) return;
    node *p;
    p=head;
    do{
        printf("%d ",p->data);
        p=p->next;
    } while(p!=head);

}

void insertbegin(node *head,int num){

    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=num;
    new->next=head->next;
    head->next=new;
    //swap head and new
    new->data=head->data;
    head->data=num;

}

void insertend(node *head,int num){
    node *temp3;
    temp3=(node*) malloc(sizeof(node));
    if(head==NULL){
        temp3->data=num;
        temp3->next=temp3;
        temp3=head;
    }
    else{
        node *walker;
        walker =head;
        while(walker->next!=head){
            walker=walker->next;
        }
        temp3->data=num;
        temp3->next=NULL;
        walker->next=temp3;
        temp3->next=head;
        
    }
    printlist(head);
}

void deletebegin(node** head){
    node* te=*head;
    node* temp3=*head;
    
    while(te->next!=*head){
        te=te->next;
    }
    te->next=(*head)->next;
    *head=(*head)->next;
    // free(temp3);
    printlist(*head);
}

int main()
{
    printf("Enter the length of the linked list:\n");
    int n;
    scanf("%d", &n);
    printf("Enter the element of circular linked list:\n");
    int x;
    scanf("%d", &x);
    node *newnode, *head,*temp;
    newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
    }
    head = newnode;
    temp=newnode;
    for (int i = 1; i < n; i++)
    {
        printf("Enter the element of circular linked list:");
        int x;
        scanf("%d", &x);
        newnode = (node *)malloc(sizeof(node));
        if (newnode != NULL)
        {
            newnode->data = x;
            newnode->next = NULL;
            temp->next=newnode;
            temp=temp->next;
        }
    }
    temp->next=head;
    printlist(head);
    printf("\nEnter the element to be inserted at the beginning: \n");
    scanf("%d",&x);
    insertbegin(head,x);
    printlist(head);
    printf("\n");
    printf("Enter the element to be inserted at the end: \n");
    scanf("%d",&x);
    
    insertend(head,x); 
    
    printf("\n");
    
    printf("Deletion at the beginning\n");
    deletebegin(&head);
    
    printf("\n");

    return 0;
}