#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} no;


int main()
{
    int n;
    int index;
    no *head, *last;
    head = NULL;
    last = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    int i, data;
    int data3;
    no *newNode;
    if (n >= 1)
    {
        head = (no *)malloc(sizeof(no));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (no *)malloc(sizeof(no));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }
    }
    no *temp;
    temp = head;
    while (temp->next != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
    // insertion at the begining
    no *new;
    new = (no *)malloc(sizeof(no));
    int data1;
    printf("Enter the value of data for new node:");
    scanf("%d", &data1);
    new->data = data1;
    new->prev = NULL;
    new->next = head;
    head->prev = new;
    head = new;
    no *temp1;
    temp1 = head;
    printf("Insertion at front :");
    while (temp1->next != 0)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("%d ", temp1->data);
    printf("\n");
    // insertion at end
    no *new1;
    new1 = (no *)malloc(sizeof(no));
    int data2;
    printf("Enter the value of data for new node:");
    scanf("%d", &data2);
    new1->data = data2;
    new1->next = NULL;
    new1->prev = last;
    last->next = new1;
    no *temp2;
    temp2 = head;
    printf("Insertion at end :");
    while (temp2->next != 0)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
    printf("%d ", temp2->data);
    printf("\nEnter the data to be inserted :");
    scanf("%d",&data3);
    printf("Enter the position :");
    scanf("%d",&index);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *cur = head;
    ptr->data = data3;
    i = 0;
    no *temp3;
    temp3=head;
    while (i != index - 1)
    {
        cur = cur->next;
        i++;
    }
    
    ptr->prev = cur;
    ptr->next = cur->next;
    cur->next->prev = ptr;
    cur->next = ptr;
    while (temp3->next != 0)
    {
        printf("%d ", temp3->data);
        temp3 = temp3->next;
    }
    printf("%d ", temp2->data);
    return 0;
}


