#include <stdio.h>
/**
 * main -prints the numbers from 0 to 9
 * 
 * Return: Always (0)
 */
int main(void)
{
    char n;

    for (n = '0'; n < '10'; n++)
    {
        putchar(n);
    }

    putchar('\n');

    return (0);
}