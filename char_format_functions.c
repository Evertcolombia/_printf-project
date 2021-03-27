#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * prt_chr - print  character
 * @ap: list of characts
 *
 * Return: nmber of bytes
 */

int format_char(va_list ap)
{
	char p;

	p = (char) va_arg(ap, int);
	return(write(1, &p, 1));
}

/**
 * prt_str - prints a string 
 * @ap: string char by char
 *
 * Return: bytes total
 */
int format_str(va_list ap)
{
	char *p;
	int bytes = 0, e = 0;

	p = va_arg(ap, char *);
	if (p)
	{
		while (*(p + e))
		{
			bytes += write(1, p + e, 1);
			e++;
		}
	}
	else
		bytes += write(1, "(null)", 6);
	return (bytes);
}

/**
 * prt_pct - prints a % sign
 * @ap: string char by char
 *
 * Return: bytes total
 */

int format_percent(va_list ap)
{
	(void) ap;

	return (write(1, "%", 1));
}

/**
 * prt_ukn - prints an unnonewd type
 * @ap: string char by char
 *
 * Return: bytes total
 */

int format_unkn(va_list  __attribute__((unused)) ap)
{
	return (write(1, "(null)", 6));
}
