#include <iostream>
#include <stdio.h>

long long get_fibbonachi_via_recursion(int number);

int main(void)
{
    int number;
    scanf_s("%d", &number);
    printf("%lld", get_fibbonachi_via_recursion(number));
    return 0;
}

long long get_fibbonachi_via_recursion(int number)
{
    static long buffer[] = { 1, 1 };
    if (number == 0)
    {
        return 0;
    }
    if (number == 1)
    {
        return 1;
    }
    if (buffer[number] == 0)
    {
        buffer[number] = get_fibbonachi_via_recursion(number - 2) + get_fibbonachi_via_recursion(number - 1);
    }
    return buffer[number];
}