#include "processValues.h"
#include <stdio.h>
#include "stdlib.h"
#include "person.h"
#include "string.h"
#include "menu.h"
#define max(a,b) (a) > (b) ? (a) : (b)
#define and &&
#include "test.h"

int * getInt() {
    int *number = (int*)malloc(sizeof(int));
    *number = getNumber();
    if (*number == -1)
        return NULL;
    if (*number == 0){
        printf("You've entered the wrong value\n");
        printf("Value 0 is set as default\n");
        }
    return number;
}

float * getFloat() {
    float *number = (float*)malloc(sizeof(float));

    printf("Enter a decimal number or enter -1.0 if you do not want to enter any value:\n");
    scanf("%f", number);
    if (*number == -1.0)
        return NULL;
    return number;
}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }

    return res;
}

struct Person * createIntPerson(){
    int manageNumber;
    int * series = (int*)malloc(sizeof(int));
    int * number = (int*)malloc(sizeof(int));
    int * age = (int*)malloc(sizeof(int));
    int * position = (int*)malloc(sizeof(int));
    int * name = NULL;
    struct Person * person;
    printf("If you want to fill person with random data press 0.Otherwise enter any other number\n");
    manageNumber = getNumber();
    if(!manageNumber) {
        *series = rand();
        *number = rand();
        *age = rand();
        *position = rand() % 2;
        person = createNewPerson(series, number, name, age, position, sizeof(int), &intFunction);
        return person;
    }
    printf("Creating an integer person\n");
    printf("Enter a series of document:\n");
    series = getInt();
    printf("Enter a number of document:\n");
    number = getInt();
    printf("Enter your age:\n");
    age = getInt();
    printf("Enter 1 if you're professor and 0 if you're student\n");
    position = getInt(); //1 for professor and 0 for students
    person = createNewPerson(series,number,name,age,position,sizeof(int),&intFunction);
    return person;
}

struct Person * createFloatPerson(){
    int manageNumber;
    float * series = (float*)malloc(sizeof(float));
    float  * number = (float*)malloc(sizeof(float));
    float * age = (float*)malloc(sizeof(float));
    float * position = (float*)malloc(sizeof(float));
    float * name = NULL;
    struct Person * person;
    printf("If you want to fill person with random data press 0.Otherwise enter any other number\n");
    manageNumber = getNumber();
    if(!manageNumber) {
        *series = frand();
        *number = frand();
        *age = frand();
        *position = frand();
        person = createNewPerson(series, number, name, age, position, sizeof(float), &floatFunction);
        return person;
    }

    printf("Creating a decimal person\n");
    printf("Enter a series of document:\n");
    series = getFloat();
    printf("Enter a number of document:\n");
    number = getFloat();
    printf("Enter your age:\n");
    age = getFloat();
    printf("print 1 if you're professor and 0 if you're student\n");
    position = getFloat();
    person = createNewPerson(series,number,name,age,position,sizeof(float),&floatFunction);
    return person;
}

struct Person * createStringPerson(){
    int manageNumber;
    char * series = NULL;
    char  * number = NULL;
    char * age = NULL;
    char * position = NULL;
    char * name = NULL;
    struct Person * person;
    printf("If you want to fill person with random data press 0.Otherwise enter any other number\n");
    manageNumber = getNumber();
    if(!manageNumber) {
        series = randomString();
        number = randomString();
        age = randomString();
        position = randomString();
        name = randomString();
        person = createNewPerson(series, number, name, age, position, sizeof(char ), &charFunction);
        return person;
    }

    int maxSizeOfString;
    printf("Creating a string person\n");
    printf("Enter your name\n");
    char c;
    scanf("%c",&c);
    name = get_str();
    printf("Enter your age\n");
    age = get_str();
    printf("Enter your status (professor/student)\n");
    position = get_str();
    printf("Enter series of your document\n");
    series = get_str();
    printf("Enter number of your document\n");
    number = get_str();
    maxSizeOfString = max(len(name),max(len(age),max(len(position),max(len(series),len(number)))));
    person = createNewPerson(series,number,name,age,position,(sizeof(char)*maxSizeOfString),&charFunction);
    return person;
}

