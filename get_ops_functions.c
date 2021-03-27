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

int (*get_ops_function(char s, int *bytes))(va_list ap)
{
	int i = 0;
	d_dt data_types[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent}
	};

	while (i < 3)
	{
		if (s == *data_types[i].type)
			return (data_types[i].f);
		i++;
	}
	*bytes += write(1, "%", 1), *bytes += write(1, &s, 1);
	return (format_unkn);
}
