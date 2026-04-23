#include <stdio.h>

struct tdate {
    int day;
    int month;
    int year;
};
typedef struct tdate data;

void setDate(data *d, int day, int month, int year);
int getDate(data d, char type);
void showDate(data d);
int dataComp(data d1, data d2);
int getDiff(data d1, data d2);
int isLeapYear(int y);
int calculaDiasByDate(data d);
int getDayFromYear(data d);
