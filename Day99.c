#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    
    Car cars[positionSize];

    // Store position and speed together
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by position: closest to target first
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < positionSize; i++) {

        // Time required to reach target
        double time = (double)(target - cars[i].position)
                      / cars[i].speed;

        /*
         * If this car takes more time than the previous fleet,
         * it cannot catch that fleet -> new fleet.
         */
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }

        /*
         * Otherwise, this car catches the fleet ahead
         * and becomes part of the same fleet.
         */
    }

    return fleets;
}