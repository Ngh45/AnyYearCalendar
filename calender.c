//(Year Code + Month Code + Century Code + Date Number - Leap Year Code) mod 7
/*    1700s = 4
      1800s = 2
      1900s = 0
      2000s = 6
      2100s = 4
      2200s = 2
      2300s = 0
*/
#include <stdio.h>

int century(int year)
{
    int century;
    if (year >= 1700 && year < 1800)
    {
        century = 4;
    }
    else if (year >= 1800 && year < 1900)
    {
        century = 2;
    }
    else if (year >= 1900 && year < 2000)
    {
        century = 0;
    }
    else if (year >= 2000 && year < 2100)
    {
        century = 6;
    }
    else if (year >= 2100 && year < 2200)
    {
        century = 4;
    }
    else if (year >= 2200 && year < 2300)
    {
        century = 2;
    }
    else
    {
        century = 0;
    }

    return century;
}

int day_code(int year, int date, int month)
{
    int month_code[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int leap = 0, centuryCode = century(year);
    (year % 4 == 0) ? leap = 1 : 0;
    year %= 100;
    int dayCode = ((year + year / 4) % 7 + centuryCode + month_code[month] + date - leap) % 7;
    return dayCode;
}

int main()
{
    // initializing Variable
    int i, j, k;
    int year;
    printf("Enter The Year = ");
    scanf("%d", &year);
    int current = day_code(year, 1, 0); //--> initializing day code
    char month[12][20] = {"Januarry", "February", "March", "April",
                          "May", "June", "July", "August", "September",
                          "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ((year % 4) == 0) ? days[1] = 29 : 0;

    printf("             %d\n", year);

    // Itaration of day and month
    for (k = 0; k < 12; k++)
    {

        printf("  ---------%s------------\n", month[k]);
        printf("  Sun Mon Tue Wed Thu Fri Sat\n");

        for (i = 0; i < current; i++)
        {
            printf("    ");
        }

        for (j = 1; j <= days[k]; j++)
        {
            printf("%4d", j);
            if (i++ == 6)
            {
                i = 0;
                printf("\n");
            }
        }

        current = i;
        if (j)
        {
            printf("\n\n");
        }
    }
    return 0;
}