#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main (void)
{
	char a = 'H';
	int len = 0, len2 = 0;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Expected: [%c]\n", a);
	_printf("Result: [%c]\n", a);
	printf("Expected: %s\n","Fuck");
        _printf("Result: %s\n", "FUCK");
	printf("Expected: [%%]\n");
        _printf("Result: [%%]\n");
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len, len2);
	printf("Que visajes %k\n", "lola");
	return (0);
}
