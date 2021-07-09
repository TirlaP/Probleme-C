#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct Node
{
    int x;
    struct Node* next;
} Node;

void insert_end(Node** root, int value);
void insert_beginning(Node** root, int value);
void insert_after(Node* node, int value);
void insert_sorted(Node** root, int value);
void deallocate(Node** root);
void reverse(Node** root);
int has_loops(Node* root);
int count(Node* root);

int main()
{
    Node* root = NULL;
    /*
    Node* root = malloc(sizeof(Node));
    if(root == NULL)
    {
        exit(EXIT_FAILURE);
    }
    root->x = 15;
    root->next = NULL;
    */

    insert_sorted(&root, 3);
    insert_sorted(&root, 5);
    insert_sorted(&root, 4);
    insert_sorted(&root, 18);
    insert_sorted(&root, 7);


    for(Node* current = root; current != NULL; current = current->next)
    {
        printf("%d\n", current->x);
    }

    printf("Linked list has %d elements.\n", recursive_count(root));

    deallocate(&root);

    return 0;
}

void insert_end(Node** root, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("\nNu s-a putut face alocarea!");
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;

}

void insert_beginning(Node** root, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(3);
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_sorted(Node** root, int value)
{
    if (*root == NULL || (*root)->x >= value)
    {
        insert_beginning(root, value);
        return;
    }

    Node* current = *root;
    while(current->next != NULL)
    {
        if (current->next->x >= value)
        {
            break;
        }
        current = current->next;
    }
    insert_after(current, value);
}

void insert_after(Node* root, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(4);
    }
    new_node->x = value;
    new_node->next = root->next;
    root->next = new_node;
}

void remove_elemennt(Node** root, int value)
{
    if (*root == NULL)
    {
        return;
    }

    int ok;
    do
    {
        ok = 1;
        if ((*root)->x == value)
        {
            ok = 0;
            Node* to_remove = *root;
            *root = (*root)->next;
            free(to_remove);
        }
    }
    while(ok == 0);

    for (Node* current = *root; current->next != NULL; current = current->next)
    {
        do
        {
            ok = 1;
            if (current->next->x == value)
            {
                ok = 0;
                Node* to_remove = current->next;
                current->next = current->next->next;
                free(to_remove);
            }
        }
        while(ok == 0);
    }
}

void deallocate(Node** root)
{
    Node* curr = *root;
    while(curr != NULL)
    {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}

void reverse(Node** root)
{
    Node* prev = NULL;
    Node* curr = *root;

    while (curr != NULL)
    {
        Node* next = curr->next;

        curr -> next = prev;

        prev = curr;
        curr = next;
    }

    *root = prev;
}

int has_loops(Node* root)
{
    Node* slow = root;
    Node* fast = root;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int count(Node* root)
{
    int cnt = 0;
    for (Node* curr = root; curr != NULL; curr = curr->next)
    {
        cnt++;
    }
    return cnt;
}

int recursive_count(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + recursive_count(node->next);
}

