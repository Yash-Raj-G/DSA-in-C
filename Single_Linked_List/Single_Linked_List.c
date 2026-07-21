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
void fdelete()
{
    node *tmp;
    if(start==NULL)
        printf("\nEmpty");
    else
    {
        tmp=start;
        start=start->next;
        free(tmp);
        printf("\nFirst Node Deleted...");
    }
}
void ldelete()
{
    node *tmp,*tmp1;
    tmp=start;
    if(start==NULL)
    printf("\nEmpty");
    else if(tmp->next==NULL)
    {
        start=NULL;
        free(tmp);
        printf("\nLast Node Deleted...");
    }
    else
    {
        while(tmp->next->next!=NULL)
            tmp=tmp->next;
        tmp1=tmp->next;
        tmp->next=NULL;
        free(tmp1);
        printf("\nLast Node Deleted...");
    }
}
void apdelete()
{
    node *tmp,*tmp1; int pos,count=0,i;
    tmp1=start;
    if(start==NULL)
    printf("\nEmpty");
    else
    {
        while(tmp1!=NULL)
        {
            count++;
            tmp1=tmp1->next;
        }
        printf("\nEnter Position:");
        scanf("%d",&pos);
        if(pos<1||pos>count)
        printf("\nInvalid Position");
        else 
        {
            if(pos==1)
            {
            tmp1=start;
            start=start->next;
            free(tmp1); printf("\nNode Deleted...");
            }
            else
            {
                tmp1=start;
                for(i=1;i<pos-1;i++)
                    tmp1=tmp1->next;
                tmp=tmp1->next;
                tmp1->next=tmp->next;
                free(tmp);
                printf("\nNode Deleted...");
            }
        }
    }
}
void sum()
{
    node *tmp; int s=0;
    tmp=start;
    if(tmp==NULL)
        printf("\nEmpty");
    else
    {
        while(tmp!=NULL)
        {
            s+=tmp->data;
            tmp=tmp->next;
        }
        printf("\nSum :%d",s);
    }
}
void alternate()
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
            if(tmp->next==NULL)
            tmp=tmp->next;
            else
            tmp=tmp->next->next;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1->Create Single Linked List\n2->Display Linked List\n3->Insert Node At First Position\n4->Insert Node At Last Position\n5->Count Nodes\n6->Insert Node At Any Position\n7->Delete First Node\n8->Delete Last Node\n9->Delete Node At Any Position\n10->Sum of Node Elements\n11->Print Alternate Nodes\n12->Exit\nEnter Choice:");
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
        fdelete();
        else if(choice==8)
        ldelete();
        else if(choice==9)
        apdelete();
        else if(choice==10)
        sum();
        else if(choice==11)
        alternate();
        else if(choice==12)
        return 0;
        else
        printf("\nEnter valid choice");
    }
    return 0;
}


