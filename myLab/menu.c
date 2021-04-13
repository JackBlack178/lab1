#include <stdio.h>
#include "processValues.h"
#include "person.h"
#include <ctype.h>
#include "menu.h"
#include "dynamicArray.h"

void runningApp() {
    struct Person *person;
    struct Person **arrayOfPerson = NULL;
    struct ConcatenatedStudents **listOfStudents = NULL;
    int numberOfPeople = 0;
    int manageNumber;
    int numberOfConcatanetedStudents = 0;

    while (1) {
        printMenu();
        manageNumber = getNumber();
        if (!manageNumber){
            continue;}
        switch (manageNumber){
            case 1:arrayOfPerson = createPersonsOp(arrayOfPerson, &numberOfPeople);break;
            case 2:person = where(arrayOfPerson,&numberOfPeople);break;
            case 3:map(arrayOfPerson,&numberOfPeople);break;
            case 4:listOfStudents = createListOfPerson(listOfStudents, &numberOfConcatanetedStudents, arrayOfPerson, &numberOfPeople);break;
            case 5:sorted(arrayOfPerson, &numberOfPeople);break;
            case 6:printConcatenatedPerson(listOfStudents, numberOfConcatanetedStudents);break;
            case 7:deleteAllConcatenatedPerson(listOfStudents, &numberOfConcatanetedStudents);break;
            case 8:printf("\nQuitting program...\n");return;
            default:errorPrint();break;
        }
    }
}

void runningApp2(){
    struct dynamicArray *myArray = NULL;
    struct ListOfValues **listOfStudents = NULL;
    int numberOfList = 0;
    int manageNumber;
    while (1) {
        printf("What type you want to use\n");
        printf("Int type - enter 1\n");
        printf("Person type - enter 2\n");
        printf("To quit - enter 3\n");
        manageNumber = getNumber();
        if (!manageNumber)
            continue;
        if (manageNumber == 1){
            myArray = newDynamicArray(&intFunction, sizeof(int));break;
        }
        else if (manageNumber == 2){
            myArray = newDynamicArray(&personFunction, sizeof(struct Person));break;
        }
        else if (manageNumber == 3){
            printf("Stopping programm...\n");
            return;
        }
    }

    while (1) {
        printMenu2();
        manageNumber = getNumber();
        if (!manageNumber){
            continue;
        }
        switch (manageNumber) {
            case 1: newELement(myArray);break;
            case 2: printElements(myArray);break;
            case 3: deleteAllLists(listOfStudents,&numberOfList,myArray);deleteAllElements(myArray);break;
            case 4: where2(myArray);break;
            case 5: map2(myArray);break;
            case 6: listOfStudents = newListOfStudents(listOfStudents, &numberOfList, myArray);break;
            case 7: printAllList(listOfStudents, &numberOfList, myArray);break;
            case 8:printf("Stopping program\n");return;
            case 9:sort(myArray, myArray->length, myArray->elementSize);break;
            default:break;
        }
    }


}

void printMenu() {
    printf("\nThe program is managed by the entered number\n");
    printf("Create new person - enter 1\n");
    printf("To apply function to person - enter 2\n");
    printf("To map - enter 3\n");
    printf("Concatenate two dict (To connect two students with the same professor)- enter 4\n");
    printf("To sort list of persons - enter 5\n");
    printf("To print all concataneted persons - enter 6\n");
    printf("To delete all concataneted persons - enter 7\n");
    printf("To quit - enter 8\n");
    printf("Enter the number of command you want to execute\n");
}

void printMenu2(){
    printf("\nThe program is managed by the entered number\n");
    printf("Add new value - enter 1\n");
    printf("To print all values - enter 2\n");
    printf("To delete all values- enter 3\n");
    printf("To apply func to special values - enter 4\n");
    printf("To apply func to all values - enter 5\n");
    printf("To concatenate values - enter 6\n");
    printf("To print all concatenated values - enter 7\n");
    printf("To quit - enter 8\n");
    printf("To sort - enter 9\n");
}

void errorPrint(){
    printf("\nYou have not entered a number or it has not been correct number\n");
    printf("Try again\n");
}

void typePrint(){
    printf("Int - enter 1\n");
    printf("Float - enter 2\n");
    printf("String - enter 3\n");
    printf("Cancel- enter 4\n");
}

void resetPrint(){
    printf("To reset ID number - enter 1\n");
    printf("To reset ID series - enter 2\n");
    printf("To age - enter 3\n");
    printf("To reset position - enter 4\n");
}

