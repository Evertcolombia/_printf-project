#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * get_ops_function - select the format
 * @s: char to switch
 * Return: a pointer to the function
 */

int (*get_ops_function(char s, char **buffer, int *bytes))(va_list ap, char **buffer)
{
	int i = 0;
	d_dt data_types[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent},
		{"i", format_int},
		{"d", format_int}
	};

	while (i < 5)
	{
		if (s == *data_types[i].type)
			return (data_types[i].f);
		i++;
	}
	*(*buffer++) = '%', *(*buffer++) = s, bytes += 2;
	return (format_unkn);
}
