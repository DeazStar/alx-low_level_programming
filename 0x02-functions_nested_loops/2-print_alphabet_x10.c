#include "main.h"

/**
 * Description: function that prints 10 times the alphabet, in lowercase.
 *
 */

void print_alphabet_x10(void)
{
    int i;
    int j;
    for(i = 0; i < 10; i++)
    {
        for(j = 'a'; j <= 'z'; j++ )
        {
            _putchar(j);
        }
        _putchar('\n');
    }
}
