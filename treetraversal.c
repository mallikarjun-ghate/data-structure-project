#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *lptr;
    struct node *rptr;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
    struct node *a, *b, *c, *d, *e, *f, *g, *t;

    a = (struct node *)malloc(sizeof(struct node *));
    b = (struct node *)malloc(sizeof(struct node *));
    c = (struct node *)malloc(sizeof(struct node *));
    d = (struct node *)malloc(sizeof(struct node *));
    e = (struct node *)malloc(sizeof(struct node *));
    f = (struct node *)malloc(sizeof(struct node *));
    g = (struct node *)malloc(sizeof(struct node *));
    t = a;
    a->data = 'A';
    a->lptr = b;
    a->rptr = d;

    b->data = 'B';
    b->lptr = c;
    b->rptr = NULL;

    c->data = 'C';
    c->lptr = NULL;
    c->rptr = NULL;

    d->data = 'D';
    d->lptr = e;
    d->rptr = g;

    e->data = 'E';
    e->lptr = NULL;
    e->rptr = f;

    f->data = 'F';
    f->lptr = NULL;
    f->rptr = NULL;

    g->data = 'G';
    g->lptr = NULL;
    g->rptr = NULL;

    printf("PreOrder Tree Is:\n");
    preorder(t);
    printf("\nInOrder Tree IS\n");
    inorder(t);
    printf("\nPostOrder Tree IS\n");
    postorder(t);
}

void preorder(struct node *tree)
{
    if (tree == NULL)
    {
        printf("\nEmpty tree");
    }
    else
    {
        printf("%c", tree->data);
        if (tree->lptr != NULL)
        {
            preorder(tree->lptr);
        }

        if (tree->rptr != NULL)
        {
            preorder(tree->rptr);
        }
    }
}

void postorder(struct node *tree)
{
    if (tree == NULL)
    {
        printf("\nEmpty tree");
    }
    else
    {

        if (tree->lptr != NULL)
        {
            postorder(tree->lptr);
        }
        if (tree->rptr != NULL)
        {
            postorder(tree->rptr);
        }
        printf("%c", tree->data);
    }
}