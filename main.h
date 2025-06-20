#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
void write_char(int *len, char c);
void write_str(int *len, char *str);
void write_int(int *len, int num);

#endif
