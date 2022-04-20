#include <list.h>

void insert(NODE **top, NODE *node) {

    if (*top == NULL) {
        *top = node;
        node->next = NULL;
        return;
    }

    node->next = *top;
    *top = node;

}

void insertOrder(NODE **top, NODE *node) {

    NODE *current;

    if (*top == NULL || (*top)->f_cost >= node->f_cost) {
        node->next = *top;
        *top = node;
    } else {
        current = *top;
        while (current->next != NULL && current->next->f_cost < node->f_cost) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }

}

int contains(NODE *top, NODE *node) {

    if (top == NULL) {
        return 0;
    }


    NODE *current = top;

    while (current->next != NULL) {
        if (eq(*node, *current) == 0) {
            return current->f_cost;
        }
        current = current->next;
    }

    return 0;

}

void freeList(NODE *top) {

    if (top == NULL) {
        return;
    }

    NODE *next = top;
    NODE *temp;
    while (next->next != NULL) {
        temp = next->next;
        free(next);
        next = temp;
    }

}

NODE * pop(NODE **top) {

    if (top == NULL) {
        return NULL;
    }

    NODE *temp = *top;
    *top = (*top)->next;

    return temp;

}
