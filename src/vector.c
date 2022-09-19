//
// Created by andrey on 17.09.22.
//

#include <assert.h>
#include "../include/vector.h"

#define TYPE int

VECTOR CONCATENATE(VECTOR, Constructor)() {
    VECTOR vector;

    vector._size = 0;
    vector._capacity = 0;
    vector.body = NULL;

    return vector;
}

VECTOR CONCATENATE(VECTOR, ConstructorCapacity)(size_t capacity) {
    VECTOR vector = CONCATENATE(VECTOR, Constructor)();

    CONCATENATE(reserve, TYPE)(&vector, capacity);

    return vector;
}

VECTOR CONCATENATE(VECTOR, ConstructorSizeValue)(size_t size, TYPE value) {
    VECTOR vector = CONCATENATE(VECTOR, ConstructorCapacity)(size);

    for (size_t i = 0; i < size; ++i)
        CONCATENATE(pushBack, TYPE)(&vector, value);

    return vector;
}

VECTOR CONCATENATE(VECTOR, ConstructorCopy)(VECTOR const * const other) {
    size_t size = other->_size;
    VECTOR vector = CONCATENATE(VECTOR, ConstructorCapacity)(size);

    for (size_t i = 0; i < size; ++i) {
        TYPE value = CONCATENATE(getAt, TYPE)(other, i);
        CONCATENATE(pushBack, TYPE)(&vector, value);
    }

    return vector;
}

void CONCATENATE(VECTOR, Destructor)(VECTOR * const this) {
    if (this->body != NULL)
        free(this->body);
    this->_capacity = 0;
    this->_size = 0;
}

void CONCATENATE(VECTOR, DestructorComplexType)(VECTOR * const this, void (*elementDestructor)(TYPE *)) {
    if (this->_size > 0)
        for (size_t i = 0; i < this->_size; ++i)
            (*elementDestructor)(&(this->body[i]));

    CONCATENATE(VECTOR, Destructor)(this);
}

TYPE CONCATENATE(getAt, TYPE)(VECTOR const * const this, size_t index) {
    assert(index <= this->_size);

    return this->body[index];
}

void CONCATENATE(setAt, TYPE)(VECTOR * const this, size_t index, TYPE value) {
    assert(index <= this->_size);

    this->body[index] = value;
}

void CONCATENATE(pushBack, TYPE)(VECTOR * const this, TYPE value) {
    if (this->_capacity - this->_size == 0) {
        size_t additionalCapacity = this->_capacity == 0 ? 1 : this->_capacity;
        CONCATENATE(reserve, TYPE)(this, additionalCapacity);
    }

    this->body[this->_size] = value;
    ++(this->_size);
}

TYPE CONCATENATE(popBack, TYPE)(VECTOR * const this) {
    assert(this->_size > 0);

    --(this->_size);
    return this->body[this->_size];
}

void CONCATENATE(shrinkToFit, TYPE)(VECTOR * const this) {
    if (this->_size == this->_capacity)
        return;

    CONCATENATE(_reallocateBody, TYPE)(this, this->_size);
}

size_t CONCATENATE(getSize, TYPE)(VECTOR const * const this) {
    return this->_size;
}

size_t CONCATENATE(getCapacity, TYPE)(VECTOR const * const this) {
    return this->_capacity;
}

void CONCATENATE(reserve, TYPE)(VECTOR * const this, size_t additionalCapacity) {
    CONCATENATE(_reallocateBody, TYPE)(this, this->_capacity + additionalCapacity);
}

void CONCATENATE(clear, TYPE)(VECTOR * const this) {
    this->_size = 0;
}

void CONCATENATE(clearComplexType, TYPE)(VECTOR * const this, void (*elementDestructor)(TYPE *)) {
    for (size_t i = 0; i < this->_size; ++i)
        (*elementDestructor)(&(this->body[i]));

    CONCATENATE(clear, TYPE)(this);
}

void CONCATENATE(addRange, TYPE)(VECTOR * const this, VECTOR const * const range) {
    if (this->_capacity - this->_size < range->_size)
        CONCATENATE(_reallocateBody, TYPE)(this, this->_size + range->_size);

    for (size_t i = 0; i < range->_size; ++i)
        CONCATENATE(pushBack, TYPE)(this, range->body[i]);
}

void CONCATENATE(_reallocateBody, TYPE)(VECTOR *const this, size_t newCapacity) {
    assert(newCapacity >= this->_size);

    TYPE *newBody = (TYPE *) malloc(sizeof(TYPE) * newCapacity);
    for (size_t i = 0; i < this->_size; ++i)
        newBody[i] = this->body[i];
    if (this->_capacity > 0)
        free(this->body);
    this->body = newBody;
    this->_capacity = newCapacity;
}
