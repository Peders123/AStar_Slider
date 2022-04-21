#include <node.h>
#include <manhattan_cost.h>


int eq(NODE node, NODE other) {

    int i;

    for (i=0; i<9; i++) {
        if (node.state[i] != other.state[i]) {
            return 1;
        }
    }

    return 0;

}

void initNode(NODE *node, short state[], NODE *parent, short move, short goal[]) {

    short i;

    for (i = 0; i < 9; i++) {
        node->state[i] = state[i];
    }

    node->parent = parent;
    node->move = move;

    if (parent == NULL) {
        node->g_cost = 0;
    } else {
        node->g_cost = (parent->g_cost)+1;
    }

    node->h_cost = manhattanCost(node->state, goal);
    node->f_cost = node->g_cost + node->h_cost;

}

short getMoves(short state[]) {

    short i;
    short index = -1;
    short moveVal = 0;

    for (i = 0; i < 9; i++) {
        if (state[i] == 0) {
            index = i;
            break;
        }
    }

    if (index > 2) {moveVal += 1;} /* down */
    if (index < 6) {moveVal += 2;} /* up */
    if (index % 3 > 0) {moveVal += 4;} /* right */
    if (index % 3 < 2) {moveVal += 8;} /* left */

    return moveVal;

}

void printState(short state[]) {

    short i;

    printf(" ----- \n");

    for (i = 0; i < 9; i+=3) {
        printf("|%d %d %d|\n", state[i], state[i+1], state[i+2]);
    }

    printf(" ----- \n\n");

}