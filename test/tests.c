#include <stdio.h>
#include "../include/vector.h"

int main() {
    Vectorint vector = VectorintConstructor();

    for (int i = 0; i < 10; ++i)
        pushBackint(&vector, i);

    size_t length = getSizeint(&vector);
    for (size_t i = 0; i < length; ++i)
        printf("%d", (getAtint(&vector, i)));
    size_t capacity = getCapacityint(&vector);
    printf("\nCapacity: %d", capacity);

    reserveint(&vector, 5);
    capacity = getCapacityint(&vector);
    printf("\nExtended capacity: %d", capacity);

    shrinkToFitint(&vector);
    capacity = getCapacityint(&vector);
    printf("\nShrunk to fit capacity: %d", capacity);

    VectorintDestructor(&vector);
    return 0;
}
