#include "person.h"

struct Person *createNewPerson(void *series, void *number, void *name, void *age, void *position, size_t element_size, const struct func *myFunc){
    struct Person *myPerson = (struct Person*)malloc(sizeof(struct Person));
    myPerson->ID = malloc(sizeof(PersonID));

    myPerson->ID->series = series;
    myPerson->ID->number = number;
    myPerson->name = name;
    myPerson->age = age;
    myPerson->position = position;
    myPerson->element_size = element_size;
    myPerson->personSize = sizeof(Person);

    //functions below

    myPerson->func = myFunc;
    myPerson->print = printPerson;
    myPerson->isSame = personIsTheSame;
    myPerson->remove = deletePerson;
    myPerson->getName = getName;
    myPerson->getStatus = getStatus;

    return myPerson;

}

int isNotTheSameType(struct Person *person1, struct Person *person2) {
    if (person1 == NULL || person2 == NULL) return 1;
    if (person1->personSize != sizeof(Person) || person2->personSize != sizeof(Person)) return 1;

    return (person1->element_size != person2->element_size || person1->func != person2->func);
}

int personIsTheSame(struct Person *person1, struct Person *person2) {
        if (isNotTheSameType(person1, person2))
            return 0;
        return (person1->func->isSame(person1->ID->series, person2->ID->series) &&
                person1->func->isSame(person1->ID->number, person2->ID->number) &&
                person1->func->isSame(person1->name, person2->name)) &&
                person1->func->isSame(person1->age,person2->age) &&
                person1->func->isSame(person1->position,person2->position);
}

void printPerson(struct Person *person) {
    if (person == NULL) {
        printf("Person is not filled\n");
        return;
    }
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

void deletePerson(struct Person *person) {
    if (person->ID->number != NULL)
        free(person->ID->number);
    if (person->ID->series != NULL)
        free(person->ID->series);
    if (person->ID != NULL)
        free(person->ID);
    if (person->name != NULL)
        free(person->name);
    if (person->age != NULL)
        free(person->age);
    if (person->position != NULL)
        free(person->position);
    if (person != NULL)
        free(person);

}

void getName(struct Person *person){
    printf("User's name is ");
    person->func->print(person->name);
}

void getStatus(struct Person *person){
    printf("User's position/status is ");
    person->func->print(person->position);
}

void printListOfStudents(struct ConcatenatedStudents* listofStudents){
    printf("Persons:\n");
    for (int i = 0; i<listofStudents->numberOfStudents;i++){
        if (listofStudents->student != NULL){
            printf("Student %d:\n",i);
            listofStudents->student[i]->print(listofStudents->student[i]);
        }
    }
}

void removeListOfStudents(struct ConcatenatedStudents *listOfStudents){
    free(listOfStudents);
}

struct ConcatenatedStudents* createListOfStudents(){
    struct ConcatenatedStudents *listOfStudents = (struct ConcatenatedStudents*)malloc(sizeof(struct ConcatenatedStudents));
    listOfStudents->professor = NULL;
    listOfStudents->print = printListOfStudents;
    listOfStudents->remove = removeListOfStudents;
    return listOfStudents;
}