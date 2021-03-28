#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _printf - print a formatted text
 * @format: str with the text and format
 * Return: the number of bytes that print
 */

int _printf(const char *format, ...)
{
	int bytes  = 0;
	char *head, *current, *init;
	int (*execute)(va_list ap);
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);
	current = head = init = (char *) format;

	while (*head)
	{
		if (*head == '%' || *current == '%')
		{
			if (*current != '%')
				current = head;

			if (*(head + 1) == 32 || *(head + 1) == 9)
			{
				head++;
				continue;
			}
			execute = get_ops_function(*(head + 1), &bytes);
			bytes += execute(ap), current = init;
			head += 2;
		}
		else
			bytes += write(1, head++, 1);
	}
	va_end(ap);
	return (bytes);
}
