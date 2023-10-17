#include "printf.h"
#include <stdio.h>
/**
 * _printf - format and prints a string stdout (screen)
 * @format: The string specify chars and formats
 *
 * Return: The number of chars printed to stdout
 */
int _printf(const char *format, ...)
{	
	short index, count;
	char buff[BUFFSIZE];/*Buffer to store the resulting string*/

	index  = count = 0;
	for (;format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			index++;
			continue;
		}
		else
		{
			buff[count] = format[index];
			count++;
		}
	}
	write(STDOUT_FILENO, buff, count);

	return (count);
}
