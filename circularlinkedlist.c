#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
};

struct node* traversal(struct node*);
struct node* insert_front(struct node*,int);
struct node* insert_end(struct node *, int);
struct node* insert_middle(struct node *,int,int);

int main()
{
struct node *first = malloc(sizeof(struct node));
struct node *second = malloc(sizeof(struct node));
struct node *third = malloc(sizeof(struct node));
struct node *fourth = malloc(sizeof(struct node));

first->data = 10;
first->link = second;

second->data = 20;
second->link = third;

third->data = 30;
third->link = fourth;

fourth->data = 40;
fourth->link = first;

printf("\nbefore inserting: ");
traversal(first);

printf("\nafter inserting at front: ");
first = insert_front(first,9);
traversal(first);

printf("\nafter inserting at end: ");
first = insert_end(first,50);
traversal(first);

printf("\nafter insert at middle: ");
first = insert_middle(first,25,4);
traversal(first);
}

struct node* traversal(struct node* first)
{
struct node *ptr = first;
printf("%d, ",ptr->data);
ptr = ptr->link;

while(ptr!= first)
{
printf("%d, ",ptr->data);
ptr = ptr->link;
}
}

struct node* insert_front(struct node *first, int data)
{
struct node *ptr = malloc(sizeof(struct node));
ptr->data = data;

struct node *temp = first->link;
while(temp->link !=first)
{
temp=temp->link;
}
temp->link = ptr;
ptr->link = first;
first = ptr;
return first;
}


struct node* insert_end(struct node *first, int data)
{
struct node *ptr = malloc(sizeof(struct node));
ptr->data = data;

struct node *temp = first->link;
while(temp->link !=first)
{
temp=temp->link;
}
temp->link = ptr;
ptr->link = first;
ptr = first;
return first;
}

struct node* insert_middle(struct node *first, int data,int p)
{
struct node *t=first;
struct node *ptr = malloc(sizeof(struct node));
ptr->data = data;
int i=1;

while(i!=p-1)
{
t = t->link;
i++;
}
ptr->link=t->link;
t->link=ptr;
return first;
}
