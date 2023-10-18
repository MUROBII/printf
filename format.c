#include "main.h"

/**
 * apchr - appends char to the main buffer
 * @v: pointer to the arguement on stack
 * @buffplus: the address on the main buffer, where is to appended
 *
 * Return: the number of chars appended
 */
int apchr(va_list v, char *buffplus)
{
	buffplus[0] = va_arg(v, int);

	return (1);
}

/**
 * apstr - appends bunch of chars to the main buffer
 * @v: pointer to the arguement on stack
 * @buffplus: the address on the main buffer, where appending is to start
 *
 * Return: the number chars appended
 */
int apstr(va_list v, char *buffplus)
{
	int index;
	char *s = va_arg(v, char *);

	if (s == NULL)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		buffplus[index] = s[index];
		index++;
	}
	return (index);
}


