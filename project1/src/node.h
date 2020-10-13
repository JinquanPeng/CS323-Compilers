#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char name[30];
    struct Node *next;
    struct Node *children;
    int line_no;
    int type;
    char type_name[30];
} Node;

Node *create_node(char *name, char *type_name, int line_no, int type)
{
    // create a new node and set to 0
    Node *new_node = (Node *)malloc(sizeof(Node));

    strncpy(new_node->name, name, 30);
    strncpy(new_node->type_name, type_name, 30);
    new_node->line_no = line_no;
    new_node->next = NULL;
    new_node->children = NULL;
    new_node->type = type;

    return new_node;
}

void insert_node(Node *parent, Node *child)
{
    if (parent->children == NULL)
    {
        parent->children = child;
    }
    else
    {
        Node *tmp = parent->children;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = child;
    }
}

void node_tostring(Node *node, int num)
{
    if (node->type == 0)
        return;
    for (int i = 0; i < num; ++i)
    {
        printf("  ");
    }

    if (!strcmp(node->type_name, "TYPE"))
    {
        printf("TYPE: %s\n", node->name);
    }
    else if (!strcmp(node->type_name, "ID"))
    {
        printf("ID: %s\n", node->name);
    }
    else if (!strcmp(node->type_name, "CHAR"))
    {
        char ch[20];
        strncpy(ch, node->name + 1, strlen(node->name) - 2);
        ch[strlen(node->name) - 2] = '\0';
        if (ch[0] == '\\')
        {
            printf("%s: %s\n", node->type_name, ch);
        }
        else
        {
            printf("%s: '%s'\n", node->type_name, ch);
        }
    }
    else if (!strcmp(node->type_name, "INT") || !strcmp(node->type_name, "FLOAT"))
    {
        printf("%s: %s\n", node->type_name, node->name);
    }
    else if (node->type >= 258 && node->type <= 292)
    {
        printf("%s\n", node->type_name);
    }
    else
    {
        printf("%s (%d)\n", node->name, node->line_no);
    }
}

void display(Node *root, int depth)
{
    if (root->type == 0)
        return;
    node_tostring(root, depth);

    Node *tmp = root->children;
    while (tmp != NULL)
    {
        display(tmp, depth + 1);
        tmp = tmp->next;
    }
}