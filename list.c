#include <node.c>


void insert(NODE *, NODE *);
void insertOrder(NODE *, NODE *);


void insert(NODE *top, NODE *node) {

    if (top == NULL) {
        top = node;
        node->next = NULL;
        return;
    }

    node->next = top;
    top = node;

}

void insertOrder(NODE *top, NODE  *node) {

    if (top == NULL) {
        top = node;
        node->next = NULL;
        return;
    }

    NODE *next = top;
    NODE *temp;

    while (next->next != NULL) {
        if (node->f_cost <= next->next->f_cost) {
            temp = next->next;
            next->next = node;
            node->next = temp;
            return;
        }
    }

    next->next = node;

}
