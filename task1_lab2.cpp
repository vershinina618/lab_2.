#include <iostream>
#include <stdio.h>

long long get_fibbonachi_via_recursion(int number);
int main()
{
    int number;
    scanf_s("%d", &number);
    printf("%lld", get_fibbonachi_via_recursion(number));

    return 0;
}

long long get_fibbonachi_via_recursion(int number)
{
    long long buffer[100];
    buffer[0] = 0;
    buffer[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        buffer[i % 2] = buffer[0] + buffer[1];
    }

    return buffer[number % 2];
}
