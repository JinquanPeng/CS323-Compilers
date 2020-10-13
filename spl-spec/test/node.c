#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct Node {
    char           name[20];
    struct Node*   dummy_head;
    struct Node*   child;
    int            line_no;
    int            child_no;
    int            begin;
    int            type;
    char           type_name[20];
} Node;

Node* new_node(char* name, char* type_name, int line_no, int type) {
    Node* node = (Node*) malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    Node* child = (Node*) malloc(sizeof(Node));

    node->line_no = line_no;
    node->child_no = 0;
    node->begin = 0;
    node->dummy_head = NULL;
    node->child = NULL;
    node->type = type;
    strncpy(node->name, name, 20);
    if(type_name != NULL){
        strncpy(node->type_name, type_name, 20);
    }

    return node;
}

void insert_node(Node* parent, Node* child) {
    if(child == NULL){
        return;
    }

    if(parent->child_no==0) {
        parent->child = child;
        child->begin = 1;
        parent->child_no = 1;
    } else {
        Node* temp = parent->child;
        while(temp->dummy_head != NULL){
            temp = temp->dummy_head;
        }
        temp->dummy_head = child;
        child->begin = 0;
        parent->child_no++;
    }
}