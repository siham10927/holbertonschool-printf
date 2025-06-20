#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int get_fun(char format, va_list args);
typedef struct form
{
	char str;

	int (*print)(va_list args);
} fmt;
int char_print(va_list args);
int pert_print(__attribute__((unused)) va_list args);
int string_print(va_list args);
int num_print(va_list args);
int unsigned_num(va_list args);
int binary(va_list args);
#endif
