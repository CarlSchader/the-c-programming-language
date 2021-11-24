#include<stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day) {
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;
    
    if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;

    for (month--; month > 0; month--)
        day += daytab[leap][month];
    
    return day;
}

void month_day(int year, int day, int *mp, int *dp) {
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;

    if (day < 1 || (leap && day > 366) || (!leap && day > 365)) {
        *mp = *dp = -1;
        return;
    }
    
    for (*mp = 1; day > daytab[leap][*mp]; (*mp)++)
        day -=  daytab[leap][*mp];
    *dp = day;
}

int main() {
    printf("%d\n", day_of_year(1988, 2, 29));
    int m, d;
    month_day(1988, 60, &m, &d);
    printf("%d %d\n", m, d);
}