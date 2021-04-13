#include "dynamicArray.h"
#include "stdlib.h"
#include "string.h"
#include "person.h"
#include "processValues.h"
#include "menu.h"
struct dynamicArray *newDynamicArray(const struct func *myFunc, int elementSize){
    struct dynamicArray *myArray = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
    myArray->length = 0;
    myArray->get = getElement;
    myArray->set = setElement;
    myArray->append = addElement;
    myArray->pop = pop;
    myArray->sort = sort;
    myArray->func = myFunc;
    myArray->elementSize = elementSize;

    return myArray;
}

void *getElement(struct dynamicArray *array, int index){
    return (void*)((char*)array->array+index*array->elementSize);
}

void setElement(struct dynamicArray *array, int index, void* element){
    memcpy(getElement(array,index),element, array->elementSize);
}

void addElement(struct dynamicArray *array, void * element){
    if (!(array->length)){
        array->array = malloc(array->elementSize);
        memcpy(array->array,element,array->elementSize);
        array->length++;
        return;
    }
    int size = array->elementSize*array->length;
    void* arrayNew = malloc(size + array->elementSize);
    memcpy(arrayNew,array->array,size);
    memcpy((arrayNew+size),element,array->elementSize);
    free(array->array);
    array->array = arrayNew;
    array->length++;
}

void pop(struct dynamicArray *array, int index){
    if (!(array->length)){
        return;
    }
    if (array->length == 1){
        array->func->deleteElement(array->array);
        array->array = NULL;
        array->length--;
        return;
    }
    int size = array->elementSize*index;
    void* arrayNew = malloc(size - array->elementSize);
    if (!index){
        memcpy(arrayNew,array->array,index*array->elementSize);
    }
    if (!(array->length-index-1))
        memcpy(arrayNew+size,array->array+size+array->elementSize,array->elementSize*(array->length-index-1));
    array->func->deleteElement(array->array);
    array->array = arrayNew;
    array->length--;
}

void sort(struct dynamicArray *array, int length, int elementSize){
    int counter = length;
    void *value1;
    void *value2;
    void *tempValue = malloc(sizeof(elementSize));
    for (int i = 0; i < counter-1; i++)
    {
        for (int j = counter - 1; j > i; j--)
        {
            value1 = array->array + (j-1)*elementSize;
            value2 = array->array + j*elementSize;
            if (value1 == NULL || value2 == NULL) {
                counter++;
                continue;
            }
            if (array->func->isGreaterThan(value1,value2))
            {
                memcpy(tempValue,value1,elementSize);
                memcpy(array->array+(j-1)*elementSize, value2, elementSize);
                memcpy(array->array+(j)*elementSize, tempValue, elementSize);
            }
        }
    }

    printf("Array was sorted\n");
    free(tempValue);
}

void newELement(struct dynamicArray *array){
    void *value = array->func->getNewElement();
    array->append(array,value);
}

void printElements(struct dynamicArray *array) {
    if (array->length == 0){
        printf("There are no elements\n");
        return;
    }
    printf("Number of elements is %d\n",array->length);
    for (int i = 0; i<array->length; i++){
        array->func->print(array->array+i*array->elementSize);
    }
}

void deleteAllElements(struct dynamicArray *array){
    if (array->length == 0){
        printf("There are no elements\n");
        return;}
    free(array->array);
    array->array = NULL;
    array->length = 0;
}

void where2(struct dynamicArray *array){
    printf("To get more information about one value - enter 1\n");
    printf("To edit value - enter 2\n");
    printf("To cancel - enter 3\n");
    int manageNumber = getNumber();
    if (!manageNumber)
        return;
    switch (manageNumber) {
        case 1:array->func->findByValue(array);return;
        case 2:editValue(array);
    }

}
void editValue(struct dynamicArray *array){
    int oldValue = array->func->getElement(array);
    if (oldValue == -1)
        return;
    printf("Creating new value\n");
    void *newValue = array->func->getNewElement();
    array->set(array,oldValue,newValue);
    free(newValue);
}

void map2(struct dynamicArray *array){
    array->func->map(array);
}

struct ListOfValues **newListOfStudents(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array){
    int manageNumber;
    int counter;
    int amountOfList = *numberOfList;
    printf("All values\n");

    for (int i = 0; i < array->length; i++){
        printf("Index is %d\n",i);
        array->func->print(array->array+i*array->elementSize);
    }
    printf("How many values you want to concatenate?\n");
    manageNumber = getNumber();
    counter = manageNumber;

    if (!manageNumber)
        return listOfStudents;

    if (amountOfList)
        listOfStudents = (struct ListOfValues **)malloc(sizeof(struct ListOfValues**));
    else{
        listOfStudents = (struct ListOfValues **)realloc(listOfStudents, sizeof(struct ListOfValues**));
    }
    listOfStudents[amountOfList] = (struct ListOfValues*)malloc(sizeof(struct ListOfValues));
    listOfStudents[amountOfList]->array = malloc(array->elementSize*counter);
    for (int i = 0; i < counter; i++){
        printf("Enter the index of number you want to concatenate\n");
        manageNumber = getNumber();
        if (manageNumber > counter || manageNumber < 0)
            manageNumber = 0;
      memcpy(listOfStudents[amountOfList]->array+i*array->elementSize, array->array+manageNumber*array->elementSize, array->elementSize);
    }
    listOfStudents[amountOfList]->length = counter;
    (*numberOfList)++;
    return listOfStudents;
}

void printAllList(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array){
    printf("number of lists is %d\n",*numberOfList);
    for (int i = 0; i< *numberOfList; i++){
        printf("%d list:\n",i+1);

        for (int j = 0; j < listOfStudents[i]->length; j++){
            array->func->print(listOfStudents[i]->array+j*array->elementSize);
        }
    }
}
void deleteAllLists(struct ListOfValues **listOfStudents, int *numberOfList, struct dynamicArray *array){
    for (int i = 0; i < *numberOfList; i++){
        free(listOfStudents[i]->array);
    }
    free(listOfStudents);
    *numberOfList = 0;
}

