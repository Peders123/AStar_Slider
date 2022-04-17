#ifndef __NODE__
#define __NODE__ 1

#include <stdio.h>
#include <stdlib.h>

/*----- structure definition -------------------------------------------------*/

typedef struct Node {
    short state[9];
    struct Node *parent;
    short move;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node *next;
} NODE;

/*----- function prototypes --------------------------------------------------*/

extern int eq(NODE, NODE);
extern void print(NODE);
extern void initNode(NODE *, short [], NODE *, short, short []);
extern short getMoves(short []);

#endif