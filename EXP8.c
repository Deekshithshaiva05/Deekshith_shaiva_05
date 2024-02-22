#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create();
void insert_front();
void insert_rear();
void display();
void delete_front();
void delete_rear();
int count=0;
struct node
{
    char dept[20],name[50],desg[10];
    int ssn;
    float sal;
    unsigned long long int phno;
    struct node *llink,*rlink;

};
struct node *first=NULL,*last=NULL,*temp=NULL,*p;
void main()
{
    int ch,n,i;
    while(1)
    {
        printf("1.create DLL \n2.insert at front\n 3.insert at rear\n 4.display\n 5.delete at front\n 6.delete atrear\n 7.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter the no. of Employees \n");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            insert_front();
                break;
            case 2: insert_front();
                break;
            case 3:insert_rear();
                break;
            case 4:display();
                break;
            case 5:delete_front();
                break;
            case 6:delete_rear();
                break;
            case 7:exit(0);
                default: printf("invalid choice\n");
                break;
        }
    }
}
void create()
{
    int ssn;
    char name[50],dept[20],desg[20];
    float sal;
    unsigned long long int phno;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->llink=temp->rlink=NULL;
    printf("enter ssn,name,dept,desg,salaryand phno\n");
    scanf("%d%s%s%s%f%llu",&ssn,name,dept,desg,&sal,&phno);
    temp->ssn=ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg,desg);
    temp->sal=sal;
    temp->phno=phno;
    count++;
}
void insert_front()
{
    if(first==NULL)
    {
        create();
        first=temp;
        last=temp;
    }
    else
    {
        create();
        temp->rlink=first;
        first->llink=temp;
        first=temp;
    }
}
void insert_rear()
{
    if(first==NULL)
    {
        create();
        first=temp;
        last=temp;
    }
    else
    {
        create();
        last->rlink=temp;
        temp->llink=last;
        temp->rlink=NULL;
        first=temp;
    }
}
void display()
{
    struct node *p;
    if(first==NULL)
    {
            printf("list is empty\n");
    }
    else
    {
        p=first;
        printf("content of list is\n");
        while(p!=NULL)
        {
            printf("%d\t%s\t%s\t%s\t%f\t%llu\n",p->ssn,p->name,p->dept,p->desg,p->sal,p->phno);
            p=p->rlink;
        }
        printf("total no.of employees %d\n",count);
    }
}
void delete_front()
{
    struct node *p;
    p=first;
    if(first==NULL)
    {
        printf("list is empty\n");
    }
    else if(p->rlink==NULL)
    {
        printf("%d\t%s\t%s\t%s\t%f\t%llu\n",p->ssn,p->name,p->dept,p->desg,p->sal,p->phno);
        free(p);
        first=NULL;
        count--;
    }
    else
    {
        first=p->rlink;
        printf("deleted node is %d\t%s\t%s\t%s\t%f\t%llu\n",p->ssn,p->name,p->dept,p->desg,p->sal,p->phno);
        free(p);
        count--;
    }
}
void delete_rear()
{
    struct node *p;
    p=first;
    if(first==NULL)
    {
        printf("list is empty\n");
    }
    else if(p->rlink==NULL)
{
    printf("%d\t%s\t%s\t%s\t%f\t%llu\n",p->ssn,p->name,p->dept,p->desg,p->sal,p->phno); 
    free(p);
    first=NULL;
    count--;
}
else
{
    p=last;
    last=p->llink;
    printf("%d\t%s\t%s\t%s\t%f\t%llu\n",p->ssn,p->name,p->dept,p->desg,p->sal,p->phno);
    free(p);
    last->rlink=NULL;
    count--;
}
}


