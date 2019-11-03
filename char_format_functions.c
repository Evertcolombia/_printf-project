/* Functions to char format as 'c, s, %, unk, nil', char, string, % percent, unknowned type, and nil of error */

#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * prt_chr - print  character
 * @ap: list of characts
 *
 * Return: nmber of bytes
 */

/* 1- This function recived a list of arguments as arguments in this
     case there are char */
int format_char(va_list ap)
{
	/* 2- Init variables to treat each character and the bytes
	  number to return*/
	char p;
	int byte = 0;

	/* 3- We have to traverse our list and store it in our 
	   p char using va_arg. The castin is to pass  a int that
	    is the number of the argument to char  */
	p = (char) va_arg(ap, int);

	/* 4- prints what contains p in his address */
	write (1, &p, 1);
	byte++;
	/*Return the bytes number*/
	return(byte);
}  
