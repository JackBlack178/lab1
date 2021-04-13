#include "function.h"
#include "person.h"
#include "processValues.h"
#include "stdlib.h"
#include "string.h"
int len(char *string){
    if (string == NULL)
        return 0;
    int i;
    for (i = 0; string[i]!= '\0'; i++);
    return i;
}

int intIsSame(void *value1, void *value2){
    return *(int*)value1 == *(int*)value2;
}

int floatIsSame(void *value1, void *value2){
    return *(float*)value1 == *(float*)value2;
}

int charIsSame(void *value1, void *value2){
    char * str1 = (char*)value1;
    char * str2 = (char*)value2;
    if (len(str1) != len(str2)) return 0;
    for (int i =0; i<len(str1); i++){
        if (*(str1+i) != *(str2+i)) {
            return 0;
        }
    }
    return 1;
}

int personIsSame(void *value1, void *value2){
    struct Person *person1 = value1;
    struct Person *person2 = value2;
    if (person1->func->isSame(person1,person2))
        return 1;
    return 0;
}

void intPrint(void *value) {
    if (value == NULL)
        printf("(information is absent)\n");

    else
        printf("%d\n",*(int*)value);
}

void floatPrint(void *value) {
    if (value == NULL)
        printf("(information is absent)\n");
    else
        printf("%f\n", *(float*)value);
}

void charPrint(void *value) {
    if (value == NULL)
        printf("(information is absent)\n");
    else
        printf("%s\n",(char*)value);
}

void personPrint(void *value) {
    if (value == NULL) {
        printf("Person is not filled\n");
        return;
    }
    struct Person *person = value;
    if (person->func == &intFunction)
        printf("Int type\n");
    else if (person->func == &floatFunction)
        printf("Float type\n");
    else if (person->func == &charFunction)
        printf("String type\n");
    else
        printf("Unknown type\n");

    printf("User's name is ");
    person->func->print(person->name);
    printf("User's series is ");
    person->func->print(person->ID->series);
    printf("User's number is ");
    person->func->print(person->ID->number);
    printf("User's age is ");
    person->func->print(person->age);
    printf("User's position/status is ");
    person->func->print(person->position);
    printf("\n");
}

int isGreaterInt(void *value1, void *value2){
    return *(int*)value1 > *(int*)value2;
}

int isGreaterFloat(void *value1, void *value2){
    return *(float *)value1 > *(float *)value2;
}

int isGreaterString(void *value1, void *value2){
    int lenght = len(value1) > len(value2) ? len(value2) : len(value1);
    for (int i = 0; i < lenght; i++){
        if (*(char*)(value1+i) > *(char*)(value2+i))
            return 1;
        else if (*(char*)(value1+i) < *(char*)(value2+i))
            return 0;
    }
    if (len(value1) > len(value2))
        return 1;
    return 0;
}

void *getNewElementInt(){
    int *manageNumber = (int*)malloc(sizeof(int));
    while(1){
        printf("Adding number\n");
        printf("Enter your number\n");
        *manageNumber = getNumber();
        if (!*manageNumber)
            continue;

        return (void*)manageNumber;
    }
}

void *getNewElementPerson(){
    int manageNumber;
    struct Person *person;
    while (1){
        printf("To create Int Person - enter 1\n");
        printf("To create Float Person - enter 2\n");
        printf("To create String Person - enter 3\n");
        manageNumber = getNumber();
        if (manageNumber)
            break;
    }
    switch(manageNumber){
        case 1: person = createIntPerson(); break;
        case 2: person = createFloatPerson(); break;
        default:person = createStringPerson();break;
    }
    return (void*)person;
}

int isGreaterPerson(void *value1, void *value2){
    struct Person *person1 = value1;
    struct Person *person2 = value2;
    if (person1->func != person2->func){
        return 0;
    }
    return isGreaterString(person1->name,person2->name);
}

void intMap(struct dynamicArray *array){
    printf("To set 0 to all numbers - enter 1\n");
    printf("To multiply all numbers by special number - enter 2\n");
    printf("Enter any other number to exit\n");
    int manageNumber = getNumber();
    int tempNumber;
    if (!manageNumber){
        printf("Wrong number\n");
        return;
    }
    switch (manageNumber) {
        case 1:
            manageNumber = 0;
            for (int i = 0; i<array->length; i++)
                memcpy(array->array+i*array->elementSize, &manageNumber, array->elementSize);
            return;
        case 2:
            printf("Enter a factor");
            tempNumber = getNumber();
            if (!tempNumber){
                printf("Wrong number\n");
                return;
            }
            for (int i = 0; i<array->length; i++){
                manageNumber = *(int*)(array->array+i*array->elementSize);
                manageNumber = manageNumber * tempNumber;
                memcpy(array->array+i*array->elementSize, &manageNumber, array->elementSize);
            } return;
        default: return;
    }
}