void printByParameter(){
    printf("To find by ID number - enter 1\n");
    printf("To find by ID series - enter 2\n");
    printf("To find by age - enter 3\n");
    printf("To find by position/status - enter 4\n");
}

int checkingManageNumber(int manageNumber){
    if (!manageNumber){
        errorPrint();
        return 1;}
    return 0;
}

void deletePrintParameter(){
    printf("To delete Int - enter 1\n");
    printf("To delete Float - enter 2\n");
    printf("To delete String - enter 3\n");
    printf("To Cancel- enter 4\n");
}

int isNumber(char *str){
    while(*str)
    {
        if(!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

void printAll(struct Person ** arrayPersons, int *numberOfPeople){
    int counter = *numberOfPeople;
    printf("Number of people is %d\n",*numberOfPeople);
    for (int i = 0; i < counter; i++){
        if (arrayPersons[i] == NULL){
            counter++;
            continue;
        }
        struct Person * person =  *(arrayPersons+i);
        person->print(person);
    }
}

void printUserWithIntType(struct Person ** arrayPersons, int *numberOfPeople){
    int counter = *numberOfPeople;

    for (int i = 0; i < counter; i++){
        if (*(arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        struct Person * person =  *(arrayPersons+i);
        if (person->func == &intFunction){
            person->print(person);


        }
    }
    if (counter == *numberOfPeople && arrayPersons[0] == NULL)
        printf("List of string person is empty\n");
}

void printUserWithFloatType(struct Person ** arrayPersons, int *numberOfPeople){
    int counter = *numberOfPeople;
    for (int i = 0; i < counter; i++){
        if (*(arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        struct Person * person =  *(arrayPersons+i);
        if (person->func == &floatFunction){
            person->print(person);


        }
    }
    if (counter == *numberOfPeople && arrayPersons[0] == NULL)
        printf("List of string person is empty\n");
}

void printUserWithStringType(struct Person ** arrayPersons, int *numberOfPeople){
    int n = *numberOfPeople;
    for (int i = 0; i < n; i++){
        if (*(arrayPersons+i) == NULL){
            n++;
            continue;
        }
        struct Person * person =  *(arrayPersons+i);
        if (person->func == &charFunction){
            person->print(person);
        }
    }
    if (n == *numberOfPeople && arrayPersons[0] == NULL)
        printf("List of string person is empty\n");
}

struct Person *findByIDInt(struct Person ** arrayPersons, int *numberOfPeople, int ID, int key){
    int counter = *numberOfPeople;
    if (arrayPersons == NULL || *numberOfPeople == 0){
        return NULL;
    }
    for (int i = 0; i<counter; i++){
        if((*arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        struct Person *person = *(arrayPersons+i);
        switch(key){
            case 1:
                if (person->ID->number != NULL && *(int*)(person->ID->number) == ID){
                    return person;
                }
                break;
            case 2:
                if (person->ID->series!= NULL && *(int*)(person->ID->series) == ID){
                    return person;
                }
                break;
            case 3:
                if (person->age != NULL && *(int*)(person->age) == ID){
                    return person;
                }
                break;
            case 4:
                if (person->position != NULL && *(int*)(person->position) == ID){
                    return person;
                }
                break;
            default:printf("Something went wrong!\n");break;
        }
    }
    return NULL;
}

struct Person *findByIDFloat(struct Person ** arrayPersons, int *numberOfPeople, float ID, int key){
    int counter = *numberOfPeople;
    if (arrayPersons == NULL || *numberOfPeople == 0)
        return NULL;
    for (int i = 0; i<counter; i++){
        if((*arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        struct Person *person = *(arrayPersons+i);
        switch(key){
            case 1:
                if (person->ID->number != NULL && *(float*)(person->ID->number) == ID){
                    return person;
                }
                break;
            case 2:
                if (person->ID->series!= NULL && *(float *)(person->ID->series) == ID){
                    return person;
                }
                break;
            case 3:
                if (person->age != NULL && *(float *)(person->age) == ID){
                    return person;
                }
                break;
            case 4:
                if (person->position != NULL && *(float *)(person->position) == ID){
                    return person;
                }
                break;
            default:printf("Something went wrong!\n");break;
        }
    }
    return NULL;
}

struct Person *findByIDString(struct Person ** arrayPersons, int *numberOfPeople, char* string, int key){
    int counter = *numberOfPeople;
    if (arrayPersons == NULL || *numberOfPeople == 0)
        return NULL;
    for (int i = 0; i<counter; i++){
        if((*arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        struct Person *person = *(arrayPersons+i);
        switch(key){
            case 1:
                if (person->ID->number != NULL && charIsSame(string,person->ID->number)){
                    return person;
                }
                break;
            case 2:
                if (person->ID->series!= NULL && charIsSame(string,person->ID->series)){
                    return person;
                }
                break;
            case 3:
                if (person->age != NULL && charIsSame(string,person->age)){
                    return person;
                }
                break;
            case 4:
                if (person->position != NULL && charIsSame(string,person->position)){
                    return person;
                }
                break;
            case 5:
                if (person->name != NULL && charIsSame(string,person->name)){
                    return person;
                }
                break;
            default:printf("Something went wrong!\n");break;
        }
    }
    return NULL;
}

struct ConcatenatedStudents *concatenateStudents(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber;
    int ID;

    int counter = *numberOfPerson;
    printf("Number of people is %d\n",*numberOfPerson);
    for (int i = 0; i < counter; i++){
        if (*(arrayOfPerson+i) == NULL){
            counter++;
            continue;
        }
        struct Person * person =  *(arrayOfPerson+i);
        printf("ID - %d\n",i+1);
        person->print(person);
    }

    printf("How many people do you want to concatenate?\n");
    manageNumber = getNumber();
    if (checkingManageNumber(manageNumber)){
        return NULL;
    }
    struct ConcatenatedStudents *listOfPersons = createListOfStudents(manageNumber);
    listOfPersons->student = (struct Person**)malloc(sizeof(struct Person**)*manageNumber);
    listOfPersons->numberOfStudents = manageNumber;
    for (int i = 0; i<manageNumber; i++){
        printf("Enter the number of person in a row you want to concatenate:\n");
        ID = getNumber();
        if (checkingManageNumber(manageNumber) || ID<0 || ID> *numberOfPerson){
            errorPrint();
            return NULL;
        }
        *(listOfPersons->student+i) = *(arrayOfPerson+ID-1);
    }
    return listOfPersons;
}

struct ConcatenatedStudents **createListOfPerson(struct ConcatenatedStudents **listOfStudents, int *numberOfConcatanetedStudents, struct Person **arrayOfPerson, int *numberOfPerson){
    if (!*numberOfPerson){
        printf("There is no one to concatanate\n");
        return NULL;
    }
    if (!numberOfConcatanetedStudents)
        listOfStudents = (struct ConcatenatedStudents**)malloc(sizeof(struct ConcatenatedStudents**));
    else
        listOfStudents  = (struct ConcatenatedStudents**)realloc(listOfStudents, sizeof(struct ConcatenatedStudents**));

    listOfStudents[*numberOfConcatanetedStudents] = createListOfStudents();

    listOfStudents[*numberOfConcatanetedStudents] = concatenateStudents(arrayOfPerson, numberOfPerson);
    if (listOfStudents[*numberOfConcatanetedStudents] != NULL) {
        (*numberOfConcatanetedStudents)++;
    }
    return listOfStudents;

}

void  printConcatenatedPerson(struct ConcatenatedStudents **listOfStudents, int numberOfConcatenatedStudents){
    int manageNumber = numberOfConcatenatedStudents;
    if (!manageNumber){
        printf("There is no concataneted persons\n");
        return;}
    for (int i = 0; i < manageNumber; i++){
        if (*(listOfStudents+i) == NULL){
            manageNumber++;
            continue;
        }
        listOfStudents[i]->print(listOfStudents[i]);

    }
}

void deleteAllConcatenatedPerson(struct ConcatenatedStudents **listOfStudents, int *numberOfConcatanetedStudents){
    int manageNumber = *numberOfConcatanetedStudents;
    if (checkingManageNumber(manageNumber))
        printf("There is no concataneted persons\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(listOfStudents+i) == NULL){
            manageNumber++;
            continue;
        }
        listOfStudents[i]->remove(listOfStudents[i]);
        listOfStudents[i] = NULL;
    }
    *numberOfConcatanetedStudents = 0;
}

void resetIDNumbers(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber = *numberOfPerson;
    if (checkingManageNumber(manageNumber))
        printf("There is no persons at all\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(arrayOfPerson+i) == NULL){
            manageNumber++;
            continue;
        }
        free(arrayOfPerson[i]->ID->number);
        arrayOfPerson[i]->ID->number = NULL;
    }
}

void resetIDSeries(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber = *numberOfPerson;
    if (checkingManageNumber(manageNumber))
        printf("There is no persons at all\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(arrayOfPerson+i) == NULL){
            manageNumber++;
            continue;
        }
        free(arrayOfPerson[i]->ID->series);
        arrayOfPerson[i]->ID->series = NULL;
    }
}

void resetAge(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber = *numberOfPerson;
    if (checkingManageNumber(manageNumber))
        printf("There is no persons at all\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(arrayOfPerson+i) == NULL){
            manageNumber++;
            continue;
        }
        free(arrayOfPerson[i]->age);
        arrayOfPerson[i]->age = NULL;
    }
}

void resetPosition(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber = *numberOfPerson;
    if (checkingManageNumber(manageNumber))
        printf("There is no persons at all\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(arrayOfPerson+i) == NULL){
            manageNumber++;
            continue;
        }
        free(arrayOfPerson[i]->position);
        arrayOfPerson[i]->position = NULL;
    }
}

void resetName(struct Person **arrayOfPerson, int *numberOfPerson){
    int manageNumber = *numberOfPerson;
    if (checkingManageNumber(manageNumber))
        printf("There is no persons at all\n");
    for (int i = 0; i < manageNumber; i++){
        if (*(arrayOfPerson+i) == NULL){
            manageNumber++;
            continue;
        }
        free(arrayOfPerson[i]->name);
        arrayOfPerson[i]->name = NULL;
    }
}

void resetInt(struct Person **arrayOfPerson, int *numberOfPerson){
    resetPrint();
    int manageNumber = getNumber();
    if (!manageNumber){
        errorPrint();
        return;
    }
    switch(manageNumber){
        case 1:resetIDNumbers(arrayOfPerson, numberOfPerson);return;
        case 2:resetIDSeries(arrayOfPerson, numberOfPerson);return;
        case 3:resetAge(arrayOfPerson, numberOfPerson);return;
        case 4:resetPosition(arrayOfPerson, numberOfPerson);return;
        default:errorPrint();return;
    }

}

void resetFloat(struct Person **arrayOfPerson, int *numberOfPerson){
    resetPrint();
    int manageNumber = getNumber();
    if (!manageNumber){
        errorPrint();
        return;
    }
    switch(manageNumber){
        case 1:resetIDNumbers(arrayOfPerson, numberOfPerson);return;
        case 2:resetIDSeries(arrayOfPerson, numberOfPerson);return;
        case 3:resetAge(arrayOfPerson, numberOfPerson);return;
        case 4:resetPosition(arrayOfPerson, numberOfPerson);return;
        default:errorPrint();return;
    }
}

void resetString(struct Person **arrayOfPerson, int *numberOfPerson){
    resetPrint();
    printf("To reset name - enter 5\n");
    int manageNumber = getNumber();
    if (!manageNumber){
        errorPrint();
        return;
    }
    switch(manageNumber){
        case 1:resetIDNumbers(arrayOfPerson, numberOfPerson);return;
        case 2:resetIDSeries(arrayOfPerson, numberOfPerson);return;
        case 3:resetAge(arrayOfPerson, numberOfPerson);return;
        case 4:resetPosition(arrayOfPerson, numberOfPerson);return;
        case 5:resetName(arrayOfPerson, numberOfPerson);
        default:errorPrint();return;
    }
}

void resetValue(struct Person **arrayOfPerson, int *numberOfPerson){
    typePrint();
    printf("Value of what type people you want to reset?\n");
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return;

    switch(manageNumber){
        case 1:resetInt(arrayOfPerson, numberOfPerson);return;
        case 2:resetFloat(arrayOfPerson, numberOfPerson);return;
        case 3:resetString(arrayOfPerson, numberOfPerson);return;
        default:errorPrint();return;
    }
}

void map(struct Person **arrayOfPerson, int *numberOfPerson){
    printf("What do you want to do?\n");
    printf("delete All array - enter 1\n");
    printf("get information about all - enter 2\n");
    printf("reset a specific value - enter 3\n");
    int manageNumber = getNumber();
    if (!*numberOfPerson){
        printf("There is no person to map");
        return;
    }

    switch(manageNumber){
        case 1:deleteAllPersonsOp(arrayOfPerson, numberOfPerson);return;
        case 2:printAll(arrayOfPerson, numberOfPerson);return;
        case 3:resetValue(arrayOfPerson, numberOfPerson);return;
        default:errorPrint();return;
    }
}

void printInformationByParameter(struct Person **arrayOfPerson, int *numberOfPerson){
    typePrint();
    printf("What type you want to use?\n");
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return;
    switch (manageNumber) {
        case 1:printInformationByParameterInt(arrayOfPerson, numberOfPerson);return;
        case 2:printInformationByParameterFloat(arrayOfPerson, numberOfPerson);return;
        case 3:printInformationByParameterString(arrayOfPerson, numberOfPerson);return;
        default:errorPrint();return;
    }
}

void printInformationByParameterInt(struct Person **arrayOfPerson, int *numberOfPerson) {
    struct Person *person = NULL;
    printByParameter();
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return;
    switch (manageNumber) {
        case 1:
            printf("Enter ID number\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 1);
            break;
        case 2:
            printf("Enter ID seriesr\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 2);
            break;
        case 3:
            printf("Enter age\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 3);
            break;
        case 4:
            printf("Enter position\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 4);
            break;
        default:errorPrint();return;
    }

    if (person != NULL)
        person->print(person);
}

void printInformationByParameterFloat(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    float number = 0;
    printByParameter();
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return;

    switch (manageNumber) {
        case 1:printf("Enter ID number\n");scanf("%f",&number);person = findByIDFloat(arrayOfPerson,numberOfPerson,number,1);break;
        case 2:printf("Enter ID seriesr\n");scanf("%f",&number);person = findByIDFloat(arrayOfPerson,numberOfPerson,number,2);break;
        case 3:printf("Enter age\n");scanf("%f",&number);person = findByIDFloat(arrayOfPerson,numberOfPerson,number,3);break;
        case 4:printf("Enter position\n");scanf("%f",&number);person = findByIDFloat(arrayOfPerson,numberOfPerson,number,4);break;
        default:errorPrint();return;
    }
    if (person != NULL)
        person->print(person);
}

void printInformationByParameterString(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    char *string = NULL;
    printByParameter();
    printf("To find by name - enter 5\n");
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return;
    switch (manageNumber) {
        case 1:printf("Enter ID number\n");string = get_str();person = findByIDString(arrayOfPerson,numberOfPerson,string,1);break;
        case 2:printf("Enter ID seriesr\n");string = get_str();person =  findByIDString(arrayOfPerson,numberOfPerson,string,2);break;
        case 3:printf("Enter age\n");string = get_str(); person = findByIDString(arrayOfPerson,numberOfPerson,string,3);break;
        case 4:printf("Enter position\n");string = get_str(); person = findByIDString(arrayOfPerson,numberOfPerson,string,4);break;
        case 5:printf("Enter name\n");string = get_str(); person = findByIDString(arrayOfPerson,numberOfPerson,string,5);break;
        default:errorPrint();return;
    }
    if (person != NULL)
        person->print(person);
}

struct Person *where(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    if (arrayOfPerson == NULL || *numberOfPerson == 0){
        printf("There is no person to use where\n");
        return NULL;
    }
    printf("To print information about person by specific parameter - enter 1\n");
    printf("To delete person by specific parameter - enter 2\n");
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return NULL;
    switch (manageNumber) {
        case 1:printInformationByParameter(arrayOfPerson, numberOfPerson);return NULL;
        case 2: person = deleteByParameter(arrayOfPerson, numberOfPerson);return person;
        default:errorPrint();return NULL;
    }
}

struct Person *deleteByParameter(struct Person **arrayOfPerson, int *numberOfPerson) {
    struct Person *person = NULL;
    deletePrintParameter();
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return NULL;
    switch (manageNumber) {
        case 1: person = deleteByParameterInt(arrayOfPerson, numberOfPerson);return person;
        case 2: person = deleteByParameterFloat(arrayOfPerson, numberOfPerson);return person;
        case 3: person = deleteByParameterString(arrayOfPerson, numberOfPerson);return person;
        case 4:return NULL;
        default:errorPrint();return NULL;
    }
}

struct Person *deleteByParameterInt(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    printByParameter();
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return NULL;
    switch (manageNumber) {
        case 1:
            printf("Enter ID number\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 1);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 2:
            printf("Enter ID series\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 2);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 3:
            printf("Enter age\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 3);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 4:
            printf("Enter position\n");
            manageNumber = getNumber();
            person = findByIDInt(arrayOfPerson, numberOfPerson, manageNumber, 4);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        default:errorPrint();return NULL;
    }
    printf("User wasn't found\n");
    return NULL;
}

struct Person *deleteByParameterFloat(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    float number = 0;
    printByParameter();
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return NULL;

    switch (manageNumber) {
        case 1:
            printf("Enter ID number\n");
            scanf("%f",&number);
            person = findByIDFloat(arrayOfPerson,numberOfPerson,number,1);
            if (person != NULL){
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 2:
            printf("Enter ID series\n");
            scanf("%f",&number);
            person = findByIDFloat(arrayOfPerson,numberOfPerson,number,2);
            if (person != NULL){
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 3:
            printf("Enter age\n");
            scanf("%f",&number);
            person = findByIDFloat(arrayOfPerson,numberOfPerson,number,3);
            if (person != NULL){
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        case 4:
            printf("Enter position\n");
            scanf("%f",&number);
            person = findByIDFloat(arrayOfPerson,numberOfPerson,number,4);
            if (person != NULL){
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was successfully deleted\n");
                return person;
            }
            break;
        default:errorPrint();return NULL;
    }
    printf("User wasn't found\n");
    return NULL;
}

struct Person *deleteByParameterString(struct Person **arrayOfPerson, int *numberOfPerson){
    struct Person *person = NULL;
    char *string = NULL;
    printByParameter();
    printf("To find by name - enter 5\n");
    int manageNumber = getNumber();
    if (checkingManageNumber(manageNumber))
        return NULL;
    switch (manageNumber) {
        case 1:
            printf("Enter ID number\n");
            string = get_str();
            person = findByIDString(arrayOfPerson,numberOfPerson,string,1);
            if (person != NULL){
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was deleted\n");
                return person;
            }
            break;
        case 2:
            printf("Enter ID series\n");
            string = get_str();
            person = findByIDString(arrayOfPerson,numberOfPerson,string,2);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was deleted\n");
                return person;
            }
            break;
        case 3:
            printf("Enter age\n");
            string = get_str();
            person = findByIDString(arrayOfPerson,numberOfPerson,string,3);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was deleted\n");
                return person;
            }
            break;
        case 4:
            printf("Enter position\n");
            string = get_str();
            person = findByIDString(arrayOfPerson,numberOfPerson,string,4);
            if (person != NULL) {
                deletePerson(person);
                setNull(arrayOfPerson, numberOfPerson, person);
                printf("User was deleted\n");
                return person;
            }
            break;
        case 5:
            printf("Enter name\n");
                string = get_str();
                person = findByIDString(arrayOfPerson,numberOfPerson,string,5);
                if (person != NULL) {
                    deletePerson(person);
                    setNull(arrayOfPerson, numberOfPerson, person);
                    printf("User was deleted\n");
                    return person;
                }
                break;
        default:errorPrint();return NULL;
    }
    printf("User wasn't found\n");
    return NULL;
}

void setNull(struct Person **arrayOfPerson, int *numberOfPerson , struct Person *person) {
    int counter = *numberOfPerson;
    for (int i = 0; i < counter; i++) {
        if (arrayOfPerson[i] == NULL) {
            counter++;
            continue;
        }
        if (arrayOfPerson[i] == person) {
            arrayOfPerson[i] = NULL;
            *numberOfPerson = *numberOfPerson - 1;
        }
    }
}

void normalizeConcatenatedArray(struct Person *person, struct ConcatenatedStudents **listOfStudents, int *numberOfConcatanetedStudents){
    if (person == NULL)
        return;
    int counter = *numberOfConcatanetedStudents;
    int counter2;
    int numberOfDeleting = 0;
    for (int i = 0; i <counter; i++){
        if (listOfStudents[i] == NULL){
            counter++;
            continue;
        }
        counter2 = listOfStudents[i]->numberOfStudents;
        for (int j = 0; j < counter2; j ++){
            if (listOfStudents[i]->student[j] == NULL){
                counter2++;
                continue;
            }
            if (listOfStudents[i]->student[j] == person){
                listOfStudents[i]->remove(listOfStudents[i]);
                listOfStudents[i] = NULL;
                numberOfDeleting++;
                }
        }
    }
    *numberOfConcatanetedStudents = *numberOfConcatanetedStudents - numberOfDeleting;
    if (numberOfDeleting){
        printf("Also %d group/groups of people was/were edited\n",numberOfDeleting);
    }
}