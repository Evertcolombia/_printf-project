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
	
	printf("Expected: [%c]\n", a);
	_printf("Result: [%c]\n", a);
	printf("Expected: %s\n","Fuck");
        _printf("Result: %s\n", "FUCK");
	printf("Expected: [%%]\n");
        _printf("Result: [%%]\n");


	return (0);
}
