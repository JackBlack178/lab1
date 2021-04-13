
#ifndef MYLAB_DYNAMICARRAY_H
#define MYLAB_DYNAMICARRAY_H

struct dynamicArray{
    void *array;
    int length;
    int elementSize;

    void (*set)(struct dynamicArray *array, int index, void* element);
    void* (*get)(struct dynamicArray *array, int index);
    void (*append)(struct dynamicArray *array, void * element);
    void (*sort)(struct dynamicArray *array, int length, int elementSize);
    void (*pop)(struct dynamicArray *array, int index);
    void (*print)();
    struct func* func;
};

struct dynamicArray *newDynamicArray(const struct func *myFunc, int elementSize);
void *getElement(struct dynamicArray *array, int index);
void setElement(struct dynamicArray *array, int index, void* element);
void addElement(struct dynamicArray *array, void * element);
void pop(struct dynamicArray *array, int index);
void sort(struct dynamicArray *array, int lenght, int elementSize);

void newELement(struct dynamicArray *array);
void printElements(struct dynamicArray *array);
void deleteAllElements(struct dynamicArray *array);
void where2(struct dynamicArray *array);
void editValue(struct dynamicArray *array);

void map2(struct dynamicArray *array);
void intMap(struct dynamicArray *array);
void personMap(struct dynamicArray *array);


struct ListOfValues **newListOfStudents(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array);
void printAllList(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array);
void deleteAllLists(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array);
#endif //MYLAB_DYNAMICARRAY_H
