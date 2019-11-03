/* This function will be called when _printf function is called and 
   send to here an argument char that contains a format to print a 
   content ina correct format, will return a function that treated
   this format correctly */
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

/* 1- This function will recieved a char as format, and will return 
   the correct format function to print the user request */
int (*get_ops_function(char s))(va_list ap)
{
	/* 2- Init conter variable*/
	int i = 0;

	/* 3- Create an instance of ous structure. this contains a 
	   char (format, type) and a function pointer for each property */
	d_dt data_types[] = {
		{"c", format_char},/*3.1-'c' format as type and func*/
		{"s", format_str}/*3.2 -'s' format as type and func*/
	};

	/* 4- while our counter  i  be less than the length of the
	   data_type intance, we want to look if the char format that
	   user passed is in our structure to return the correct
	   function */
	while (i < 2)
	{
		/* 4.1- If the char format is equal to the type in 
		   the property in the data_type index, return the
		   function in this property */
		if (s == *data_types[i].type)
			return (data_types[i].f);


		/* 4.2- i + 1 to continue the loop */
		i++;
	}

	/* 5- if the loops end and no one format is the same that 
	   the argument  print the % that correspond and after print
	   what contais our argument in his address */
	write(1, "%", 1);
	write(1, &s, 1);
	
	/* 6-we have to return now a error message because the 
	   argument is not equal to no one format, so return an
	   instance for the unknowned format function */
	/*return (format_ukn);*/
	return (0);
}
