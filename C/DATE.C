#include <stdio.h>

day_of_year(year, month, day)
int year, month, day;
{
  int day_tab[2][13];
  day_tab = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; i++)
    day += day_tab[leap][i];
  return(day);
}

month_day(year, yearday, pmonth, pday)
int year, yearday, *pmonth, *pday;
{
  int day_tab[2][13];
  day_tab = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > day_tab[leap][i]; i++)
    yearday -= day_tab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

main() {
  printf("%d", day_of_year(2012, 3, 4);
}
