#include "holberton.h"
#include <unistd.h>
#include <stdio.h>

int print_int(unsigned int p, char *buf);

/**
 * format_int - print int format
 * @ap: list or arguments
 *
 * Return: int
 */
int format_int(va_list ap, char **buffer)
{
	int p;
	char *copy = *buffer;
	int byte = 0;

	p = va_arg(ap, int);
	if (p < 0)
		*copy++ = '-', p = -p;
	byte = print_int(p, copy);
	return (byte);
}

/**
 * print_int - convert string to int recursively
 * @p: unsigned int
 *
 * Return: int
 */
int print_int(unsigned int p, char *buf)
{
	int a = 48, byte = 0;

	if (p / 10 == 0)
	{
		a = p + a;
		*buf = (char) a;
		buf++;
		return (1);
	}
	byte = print_int(p / 10, buf);
	a = (p % 10) + a;
	*buf = (char) a;
	return (byte);
}

unsigned int to_binary(unsigned int p)
{
	unsigned int res = 0;
	
	res = (p == 0 || p == 1) ? p : ((p % 2) + 10  * to_binary(p / 2));
	return(res);
}
