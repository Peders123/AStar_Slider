#include <algorithm.h>


int main() {

    /*short *scrambled = scramble();
    short startState[9];

    startState[0] = scrambled[0];
    startState[1] = scrambled[1];
    startState[2] = scrambled[2];
    startState[3] = scrambled[3];
    startState[4] = scrambled[4];
    startState[5] = scrambled[5];
    startState[6] = scrambled[6];
    startState[7] = scrambled[7];
    startState[8] = scrambled[8];*/

    short startState[] = {7,2,4,5,0,6,8,3,1};
    short endState[] = {1,2,3,4,5,6,7,8,0};

    printf("Start:\n");
    printState(startState);

    short *reverseSolution = algorithm(startState, endState);

    sleep(2);

    int i;
    int len = reverseSolution[0];
    short *solution;

    if ((solution = (short *)malloc(len)) == NULL) {
        printf("Out of memory\n");
        exit(1);
    }

    for (i = len; i > 0; i--) {
        solution[len-i] = reverseSolution[i];
    }

    short *state;

    state[0] = startState[0];
    state[1] = startState[1];
    state[2] = startState[2];
    state[3] = startState[3];
    state[4] = startState[4];
    state[5] = startState[5];
    state[6] = startState[6];
    state[7] = startState[7];
    state[8] = startState[8];

    printState(state);

    for (i = 0; i < len; i++) {

        state = createChildState(solution[i], state);

        printState(state);

        usleep(100000);

    }

    for (i = 0; i < len-1; i++) {
        switch (solution[i]) {
            case 8:
                printf("Left, ");
                break;
            case 4:
                printf("Right, ");
                break;
            case 2:
                printf("Up, ");
                break;
            case 1:
                printf("Down, ");
                break;
        }
    }

    switch (solution[len-1]) {
        case 8:
            printf("Left");
            break;
        case 4:
            printf("Right");
            break;
        case 2:
            printf("Up");
            break;
        case 1:
            printf("Down");
            break;
    }

    return 0;

}

short * algorithm(short startState[], short endState[]) {

    NODE *open = NULL;
    NODE *closed = NULL;
    NODE *current;

    NODE start;
    NODE end;

    NODE *child;

    int add;
    short move;
    short moves;
    short *childState;

    initNode(&start, startState, NULL, 0, endState);

    end.state[0] = endState[0];
    end.state[1] = endState[1];
    end.state[2] = endState[2];
    end.state[3] = endState[3];
    end.state[4] = endState[4];
    end.state[5] = endState[5];
    end.state[6] = endState[6];
    end.state[7] = endState[7];
    end.state[8] = endState[8];

    insertOrder(&open, &start);

    while (open != NULL) {

        current = pop(&open);

        insert(&closed, current);

        if (eq(*current, end) == 0) {

            static short *solution;
            if ((solution = (short *)malloc((sizeof(short) * current->g_cost) + 1)) == NULL) {
                printf("Out of memory\n");
                exit(1);
            }

            int i;
            int iterations = current->g_cost;

            solution[0] = iterations;

            for (i = 1; i <= iterations; i++) {
                solution[i] = current->move;
                current = current->parent;
            }

            freeList(open);
            freeList(closed);

            return solution;

        }

        moves = getMoves(current->state);

        while (moves > 0) {

            if (moves >= 8) {
                childState = createChildState(8, current->state);
                moves-=8;
                move = 8;
            } else if (moves >= 4) {
                childState = createChildState(4, current->state);
                moves-=4;
                move = 4;
            } else if (moves >= 2) {
                childState = createChildState(2, current->state);
                moves-=2;
                move = 2;
            } else if (moves >= 1) {
                childState = createChildState(1, current->state);
                moves--;
                move = 1;
            }

            if ((child = (NODE *)malloc(sizeof(NODE))) == NULL) {
                printf("Out of memory\n");
                exit(1);
            }

            initNode(child, childState, current, move, endState);

            if (contains(closed, child) != 0) {
                continue;
            }

            add = contains(open, child);

            if (add == 0) {
                insertOrder(&open, child);
            } else if (child->f_cost < add) {
                insertOrder(&open, child);
            }

        }

    }

}

short * createChildState(short move, short parent[]) {

    int index = getIndex(0, parent);
    static short state[9];

    state[0] = parent[0];
    state[1] = parent[1];
    state[2] = parent[2];
    state[3] = parent[3];
    state[4] = parent[4];
    state[5] = parent[5];
    state[6] = parent[6];
    state[7] = parent[7];
    state[8] = parent[8];

    short temp = state[index];

    switch (move) {
        case 8:
            state[index] = state[index+1];
            state[index+1] = temp;
            break;
        case 4:
            state[index] = state[index-1];
            state[index-1] = temp;
            break;
        case 2:
            state[index] = state[index+3];
            state[index+3] = temp;
            break;
        case 1:
            state[index] = state[index-3];
            state[index-3] = temp;
            break;
    }

    return state;

}

short * scramble() {

    short startState[9];
    short *state;
    short moves;

    startState[0] = 1;
    startState[1] = 2;
    startState[2] = 3;
    startState[3] = 4;
    startState[4] = 5;
    startState[5] = 6;
    startState[6] = 7;
    startState[7] = 8;
    startState[8] = 0;


    state = createChildState(1, startState);
    state = createChildState(4, state);

    return state;

}