void normalizeRow(struct Person **personArray,const  int *numberOfPeople){
    int counter = 0;
    int numberOfDeletedPerson = 0;
    for (int i = 0; i < *numberOfPeople;i++){
        if (*(personArray+i) == NULL){
            numberOfDeletedPerson++;
        }
    }
    for (int i = 0; i < *numberOfPeople and counter < numberOfDeletedPerson; i++){
        if ((personArray[i]) != NULL)
            continue;
        for (int j = *numberOfPeople -i; j>=0;j--){
            if (personArray[j] != NULL) {
                personArray[i] = personArray[j];
                personArray[j] = NULL;
            }
        }
    }
}

void sorted(struct Person **personArray,const  int *numberOfPeople){
    normalizeRow(personArray, numberOfPeople);
    int counter = *numberOfPeople;
    struct Person *person1;
    struct Person *person2;
    for (int i = 0; i < counter-1; i++)
    {
        for (int j = counter - 1; j > i; j--)
        {
            person1 = *(personArray+j-1);
            person2 = *(personArray+j);
            if (person1 == NULL || person2 == NULL){
                counter++;
                continue;
            }
            if (person1->func>person2->func) // Comparing by address
            {
                personArray[j-1] = person2;
                personArray[j] = person1;
            }
        }
    }
    for (int i = 0; i < counter-1; i++)
    {
        for (int j = counter - 1; j > i; j--)
        {
            person1 = *(personArray+j-1);
            person2 = *(personArray+j);
            if (person1 == NULL || person2 == NULL) {
                counter++;
                continue;
            }

            if (person1 == person2 && person1->func == &charFunction && person1->func->isGreaterThan(person1->name,person2->name)){
                personArray[j-1] = person2;
                personArray[j] = person1;
            }

            if (person1->func == person2->func && (person1->func->isGreaterThan(person1->ID->number,person2->ID->number))) // Comparing by address
            {
                personArray[j-1] = person2;
                personArray[j] = person1;
            }
        }
    }
    printf("Array was sorted\n");
}

int getNumber(){
    char *enteredNumber;
    enteredNumber = get_str();
    if (enteredNumber == NULL)
        return 0;
    for (int i = 0; i <len(enteredNumber);i++){
        if (enteredNumber[i] == '.')
            return 0;
    }
    return atoi(enteredNumber);
}

struct Person ** createPersonsOp(struct Person ** arrayPersons, int *numberOfPeople){
    int n;
    int counter = *numberOfPeople;
    printf("\nHow many people you want to create?\n");
    int manageNumber = getNumber();
    if (!manageNumber) {
        errorPrint();
        return NULL;}
    if (!*numberOfPeople)
        arrayPersons = (struct Person**)malloc(sizeof(struct Person*) *manageNumber);

    else
        arrayPersons = (struct Person**)realloc(arrayPersons,sizeof(struct Person*)* manageNumber);
    for (int i = *numberOfPeople;i<counter+manageNumber;){
            printf("What type of person do you want to do?\n");
            typePrint();
            n = getNumber();
            switch(n) {
                case 1:
                    *(arrayPersons+i) = createIntPerson();
                    *numberOfPeople = *numberOfPeople + 1;
                    i++;
                    break;
                case 2:
                    *(arrayPersons+i) = createFloatPerson();
                    *numberOfPeople = *numberOfPeople + 1;
                    i++;

                    break;
                case 3:
                    *(arrayPersons+i) = createStringPerson();
                    *numberOfPeople = *numberOfPeople + 1;
                    i++;

                    break;
                case 4:
                    return arrayPersons;

                default:
                    errorPrint();
                    break;
        }
    }
    return arrayPersons;
}

void deleteAllPersonsOp(struct Person ** arrayPersons, int *numberOfPeople){
    int counter = *numberOfPeople;
    for (int i = 0; i < counter; i++){
        if (*(arrayPersons+i) == NULL){
            counter++;
            continue;
        }
        else{
            deletePerson(*(arrayPersons+i));
            arrayPersons[i] = NULL;
        }
    }
    printf("All users were deleted\n");
    *numberOfPeople = 0;
}

int getDec(int *n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf("%d", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Bad value. Try again!\n");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}