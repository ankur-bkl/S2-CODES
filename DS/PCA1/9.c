#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Create node at end
void create(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Search element
void search(int key)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element Not Found\n");
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    create(10);
    create(20);
    create(30);

    display();
    search(20);

    return 0;
}