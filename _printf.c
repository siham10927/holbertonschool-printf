#include "main.h"

/**
 * _printf - Prints the given format with variables.
 * @format: Main format
 *
 * Return: Number of the chars printed.
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int len = 0, i = 0;
	char crntchar, *crntstring;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			switch (format[i + 1])
			{
				case 'c':
					crntchar = (char)va_arg(arg, int);
					write_char(&len, crntchar), i += 2;
					break;
				case 's':
					crntstring = va_arg(arg, char*);
					write_str(&len, crntstring), i += 2;
					break;
				case 'd':
				case 'i':
					write_int(&len, va_arg(arg, int)), i += 2;
					break;
				case '%':
					write_char(&len, '%'), i += 2;
					break;
				case '\0':
					continue;
				default:
					write_char(&len, format[i]), i++;
					break;
			}
		else
			write_char(&len, format[i]), i++;
	}
	va_end(arg);
	return (len);
}
