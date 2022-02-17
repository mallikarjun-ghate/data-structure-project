//Copy is remaining
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *first = NULL, *temp, *new, *prev;

void insertAtStart();
void insertAtMiddle();
void insertAtEnd();
void deleteAtStart();
void deleteAtMiddle();
void deleteAtEnd();
void countNodes();
void display();

int main()
{

    int choice, insertChoice, deleteChoice;
    while (1)
    {
        printf("\n1:Insert \n2:Delete\n3:Display List\n4:Count Nodes\n5:Exit");
        printf("\nEnter Your Choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n1:Insert At Start\n2:Insert At Middle\n3:Insert At End\n4:Exit");
            printf("\nEnter Your Choice");
            scanf("%d", &insertChoice);
            switch (insertChoice)
            {
            case 1:
                insertAtStart();
                break;
            case 2:
                insertAtMiddle();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice !!");
            }

            break;
        case 2:
            printf("\n1:Delete From Start\n2:Delete From Middle\n3:Delete From End\n4:Exit");
            printf("\nEnter Your Choice");
            scanf("%d", &deleteChoice);
            switch (deleteChoice)
            {
            case 1:
                deleteAtStart();
                break;
            case 2:
                deleteAtMiddle();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice !!");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            countNodes();
            break;
        case 5:
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

    int input;
    printf("\nEnter the info to Insert at start");
    scanf("%d", &input);
    new = (struct Node *)malloc(sizeof(struct Node));
    new->info = input;

    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }

    else
    {
        new->link = first;
        first = new;
    }
}
void insertAtMiddle()
{
    int input;
    printf("\nEnter the info to Insert at Middle");
    scanf("%d", &input);
    new = (struct Node *)malloc(sizeof(struct Node));
    new->info = input;

    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }
    else
    {
        if (new->info <= first->info)
        {
            new->link = first;
            first = new;
        }
        else
        {
            temp = first;
            while (temp->link != NULL && (temp->link->info) <= (new->info))
            {
                temp = temp->link;
            }
            new->link = temp->link;
            temp->link = new;
        }
    }
}

void insertAtEnd()
{
    int input;
    printf("\nEnter the info to Insert at End");
    scanf("%d", &input);
    new = (struct Node *)malloc(sizeof(struct Node));
    new->info = input;

    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }
    else
    {
        temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new;
        new->link = NULL;
    }
}

void display()
{
    if (first == NULL)
    {
        printf("\nUnderflow !!");
    }

    else
    {
        temp = first;

        while (temp != NULL)
        {
            printf("%d->", temp->info);
            temp = temp->link;
        }
    }
}

void deleteAtStart()
{
    if (first == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        temp = first;
        first = temp->link;
        printf("\nDeleted Element :%d", temp->info);
        free(temp);
    }
}
void deleteAtMiddle()
{
    int input;
    if (first == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        temp = first;
        printf("Enter the Element Data to Delete From List :\n");
        scanf("%d", &input);
        while (temp != NULL && (temp->info != input))
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("\nElement not Found\n");
        }
        else
        {
            prev->link = temp->link;
            printf("\nDeleted Element :%d", temp->info);
            free(temp);
        }
    }
}
void deleteAtEnd()
{
    temp = first;
    if (first == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        if (temp->link == NULL)
        {
            printf("\nDeleted Element :%d", first->info);
            free(temp);
            first = NULL;
        }
        temp = first;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        printf("\nDeleted Element :%d", temp->info);
        prev->link = NULL;
        free(temp);
    }
}

void countNodes()
{
    int count=0;
    temp=first;
    while (temp!=NULL)
    {
        temp=temp->link;
        count++;
    }
    printf("\n No on nodes : %d\n",count);
}
