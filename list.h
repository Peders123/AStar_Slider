#ifndef __LIST__
#define __LIST__ 1

#include <node.h>

/*----- function prototypes --------------------------------------------------*/

extern void insert(NODE **, NODE *);
extern void insertOrder(NODE **, NODE *);
extern int contains(NODE *, NODE *);
extern void freeList(NODE *);
extern NODE * pop(NODE **);

#endif