#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Delete at beginning
void delete_begin()
{
    if (head == NULL)
        return;

    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete at end
void delete_end()
{
    if (head == NULL)
        return;

    struct node *temp = head, *prev;

    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete specific element
void delete_value(int val)
{
    struct node *temp = head, *prev;

    if (temp != NULL && temp->data == val)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Sample data
    head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = malloc(sizeof(struct node));
    head->next->data = 20;
    head->next->next = NULL;

    delete_begin();
    delete_end();
    delete_value(20);

    display();
    return 0;
}