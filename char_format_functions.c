#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * prt_chr - print  character
 * @ap: list of characts
 *
 * Return: nmber of bytes
 */

int format_char(va_list ap, char **buffer)
{
	char p;

	p = (char) va_arg(ap, int);
	*(*buffer) = p;
	return (1);
}

/**
 * prt_str - prints a string 
 * @ap: string char by char
 *
 * Return: bytes total
 */
int format_str(va_list ap, char **buffer)
{
	char *p, *n = "(null)", *copy = *buffer;
	int bytes = 0, e = 0;

	p = va_arg(ap, char *);
	if (p)
	{
		while (*(p + e))
			*copy++ = p[e++], bytes++;
	}
	else{
		while ((*copy++ = *n++))
			bytes++;
	}
	return (bytes);
}

/**
 * prt_pct - prints a % sign
 * @ap: string char by char
 *
 * Return: bytes total
 */

int format_percent(va_list ap, char **buffer)
{
	(void) ap;

	*(*buffer) = '%';
	return (1);
}

/**
 * prt_ukn - prints an unnonewd type
 * @ap: string char by char
 *
 * Return: bytes total
 */

int format_unkn(va_list  __attribute__((unused)) ap, char **buffer)
{
	char *n, *copy = *buffer;
	int bytes = 0;
	(void) buffer;

	n = "(null)";
	while ((*copy++ = *n++))
		bytes++;
	return (bytes);
}
