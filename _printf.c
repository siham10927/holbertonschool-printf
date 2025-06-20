#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += print_string(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                case 'X':
                    count += print_hex(va_arg(args, unsigned int), *format == 'X');
                    break;
                case 'p':
                    count += print_pointer(va_arg(args, void *));
                    break;
                default:
                    count += _putchar('%') + _putchar(*format);
                    break;
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);
    return (count);
}
