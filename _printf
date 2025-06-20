#include "main.h"
/**
 * _printf - Entry point
 * @format: char
 * Return:size
 */
int _printf(const char *format, ...)
{
	int i = 0, size = 0;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			size += get_fun(format[i + 1], args);
			i += 1;
		}
		else
		{
			_putchar(format[i]);
			size += 1;
		}
	}
	va_end(args);
	return (size);
}
