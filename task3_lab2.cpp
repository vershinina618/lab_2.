#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

void power(int number, int source, int target);
char int_to_char(int number);

int main(void)
{
    int number, source, target;
    scanf("%d %d %d", &number, &source, &target);
    if (target > 32 || source > 11)
    {
        printf("error");
    }
    else
    {
        power(number, source, target);
    }
}

char int_to_char(int number)
{
    if (number >= 0 && number <= 9)
    {
        return number + '0';
    }
    else
    {
        return number + 'A' - 10;
    }
}

void power(int number, int source, int target)
{
    int result_in_decimal;
    int lengt = sizeof(number) / sizeof(int);
    char result[100];

    while (number > 0)
    {
        static int pow = 1;
        result_in_decimal += number % 10 * pow;
        pow *= source;
        number /= 10;
    }

    while (result_in_decimal > 0)
    {
        static int q = 0;
        result[q++] = int_to_char(result_in_decimal % target);
        result_in_decimal /= target;
    }

    int length = strlen(result);
    for (int q = 0; q < length / 2; q++)
    {
        result[q] += result[length - 1 - q];
        result[length - 1 - q] = result[q] - result[length - q - 1];
        result[q] -= result[length - 1 - q];
    }

    printf("%s", result);
}