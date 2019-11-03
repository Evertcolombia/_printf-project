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

/* This function recived a list of arguments as arguments in this
     case there are char */
int format_char(va_list ap)
{
	/* 1- Init variables to treat each character and the bytes
	  number to return*/
	char p;
	int byte = 0;

	/* 2- We have to traverse our list and store it in our 
	   p char using va_arg. The castin is to pass  a int that
	    is the number of the argument to char  */
	p = (char) va_arg(ap, int);

	/* 3- prints what contains p in his address */
	write (1, &p, 1);
	byte++;
	/*Return the bytes number*/
	return(byte);
}

/**
 * prt_str - prints a string 
 * @ap: string char by char
 *
 * Return: bytes total
 */

/* This function recived a list of argument in this case is a 
string */
int format_str(va_list ap)
{
	/* 1- Init vairables, use a pointer by each char, and a byte
	   for the byte counter, and e that is for the prints */
	char *p;
	int byte = 0, e = 0;

	/* 2- traverse the list usen var_arg,and the poinet for each 
	   char tha will recieved*/
	p = va_arg(ap, char *);

	/* 3- If  p is true we want to use this to print our string */
	if (p)
	{
		/* 3.1- While p can be recorred as a array using a
		   counter and pus it with the value o p, init this
		   variable as e */
		while (*(p + e))
		{
			/* 3.2- Print each character of the string
			   using p + e, after e is aumented in 1. so
			   always p will be printed in a new
			   position */
			write(1, p + e, 1);
			e++;
			byte++;
		}
	}
	/* 4- Else, if p is empty print (null), and byte will
	   the same number of bytes that this string */
	else
	{
		write(1, "(null)", 6);
		byte = 6;
	}
	/* 5- Return bytes numbers*/
	return (byte);
}

/**
 * prt_pct - prints a % sign
 * @ap: string char by char
 *
 * Return: bytes total
 */

/* This function will print a % if recives as argument another % */
int format_percent(va_list ap)
{
	/* 1- init variable yte for the count of bytes */
	int byte = 0;

	/* 2- print a % sing, after  byte plus one and*/
	write(1, "%", 1);
	byte++;

	/* 3- cast ap to get no return value */
	(void) ap;

	/* 4 - Return the number of bytes*/
	return (byte);
}
