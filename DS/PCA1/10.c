#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create (insert at end)
void create(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete from end
void delete_end()
{
    if (head == NULL)
        return;

    struct node *temp = head, *prev;

    if (temp->next == head)
    {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void display()
{
    if (head == NULL)
        return;

    struct node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

int main()
{
    create(10);
    create(20);
    create(30);

    display();

    delete_end();
    display();

    return 0;
}