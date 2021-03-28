#include "holberton.h"
#include <unistd.h>
#include <stdio.h>

int print_int(unsigned int p);

/**
 * format_int - print int format
 * @ap: list or arguments
 *
 * Return: int
 */
int format_int(va_list ap)
{
	int p;

	p = va_arg(ap, int);
	if (p < 0)
		write(1, "-", 1), p = -p;

	return (print_int(p) + 1);
}

/**
 * print_int - convert string to int recursively
 * @p: unsigned int
 *
 * Return: int
 */
int print_int(unsigned int p)
{
	int a = 48, byte = 0;

	if (p / 10 == 0)
	{
		a = p + a;
		return (write(1, &a, 1));
	}
	byte = 1 + print_int(p / 10);
	a = (p % 10) + a;
	write(1, &a, 1);
	return (byte);
}
