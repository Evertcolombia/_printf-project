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
	/* 1- init variables for counter and bytes */
	int i = 0, byte  = 0;

	/* 2- Init a funtion pointer that will be return
	   for this function */
	int (*execute)(va_list ap);
	
	/* 3- Init the va_list with the unknown arguments, 
	   then start it */
	va_list ap;
	va_start(ap, format);

	/* 4- if format constant is empty return -1 */
	if (!format)
		return (-1);

	/* 5- While format can be traverse with a counter */
	while (format[i])
	{
		/* 6- If format in his index is same to %
		     we have to look wich's the follow character */
		if (format[i] == '%')
		{
			/* 6.1- While format in the next character
			   of % is equal to ' ' or /t, plus index in
			   one thill the space o tab end*/
			while (format[i + 1] == 32 || format[i + 1] == 9)
				i++;

			/* 6.2- If format in his index + 1 is true
			   we need to use the function pointer to get
			   an instance of the correct function for 
			   the format character, it will look
			   in our struct*/
			if (format[i + 1])
			{
				/* 6.3- function pointer will point to
				    the get_ops_functions and return
				    the correct function for the  
				    format that we send*/
				execute = get_ops_function(format[i +1]);
				/* 6.4- Now use the intance that
				     contains our function for the 
				     correct format, pasing our ap 
				     (argument list) and storage the 
				     number of bytes of the result in
				     the byte function. This function 
				     will print the arguments en ap in 
				     correct format*/
				byte = byte + execute(ap);

				/* plus i in one to sum the count */
				i++;
			}
			/* 6.5- If format in his index + 1 is false 
				return -1 */
			else
				return (-1);
		}
		/* 6.6- if format is not equal to %, prints what 
		  format brings in his index and plus byte in one */
		else
		{
			write(1, &format[i], 1);
			byte = byte + 1;
		}
		/* 7- plus i in one by each lap for our while stil 
		   format can be traverse */
		i++;
	}
	/* 8- ends or list and return or byte counter*/
	va_end(ap);
	return (byte);
}
