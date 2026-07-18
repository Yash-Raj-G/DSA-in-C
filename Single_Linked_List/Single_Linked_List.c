#include<stdio.h>
#include<stdlib.h>
struct slist
{
    int data;
    struct slist *next;
}*start=NULL;
typedef struct slist node;
void create()
{
    node *tmp,*tmp1;
    tmp=(node *)malloc(sizeof(node));
    tmp->next=NULL;
    printf("\nEnter Data:");
    scanf("%d",&tmp->data);
    if(start==NULL)
    start=tmp;
    else
    {
        tmp1=start;
        while(tmp1->next!=NULL)
        tmp1=tmp1->next;
        tmp1->next=tmp;
    }
}
void display()
{
    node *tmp;
    tmp=start;
    if(tmp==NULL)
    printf("\nEmpty");
    else
    {
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
    tmp->next=start;
    start=tmp;
    printf("\nEnter Value For First Node:");
    scanf("%d",&tmp->data);
    printf("\nInsertion Completed...");
}
void linsert()
{
    node *tmp,*tmp1;
    tmp=(node *)malloc(sizeof(node));
    tmp->next=NULL;
    printf("\nEnter Value For Last Node:");
    scanf("%d",&tmp->data);
    if(start==NULL)
    {
        start=tmp;
        printf("\nLast Insertion Completed...");
    }
    else
    {
        tmp1=start;
        while(tmp1->next!=NULL)
        tmp1=tmp1->next;
        tmp1->next=tmp;
        printf("\nLast Insertion Completed...");
    }

}
void count()
{
    node *tmp;
    int c=0;
    tmp=start;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->next;
    }
    printf("\nTotal Nodes:%d",c);
}
void apinsert()
{
    node *tmp,*tmp1; int pos,count=0,i;
    tmp1=start;
    while(tmp1!=NULL)
    {
        count++;
        tmp1=tmp1->next;
    }
    printf("\nEnter Position:");
    scanf("%d",&pos);
    if(pos<1 || pos>count+1)
        printf("\nInvalid Position");
    else 
    {
        tmp=(node *)malloc(sizeof(node));
        printf("\nEnter Value For Node:");
        scanf("%d",&tmp->data);
        if(pos==1)
        {
            tmp->next=start;
            start=tmp; printf("\nInsertion Completed...");
        }
        else
        {
            tmp1=start;
            for(i=1;i<pos-1;i++)
                tmp1=tmp1->next;
            tmp->next=tmp1->next;
            tmp1->next=tmp;
            printf("\nInsertion Completed...");
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1->Create Single Linked List\n2->Display Linked List\n3->Insert Node At First Position\n4->Insert Node At Last Position\n5->Count Nodes\n6->Insert Node At Any Position\n7->Exit\nEnter Choice:");
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
        count();
        else if(choice==6)
        apinsert();
        else if(choice==7)
        break;
        else
        printf("\nEnter valid choice");
    }
    return 0;
}


