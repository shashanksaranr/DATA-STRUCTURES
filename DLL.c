#include <stdio.h>
#include<stdlib.h>

void insert_begin();
void insert_end();
void display();
void delete_begin();
void delete_end();

struct node
{
    char id[20];
    char name[20];
    char branch[20];
    char spl[20];
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;

int main()
{
 int choice;
        do
        {
                printf("\n...........MENU..........\n");
                printf("\n 1.Insert at the beginning:\n");
                printf("\n 2.Insert at the end:\n");
                printf("\n 3.Display:\n");
                printf("\n 4.Delete from beginning:\n");
                printf("\n 5.Delete from the end:\n");
                printf("\n 6.Exit\n");
                printf("Enter your choice:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        
                        case 1: insert_begin();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: display();
                                break;
                        case 4: delete_begin();
                                break;
                        case 5: delete_end();
                                break;
                        case 6: exit(0);
                                break;

                        default: printf("INVALID CHOICE\n");
                                 return 0;
                }
        }while(1);
}

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("\nDetails of the Professor:\n");
            printf("Name:%s\n",ptr->name);
            printf("ID:%d\n",&ptr->id);
            printf("Branch:%s\n",ptr->branch);
            printf("Specialization: %s\n",ptr->spl);
            ptr=ptr->next;
        }
    }
}

void insert_begin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Space\n");
        return;
    }

    printf("\nEnter the details of the professor:\n");
    printf("Enter the Professor's Name:\n");
    scanf("%s",temp->name);
    printf("Enter the Professor's ID:\n");
    scanf("%d",temp->id);
    printf("Enter the Professor's Branch:\n");
    scanf("%s",temp->branch);
    printf("Enter the Professor's Specialization:\n");
    scanf("%s",temp->spl);
    temp->next = NULL;

    if(start==NULL)
        start=temp;

    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
}

void insert_end()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
         printf("Insufficient Space\n");
        return;
    }
    
    printf("\nEnter the details of the professor:\n");
    printf("Enter the Professor's Name:\n");
    scanf("%s",&temp->name);
    printf("Enter the Professor's ID:\n");
    scanf("%d",&temp->id);
    printf("Enter the Professor's Branch:\n");
    scanf("%s",&temp->branch);
    printf("Enter the Professor's Specialization:\n");
    scanf("%s",&temp->spl);
    temp->next = NULL;

    if(start==NULL)
    {
        start=temp;
    }

    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
}

void delete_begin()
{
    struct node *ptr;

    if(ptr==NULL)
    {
        printf("List Empty!\n");
        return;
    }

    else
    {
        ptr=start;
        start=start->next;
        printf("Professor %s Data deleted\n",ptr->name);
        free(ptr);
    }   
}

void delete_end()
{
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("List Empty!\n");
        exit(0);
    }

    else if(start->next=NULL)
    {
        ptr=start;
        start=NULL;
        printf("Professor %s Data deleted\n",ptr->name);
        free(ptr);
    }

    else
    {
        ptr=start;
        while (ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next->ptr=NULL;

        printf("Professor %s Data deleted\n:",ptr->name);
        free(ptr);
    }
}