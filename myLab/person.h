#pragma once

#include "function.h"
#include "stdlib.h"
typedef struct {
    void* series;
    void* number;
} PersonID;

typedef struct Person{
    PersonID* ID;
    void* name;
    void* age;
    void* position;          // professor or student
    size_t element_size;
    size_t personSize;

    int (*isSame) (struct Person *person1, struct Person *person2);
    void (*print)(struct Person *person);
    void (*remove)(struct Person *person);
    void (*getName)(struct Person *person);
    void (*getStatus)(struct Person *person);
    void (*sorted)(struct Person *person1, struct Person *person2);
    struct func* func;

} Person;


typedef struct ConcatenatedStudents{
    struct Person* professor;
    struct Person** student;
    int numberOfStudents;


    void (*print)(struct ConcatenatedStudents *person);
    void (*remove)(struct ConcatenatedStudents *person);

    struct func* func;

} ConcatanetedStudents;

struct ListOfValues{
    void *array;
    int length;
    int elementSize;
};



struct Person *createNewPerson(void *series, void *number, void *name, void *age, void *position, size_t element_size, const struct func *myFunc);
void deletePerson(struct Person *person);
void printPerson(struct Person *person);
void getName(struct Person *person);
void getStatus(struct Person *person);

//For comparing persons
int isNotTheSameType(struct Person *person1, struct Person *person2);
int personIsTheSame(struct Person *person1, struct Person *person2);

struct MappedPerson *createMappedPerson(struct Person* professor, struct Person* student, const struct func *myFunc);
struct ConcatenatedStudents* createListOfStudents();