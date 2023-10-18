#ifndef MAIN_H
#define MAIN_H

/*Include other header file*/
#include <unistd.h>
#include <stdarg.h>

/**
 * struct chaFun - associates a function to it format specifier
 * @spec: the format specifier in the printf format string
 * @fp: point to correlating function
 */
struct chaFun
{
	char spec;
	int (*fp)(va_list, char *);
};
#define BUFFSIZE 1024
int _printf(const char *, ...);

/* The function to for format specifications*/
int apchr(va_list, char *);
int apstr(va_list, char *);
#endif
