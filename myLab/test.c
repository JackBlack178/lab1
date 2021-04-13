#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "processValues.h"
#include "menu.h"
float frand() {
    return (float)(rand() + 1./rand());
}

char *randomString(){
    // range 1 to 100
    int number;
    char *string = (char*)malloc(sizeof(char*)*100);
    for (int i = 0; i< 30; i++){
        number = rand()%12;
        switch(number){
            case 1:string[i] = ' ';break;
            case 2:string[i] = 'T';break;
            case 3:string[i] = 'o';break;
            case 4:string[i] = 'b';break;
            case 5:string[i] = 'D';break;
            case 6:string[i] = 'T';break;
            case 7:string[i] = 'G';break;
            case 8:string[i] = 'J';break;
            case 9:string[i] = 'U';break;
            case 0:string[i] = 'p';break;
            case 10:string[i] = 'a';break;
            case 11:string[i] = 'C';break;
            case 12:string[i] = 'Y';break;
            default:break;
        }
    }
    return string;
}

int testInt(){
    int numberOfTest = 1000000;
    struct Person **person = (struct Person**)malloc(sizeof(struct Person**)*2);
    struct Person *tempPerson = (struct Person*)malloc(sizeof(struct Person*));
    for (int i = 0; i < numberOfTest; i++){
        int number1 = rand(), number2 = rand();
        int series1 = rand(), series2 = rand();
        int age1 = rand(), age2 = rand();
        int position1 = rand(), position2 = rand();
        struct Person *person1 = createNewPerson(&series1,&number1,NULL,&age1,&position1,sizeof(int),&intFunction);
        struct Person *person2 = createNewPerson(&series1,&number1,NULL,&age1,&position1,sizeof(int),&intFunction);
        person[0] = person1;
        person[1] = person2;
        int number = 2;
        tempPerson = findByIDInt(person,&number, number1, 1);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDInt(person,&number, series1, 2);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDInt(person,&number, age1, 3);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDInt(person,&number, position1, 4);
        if (tempPerson != person1)
            return 0;
        free(person1);
        free(person2);

    }
    printf("%d tested done. No mistakes\n",numberOfTest);
    return 1;

}

int testFloat(){
    int numberOfTest = 1000000;
    struct Person **person = (struct Person**)malloc(sizeof(struct Person**)*2);
    struct Person *tempPerson = (struct Person*)malloc(sizeof(struct Person*));
    for (int i = 0; i < numberOfTest; i++){
        float number1 = frand(), number2 = frand();
        float series1 = frand(), series2 = frand();
        float age1 = frand(), age2 = frand();
        float position1 = frand(), position2 = frand();
        struct Person *person1 = createNewPerson(&series1,&number1,NULL,&age1,&position1,sizeof(float),&floatFunction);
        struct Person *person2 = createNewPerson(&series1,&number1,NULL,&age1,&position1,sizeof(float),&floatFunction);
        person[0] = person1;
        person[1] = person2;
        int number = 2;
        tempPerson = findByIDFloat(person,&number, number1, 1);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDFloat(person,&number, series1, 2);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDFloat(person,&number, age1, 3);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDFloat(person,&number, position1, 4);
        if (tempPerson != person1)
            return 0;
        free(person1);
        free(person2);

    }
    printf("%d tested done. No mistakes\n",numberOfTest);
    return 1;
}

int testString(){
    int numberOfTest = 1000;
    struct Person **person = (struct Person**)malloc(sizeof(struct Person**)*2);
    struct Person *tempPerson = (struct Person*)malloc(sizeof(struct Person*));
    for (int i = 0; i < numberOfTest; i++){
        char *number1 = randomString();
        char *number2 = randomString();
        char *series1 = randomString();
        char *series2 = randomString();
        char *age1 = randomString();
        char *age2 = randomString();
        char *position1 = randomString();
        char *position2 = randomString();
        char *name1 = randomString();
        char *name2 = randomString();
        struct Person *person1 = createNewPerson(series1,number1,name1,age1,position1,sizeof(char),&charFunction);
        struct Person *person2 = createNewPerson(series1,number1,name2,age1,position1,sizeof(char),&charFunction);
        person[0] = person1;
        person[1] = person2;
        int number = 2;
        tempPerson = findByIDString(person,&number, number1, 1);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDString(person,&number, series1, 2);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDString(person,&number, age1, 3);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDString(person,&number, position1, 4);
        if (tempPerson != person1)
            return 0;
        tempPerson = findByIDString(person,&number, name1, 5);
        if (tempPerson != person1)
            return 0;
        free(person1);
        free(person2);

    }
    printf("%d tested done. No mistakes\n",numberOfTest);
    return 1;
}

int test(){
    int numberOfPerson = 1000;

    int numberI;
    int seriesI;
    int ageI;
    int positionI;
    float numberF;
    float seriesF;
    float ageF;
    float positionF;
    char *numberS;
    char *seriesS;
    char *ageS;
    char *positionS;
    char *nameS;
    struct Person **person = (struct Person**)malloc(sizeof(struct Person**)*numberOfPerson);
    for (int i = 0; i < numberOfPerson; i++){
        switch(rand()%3){
            case 0:
                numberI = rand();
                seriesI=rand();
                ageI=rand();
                positionI=rand();
                person[i] = createNewPerson(&seriesI,&numberI,NULL,&ageI,&positionI,sizeof(int),&intFunction);
                break;
            case 1:
                numberF = frand();
                seriesF = frand();
                ageF = frand();
                positionF = frand();
                person[i] = createNewPerson(&seriesF,&numberF,NULL,&ageF,&positionF,sizeof(float),&floatFunction);
                break;
            case 2:
                numberS = randomString();
                seriesS = randomString();
                ageS = randomString();
                positionS = randomString();
                nameS = randomString();
                person[i] = createNewPerson(seriesS,numberS,nameS,ageS,positionS,sizeof(char),&charFunction);
        }
    }
    sorted(person,&numberOfPerson);
    for (int i = 0; i<numberOfPerson-1;i++) {
        if (person[i]->func > person[i + 1]->func)
            return 0;
        if (person[i] == person[i + 1] && person[i]->func == &intFunction &&
            (int *) person[i]->ID->number > (int *) person[i + 1]->ID->number)
            return 0;
        if (person[i] == person[i + 1] && person[i]->func == &charFunction &&
            (float *) person[i]->ID->number > (float *) person[i + 1]->ID->number)
            return 0;
        if (person[i] == person[i + 1] && person[i]->func == &charFunction && person[i]->func->isGreaterThan(person[i]->name,person[i+1]->name))
            return 0;
    }
    printf("No mistakes\n");
    return 1;
}
