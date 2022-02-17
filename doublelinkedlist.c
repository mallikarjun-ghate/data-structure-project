#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};
struct Node *first = NULL, *temp, *new, *prev;
void insertAtStart();
void insertAtEnd();
void deleteAtStart();
void deleteAtEnd();
void display();
int main()
{
    int choice, insertChoice, deleteChoice;
    while (1)
    {
        printf("\n1:Insert \n2:Delete\n3:Display List\n4:Exit");
        printf("\nEnter Your Choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n1:Insert At Start\n2:Insert At End\n3:Exit");
            printf("\nEnter Your Choice");
            scanf("%d", &insertChoice);
            switch (insertChoice)
            {
            case 1:
                insertAtStart();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice !!");
            }

            break;
        case 2:
            printf("\n1:Delete From Start\n2:Delete From End\n3:Exit");
            printf("\nEnter Your Choice");
            scanf("%d", &deleteChoice);
            switch (deleteChoice)
            {
            case 1:
                deleteAtStart();
                break;
            case 2:
                deleteAtEnd();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice !!");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice ???");
            break;
        }
    }

    return 0;
}
void insertAtStart()
{
    temp = first;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data: ");
    scanf("%d", &new->info);

    if (first == NULL)
    {
        new->lptr = NULL;
        new->rptr = NULL;
        first = new;
    }
    else
    {
        new->rptr = temp;
        new->lptr = NULL;
        first = new;
    }
}
void insertAtEnd()
{
    temp = first;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data: ");
    scanf("%d", &new->info);

    if (first == NULL)
    {
        new->lptr = NULL;
        new->rptr = NULL;
        first = new;
    }
    else
    {
        while (temp->rptr != NULL)
        {
            temp = temp->rptr;
        }
        temp->rptr = new;
        new->lptr = temp;
        new->rptr = NULL;
    }
}

void deleteAtStart()
{
    if (first == NULL)
    {
        printf("\nEmpty List");
    }
    else if (first->rptr == NULL)
    {
        printf("\nDeleted Element :%d", first->info);
        first = NULL;
        free(first);
    }

    else
    {
        temp = first;
        first = first->rptr;
        first->lptr = NULL;
        printf("\nDeleted Element :%d", temp->info);
        free(temp);
    }
}
void deleteAtEnd()
{
    if (first == NULL)
    {
        printf("\nEmpty List");
    }
    else if (first->rptr == NULL)
    {
        printf("\nDeleted Element :%d", first->info);
        first = NULL;
        free(first);
    }

    else
    {
        temp = first;
        while (temp->rptr != NULL)
        {
            temp = temp->rptr;
        }
        temp->lptr->rptr = NULL;
        printf("\nDeleted Element :%d", temp->info);
        free(temp);
    }
}

void display()
{
    temp = first;
    if (first == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n");
        while (temp != NULL)
        {
            printf("%d->", temp->info);
            temp = temp->rptr;
        }
    }
}