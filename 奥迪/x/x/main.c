
#include<stdio.h>
#include<stdlib.h>
struct node{
    int date;
    struct node* next;
};
int main()
{
    struct node* list=(struct node*)malloc(sizeof(struct node));
    list->date=0x7fffffff;
    list->next=NULL;
    int k;
    scanf("%d",&k);
    int date;
    while(scanf("%d",&date)!=EOF&&date>=0)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->date=date;
        newnode->next=NULL;
        newnode->next=list->next;
        list->next=newnode;
    }
    int count=1;
    struct node* p=list->next;
    while(p!=NULL)
    {
        if(count==k)
            break;
        count++;
        p=p->next;
    }
    if(p!=NULL)
        printf("%d",p->date);
    else
        printf("NULL");
}