void personMap(struct dynamicArray *array){
    printf("To reset all users name - enter 1\n");
    printf("To reset ID number - enter 2\n");
    printf("To reset ID series - enter 3\n");
    printf("To age - enter 4\n");
    printf("To reset position - enter 5\n");
    int manageNumber = getNumber();
    if (!manageNumber){
        printf("Wrong number\n");
        return;
    }
    for (int i = 0; i<array->length; i++){
        switch(manageNumber) {
            case 1:resetPersonsData(array->array+i*array->elementSize,1);break;
            case 2:resetPersonsData(array->array+i*array->elementSize,2);break;
            case 3:resetPersonsData(array->array+i*array->elementSize,3);break;
            case 4:resetPersonsData(array->array+i*array->elementSize,4);break;
            case 5:resetPersonsData(array->array+i*array->elementSize,5);break;
            default:printf("Something went wrong\n");break;
        }
    }
}

void resetPersonsData(struct Person *person, int key){
    switch (key) {
        case 1:free(person->name);person->name = NULL;return;
        case 2:free(person->ID->number);person->ID->number = NULL;return;
        case 3:free(person->ID->series);person->ID->series = NULL;return;
        case 4:free(person->age);person->age = NULL;return;
        case 5:free(person->position);person->position = NULL;return;
        default:printf("Something went wrong\n");return;
    }
}

void findByValueInt(struct dynamicArray *array){
    printf("Enter number for searching\n");
    int manageNumber = getNumber();
    for (int i = 0; i < array->length; i++){
        if (array->func->isSame(array->array+i*array->elementSize, &manageNumber)){
            printf("Value was found\nIndex is %d\nNumber is ",i);
            array->func->print(array->array+i*array->elementSize);
            return;
        }
    }
    printf("User wasn't found");
}

void findByValuePerson(struct dynamicArray *array){
    printf("What type of person you want to find?\n");
    printf("Int Person - enter 1\n");
    printf("Float Person - enter 2\n");
    printf("String Person - enter 3\n");
    struct Person *person;
    int manageNumber = getNumber();
    if (manageNumber == 1){
        printf("Enter person's ID number\n");
        manageNumber = getNumber();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (intIsSame(&manageNumber,person->ID->number)) {
                printf("Value was found\nIndex is %d\nNumber is ", i);
                array->func->print(array->array + i * array->elementSize);
                return;
            }
        }
        printf("Wasn't found\n");
        return;
    }
    if (manageNumber == 2){
        float *fNumber;
        printf("Enter person's ID number\n");
        fNumber = getFloat();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (floatIsSame(fNumber,person->ID->number)) {
                printf("Value was found\nIndex is %d\nNumber is ", i);
                array->func->print(array->array + i * array->elementSize);
                return;
            }
        }
        printf("Wasn't found\n");
        return;
    }
    if (manageNumber == 3){
        printf("Enter person's name\n");
        char *string = get_str();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (charIsSame(string, person->name)) {
                printf("Value was found\nIndex is %d\nNumber is ", i);
                array->func->print(array->array + i * array->elementSize);
                return;
            }
        }
        printf("Wasn't found\n");
        return;
    }
}

int getElementInt(struct dynamicArray *array){
    printf("Enter number for searching\n");
    int manageNumber = getNumber();
    for (int i = 0; i < array->length; i++){
        if (array->func->isSame(array->array+i*array->elementSize, &manageNumber)){
            printf("Value was found\n");
            array->func->print(array->array+i*array->elementSize);
            return i;
        }
    }
    printf("User wasn't found");
    return -1;
}

int getElementPerson(struct dynamicArray *array){
    printf("What type of person you want to find?\n");
    printf("Int Person - enter 1\n");
    printf("Float Person - enter 2\n");
    printf("String Person - enter 3\n");
    struct Person *person;
    int manageNumber = getNumber();
    if (manageNumber == 1){
        printf("Enter person's ID number\n");
        manageNumber = getNumber();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (intIsSame(&manageNumber,person->ID->number))
                return i;

        }
        printf("Wasn't found\n");
        return -1;
    }
    if (manageNumber == 2){
        float *fNumber;
        printf("Enter person's ID number\n");
        fNumber = getFloat();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (floatIsSame(fNumber,person->ID->number))
                return i;
        }
        printf("Wasn't found\n");
        return -1;
    }
    if (manageNumber == 3){
        printf("Enter person's name\n");
        char *string = get_str();
        for (int i = 0; i < array->length; i++) {
            person = array->array + i * array->elementSize;
            if (charIsSame(string, person->name))
                return i;
        }
        printf("Wasn't found\n");
        return -1;
    }
    return -1;
}

void deleteElementInt(void *value){
    if (value == NULL)
        return;
    free(value);
}

void deleteElelementPerson(void *value){
    deletePerson(value);
}

const struct func floatFunction = {
    floatPrint,
    floatIsSame,
    isGreaterFloat
};

const struct func charFunction = {
    charPrint,
    charIsSame,
    isGreaterString,
};

const struct func intFunction = {
        intPrint,
        intIsSame,
        isGreaterInt,
        getNewElementInt,
        intMap,
        findByValueInt,
        getElementInt
};

const struct func personFunction = {
    personPrint,
    personIsSame,
    isGreaterPerson,
    getNewElementPerson,
    personMap,
    findByValuePerson,
    getElementPerson
};

