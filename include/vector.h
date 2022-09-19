//
// Created by andrey on 17.09.22.
//

#ifndef BADSTL_VECTOR_H
#define BADSTL_VECTOR_H

#define TYPE int
#define CONCATENATE_INTERNAL(A, B) A ## B
#define CONCATENATE(A, B) CONCATENATE_INTERNAL(A, B)
#define VECTOR CONCATENATE(Vector, TYPE)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t _size;
    size_t _capacity;
    TYPE *body;
} VECTOR;

VECTOR CONCATENATE(VECTOR, Constructor)();

VECTOR CONCATENATE(VECTOR, ConstructorCapacity)(size_t capacity);

VECTOR CONCATENATE(VECTOR, ConstructorSizeValue)(size_t size, TYPE value);

VECTOR CONCATENATE(VECTOR, ConstructorCopy)(VECTOR const * const other);

void CONCATENATE(VECTOR, Destructor)(VECTOR * const this);

void CONCATENATE(VECTOR, DestructorComplexType)(VECTOR * const this, void (*elementDestructor)(TYPE *));

TYPE CONCATENATE(getAt, TYPE)(VECTOR const * const this, size_t index);

void CONCATENATE(setAt, TYPE)(VECTOR * const this, size_t index, TYPE value);

void CONCATENATE(pushBack, TYPE)(VECTOR * const this, TYPE value);

TYPE CONCATENATE(popBack, TYPE)(VECTOR * const this);

void CONCATENATE(shrinkToFit, TYPE)(VECTOR * const this);

size_t CONCATENATE(getSize, TYPE)(VECTOR const * const this);

size_t CONCATENATE(getCapacity, TYPE)(VECTOR const * const this);

void CONCATENATE(reserve, TYPE)(VECTOR * const this, size_t additionalCapacity);

void CONCATENATE(clear, TYPE)(VECTOR * const this);

void CONCATENATE(clearComplexType, TYPE)(VECTOR * const this, void (*elementDestructor)(TYPE *));

void CONCATENATE(addRange, TYPE)(VECTOR * const this, VECTOR const * const range);

void CONCATENATE(_reallocateBody, TYPE)(VECTOR *const this, size_t newCapacity);

#undef TYPE

#endif //BADSTL_VECTOR_H
