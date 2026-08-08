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
void finsert();
void linsert();
void countnodes();
void apinsert();
void fdelete();
void ldelete();
void apdelete();
int main()
{
    int choice;
    while(1)
    {
    printf("\n1->Create\n2->Display\n3->First Insert\n4->Last Insert\n5->Count Nodes\n6->Any Position Insert\n7->First Delete\n8->Last Delete\n9->Any Position Delete\n10->Exit\nEnter Your Choice:");
    scanf("%d",&choice);
    if(choice==1)
    create();
    else if(choice==2)
    display();
    else if(choice==3)
    finsert();
    else if(choice==4)
    linsert();
    else if(choice==5)
    countnodes();
    else if(choice==6)
    apinsert();
    else if(choice==7)
    fdelete();
    else if(choice==8)
    ldelete();
    else if(choice==9)
    apdelete();
    else if(choice==10)
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
void finsert()
{
    node *tmp;
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
        tmp->next=head;
        head->prev=tmp;
        tmp->prev=NULL;
        head=tmp;
    }
    printf("\nNode Inserted...");
}
void linsert()
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
    printf("\nNode Inserted...");
}
void countnodes()
{
    node *tmp;
    int count=0;
    tmp=head;
    if(tmp==NULL)
    printf("\nEmpty");
    else
    {
        while(tmp!=NULL)
        {
            count++;
            tmp=tmp->next;
        }
        printf("\nTotal Nodes: %d",count);
    }
}
void apinsert()
{
    node *tmp,*tmp1;
    int pos,i=1,count=0;
    tmp=(node *)malloc(sizeof(node));
    printf("\nEnter Data:");
    scanf("%d",&tmp->data);
    printf("\nEnter Position:");
    scanf("%d",&pos);
    tmp1=head;
    while(tmp1!=NULL)
    {
        count++;
        tmp1=tmp1->next;
    }
    if(pos<1 || pos>count+1)
    printf("\nInvalid Pos");
    else if(pos==1)
    {
        tmp->next=head;
        tmp->prev=NULL;
        head->prev=tmp;
        head=tmp;
        printf("\nNode Inserted...");
    }
    else if(pos==count+1)
    {
        tmp1=head;
        while(tmp1->next!=NULL)
        tmp1=tmp1->next;
        tmp1->next=tmp;
        tmp->prev=tmp1;
        tmp->next=NULL;
        printf("\nNode Inserted...");
    }
    else
    {
        tmp1=head;
        while(i<pos-1)
        {
            tmp1=tmp1->next;
            i++;
        }
        tmp->next=tmp1->next;
        tmp->next->prev=tmp;
        tmp1->next=tmp;
        tmp->prev=tmp1;
        printf("\nNode Inserted...");
    }
}
void fdelete()
{
    node *tmp;
    if(head==NULL)
    printf("\nEmpty");
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nNode Deleted...");
    }
    else
    {
        tmp=head->next;
        tmp->prev=NULL;
        free(head);
        head=tmp;
        printf("\nNode Deleted...");    
    }
}
void ldelete()
{
    node *tmp;
    tmp=head;
    if(tmp==NULL)
    printf("\nEmpty");
    else
    {
        if(tmp->next==NULL)
        {
            head=NULL;
            free(tmp);
        }
        else
        {
            while(tmp->next!=NULL)
            tmp=tmp->next;
            tmp->prev->next=NULL;
            free(tmp);
        }
        printf("\nNode Deleted...");
    }
}
void apdelete()
{
    node *tmp,*tmp1;
    int pos,i=1,count=0;
    tmp=head;
    while(tmp!=NULL)
    {
        count++;
        tmp=tmp->next;
    }
    printf("\nEnter Position:");
    scanf("%d",&pos);
    if(pos<1 || pos>count)
    printf("\nInvalid Pos");
    else if(pos==1)
    {
        tmp=head;
        tmp1=tmp->next;
        tmp1->prev=NULL;
        free(tmp);
        head=tmp1;
        printf("\nNode Deleted...");
    }
    else if(pos==count)
    {
        tmp=head;
        while(tmp->next->next!=NULL)
        tmp=tmp->next;
        tmp1=tmp->next;
        tmp->next=NULL;
        free(tmp1);
        printf("\nNode Deleted...");
    }
    else
    {
        tmp=head;
        while(i<pos-1)
        {
            tmp=tmp->next;
            i++;
        }
        tmp1=tmp->next;
        tmp->next=tmp1->next;
        tmp1->next->prev=tmp;
        free(tmp1);
        printf("\nNode Deleted...");
    }
}
