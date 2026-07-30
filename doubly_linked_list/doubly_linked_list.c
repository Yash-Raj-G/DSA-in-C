#include<stdio.h>
#include<stdlib.h>
struct dlist 
{
    int data;
    struct dlist *next;
    struct dlist *prev;
}*head = NULL;
typedef struct dlist node;
void create();
void display();
int main()
{
    int choice;
    while(1)
    {
    printf("\n1->Create\n2->Display\n3->Exit\nEnter Your Choice:");
    scanf("%d",&choice);
    if(choice==1)
    create();
    else if(choice==2)
    display();
    else if(choice==3)
    break;
    else
    printf("\nInvalid Choice");
    }
    return 0;
}
void create()
{
    node *tmp,*tmp1;
    tmp=(node *)malloc(sizeof(node));
    printf("\nEnter Data:");
    scanf("%d",&tmp->data);
    if(head==NULL)
    {
        tmp->next=NULL;
        tmp->prev=NULL;
        head=tmp;
    }
    else
    {
        tmp1=head;
        while(tmp1->next!=NULL)
        tmp1=tmp1->next;
        tmp1->next=tmp;
        tmp->prev=tmp1;
        tmp->next=NULL;
    }
    printf("\nNode Created");
}
void display()
{
    node *tmp;
    tmp=head;
    if(tmp==NULL)
    printf("\nEmpty");
    else
    {
        printf("\nThe List is:");
        while(tmp!=NULL)
        {
            printf("\n%d",tmp->data);
            tmp=tmp->next;
        }
    }
}
