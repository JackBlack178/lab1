void runningApp();
void runningApp2();
void errorPrint();
void typePrint();
int checkingManageNumber(int manageNumber);

struct Person *findByIDInt(struct Person ** arrayPersons, int *numberOfPeople, int ID, int key);
struct Person *findByIDFloat(struct Person ** arrayPersons, int *numberOfPeople, float ID, int key);
struct Person *findByIDString(struct Person ** arrayPersons, int *numberOfPeople, char* string, int key);

void printUserWithIntType(struct Person ** arrayPersons, int *numberOfPeople);
void printUserWithFloatType(struct Person ** arrayPersons, int *numberOfPeople);
void printUserWithStringType(struct Person ** arrayPersons, int *numberOfPeople);
void printMenu();
void printAll(struct Person ** arrayPersons, int *numberOfPeople);
void printConcatenatedPerson(struct ConcatenatedStudents **listOfStudents, int numberOfConcatenatedStudents);
void deleteAllConcatenatedPerson(struct ConcatenatedStudents **listOfStudents, int *numberOfConcatenatedStudents);
struct ConcatenatedStudents **createListOfPerson(struct ConcatenatedStudents **listOfStudents, int *numberOfConcatenatedStudents, struct Person **arrayOfPerson, int *numberOfPerson);
void map(struct Person **arrayOfPerson, int *numberOfPerson);
void resetPrint();
void printByParameter();
void deletePrintParameter();

void resetIDNumbers(struct Person **arrayOfPerson, int *numberOfPerson);
void resetIDSeries(struct Person **arrayOfPerson, int *numberOfPerson);
void resetAge(struct Person **arrayOfPerson, int *numberOfPerson);
void resetPosition(struct Person **arrayOfPerson, int *numberOfPerson);
void resetName(struct Person **arrayOfPerson, int *numberOfPerson);
void resetValue(struct Person **arrayOfPerson, int *numberOfPerson);
void resetString(struct Person **arrayOfPerson, int *numberOfPerson);
void resetFloat(struct Person **arrayOfPerson, int *numberOfPerson);
void resetInt(struct Person **arrayOfPerson, int *numberOfPerson);

struct Person *where(struct Person **arrayOfPerson, int *numberOfPerson);
void printInformationByParameter(struct Person **arrayOfPerson, int *numberOfPerson);
void printInformationByParameterInt(struct Person **arrayOfPerson, int *numberOfPerson);
void printInformationByParameterFloat(struct Person **arrayOfPerson, int *numberOfPerson);
void printInformationByParameterString(struct Person **arrayOfPerson, int *numberOfPerson);

struct Person *deleteByParameter(struct Person **arrayOfPerson, int *numberOfPerson);
struct Person *deleteByParameterInt(struct Person **arrayOfPerson, int *numberOfPerson);
struct Person *deleteByParameterFloat(struct Person **arrayOfPerson, int *numberOfPerson);
struct Person *deleteByParameterString(struct Person **arrayOfPerson, int *numberOfPerson);
void setNull(struct Person **arrayOfPerson, int *numberOfPerson , struct Person *person);
void normalizeConcatenatedArray(struct Person *person, struct ConcatenatedStudents **listOfStudents, int *numberOfConcatanetedStudents);

void printMenu2();
