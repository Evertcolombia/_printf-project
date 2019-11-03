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
	
	printf("Expected: [%c] %s\n", a, "Fuck");
	_printf("Result: [%c] %s\n", a, "FUCK");

	return (0);
}
