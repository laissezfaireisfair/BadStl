//
// Created by andrey on 28.09.22.
//

#ifndef BADSTL_LIST_H
#define BADSTL_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct i_element {
    struct i_element *next;
    struct i_element *previous;
    T value;
} ListElement;

typedef struct {
    ListElement *head;
    ListElement *tail;
    size_t length;
} List;

List ListConstructor();

void ListDestructor(List * const this);

#endif //BADSTL_LIST_H
