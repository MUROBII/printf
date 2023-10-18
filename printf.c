#include "main.h"
/**
 * _printf - format and prints a string stdout (screen)
 * @format: The string specify chars and formats
 *
 * Return: The number of chars printed to stdout
 */
int _printf(const char *format, ...)
{
	short index, count, idx;
	va_list v;/*point to stack*/
	char buff[BUFFSIZE];/*Buffer to store the resulting string*/
	/* array of structures that assocites, func to format specifier*/
	struct chaFun arr_spec[] = {{'c', apchr}, {'s', apstr}, {'\0', NULL}};

	va_start(v, format);/*Initializing pointer to stack*/
	index  = count = idx = 0;
	for (; format[index] != '\0'; index++)
	{/*going through the Array*/
		if (format[index] == '%')
		{/*Scanning for format specifier*/
			index++;
			if (format[index] == '%')
			{/*for % as a format specifier*/
				buff[count] = format[index];
				count++;
				continue;
			}

			for (idx = 0; arr_spec[idx].spec; idx++)
			{/*Scanning for correlating function*/
				if (arr_spec[idx].spec == format[index])
					count += arr_spec[idx].fp(v, buff + count);
			}
		}
		else
		{/*never met format specifier, writing to buffer*/
			buff[count] = format[index];
			count++;
		}
	}
	write(STDOUT_FILENO, buff, count);

	return (count);
}
