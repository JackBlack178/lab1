#pragma once
#include "stdio.h"
#include "dynamicArray.h"
#include "person.h"
struct func {
    void (*print)(void *);
    int (*isSame) (void *, void *);
    int (*isGreaterThan)(void *, void *);
    void *(*getNewElement)();
    void (*map)(struct dynamicArray *);
    void (*findByValue)(struct dynamicArray *);
    int (*getElement)(struct dynamicArray *);
    void (*deleteElement)(void *);
};

const struct func intFunction;
const struct func floatFunction;
const struct func charFunction;
const struct func personFunction;

int len(char*string);
int charIsSame(void *value1, void *value2);
int isGreaterPerson(void *value1, void *value2);
void resetPersonsData(struct Person *person, int key);


