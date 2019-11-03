#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>

/**
 * struct data - contains data in two columns
 * @type: data type
 * @f: function type
 *
 * Description: contains data in two columns
 */
typedef struct data
{
	char *type;
	int (*f)(va_list ap);
} d_dt;

int _printf(const char *format, ...);
int (*get_ops_function(char s))(va_list ap);
int format_char(va_list ap);
#endif /* _HOLBERTON_H_ */
