#include <manhattan_cost.h>


short manhattanCost(short state[], short target[]) {

    short i = 0;
    short cost = 0;

    for (i = 0; i < 9; i++) {
        cost += abs((getIndex(i, state) % 3) - (getIndex(i, target) % 3));
        cost += abs((getIndex(i, state) / 3) - (getIndex(i, target) / 3));
    }

    return cost;

}

short getIndex(short val, short state[]) {

    short i = 0;

    for (i = 0; i < 9; i++) {
        if (state[i] == val) {
            return i;
            break;
        }
    }

    return -1;

}
