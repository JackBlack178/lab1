int * getInt();
float * getFloat();
char *get_str();
struct Person * createIntPerson();
struct Person * createFloatPerson();
struct Person * createStringPerson();


void sorted(struct Person **personArray,const  int *numberOfPeople);
void normalizeRow(struct Person **personArray,const  int *numberOfPeople);
int getNumber();

struct Person ** createPersonsOp(struct Person ** arrayPersons, int *numberOfPeople);
void deletePersonOp(struct Person ** arrayPersons, int *numberOfPeople);
void deleteAllPersonsOp(struct Person ** arrayPersons, int *numberOfPeople);
int getDec(int *n, int down, int up);


