#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>

int _printf(const char *format, ...);
int (*get_ops_function(char s, char **buffer, int *bytes))(va_list ap, char **format);
int format_char(va_list ap, char **buffer);
int format_str(va_list ap, char **buffer);
int format_percent(va_list ap, char **buffer);
int format_nil(va_list ap, char **buffer);
int format_unkn(va_list ap, char **buffer);
int format_int(va_list ap, char **buffer);
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
	int (*f)(va_list ap, char **buffer);
} d_dt;

#endif /* _HOLBERTON_H_ */
