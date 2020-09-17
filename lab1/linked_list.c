#include "linked_list.h"

node *linked_list_init()
{
    node *head = (node *)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head)
{
    node *cur = head;
    node *last;
    while (cur != NULL)
    {
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head)
{
    node *cur = head->next;
    char *position;
    int length = 0;
    while (cur != NULL)
    {
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if (cur != NULL)
        {
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head)
{
    return head->count;
}

void linked_list_append(node *head, int val)
{
    node *cur = head;
    node *new_node;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    new_node = (node *)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

void linked_list_insert(node *head, int val, int index)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;

    node *cur = head;
    int i = 0;
    for (i = 0; i < index; i++)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            return;
        }
    }

    new_node->next = cur->next;
    cur->next = new_node;

    head->count++;
}

void linked_list_delete(node *head, int index)
{
    if (index < 0)
    {
        return;
    }
    node *cur = head;
    int i = 0;
    for (i = 0; i < index; i++)
    {
        cur = cur->next;
        if (cur->next == NULL)
        {
            return;
        }
    }
    node *tmp = cur->next;
    cur->next = cur->next->next;
    free(tmp);

    head->count--;
}

void linked_list_remove(node *head, int val)
{
    node *tmp = head->next;
    while (tmp != NULL && tmp->next != NULL && tmp->next->value != val)
    {
        tmp = tmp->next;
    }
    if (tmp != NULL && tmp->next != NULL && tmp->next->value == val)
    {
        tmp->next = tmp->next->next;
        head->count--;
    }
}

void linked_list_remove_all(node *head, int val)
{
    node *pre = NULL;
    node *cur = head->next;
    while (cur != NULL)
    {
        if (cur->value == val)
        {
            pre->next = cur->next;
            head->count--;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
}

int linked_list_get(node *head, int index)
{
    if (index < 0 || index >= head->count)
    {
        return -0x80000000;
    }

    node *cur = head->next;
    int i = 0;
    for (i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->value;
}

/* search the first index of val */
int linked_list_search(node *head, int val)
{
    node *tmp = head->next;
    int cur_index = 0;
    while (tmp != NULL && tmp->value != val)
    {
        tmp = tmp->next;
        cur_index++;
    }
    if (tmp != NULL && tmp->value == val)
    {
        return cur_index;
    }
    return -1;
}

/* search all indexes of val */
node *linked_list_search_all(node *head, int val)
{
    node *rst = linked_list_init();
    node *cur = head->next;
    int index = 0;
    while (cur != NULL)
    {
        if (cur->value == val)
        {
            linked_list_append(rst, index);
        }
        cur = cur->next;
        index++;
    }
    return rst;
}