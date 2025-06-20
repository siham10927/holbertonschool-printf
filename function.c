#include "main.h"

/**
 * write_char - Writes the given char.
 * @len: Length of the char in _printf func.
 * @c: Char to be printed.
 *
 * Return: void.
*/
void write_char(int *len, char c)
{
	write(1, &c, 1);
	(*len)++;
}

/**
 * write_str - Writes the given string.
 * @len: Length of the chars in _printf func.
 * @str: String to be printed
 *
 * Return: void.
 */
void write_str(int *len, char *str)
{
	int lenstr;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		for (lenstr = 0; str[lenstr]; lenstr++)
			;
		write(1, str, lenstr);
		*len += lenstr;
	}
}

/**
 * write_int - Writes the given integer.
 * @len: Length of the chars in _printf func.
 * @num: Integer to be printed
 *
 * Return: void.
 */
void write_int(int *len, int num)
{
	int divisor = 1, temp = num;
	char digit;

	if (num == INT_MIN)
	{
		write_str(len, "-2147483648");
		return;
	}
	if (num < 0)
	{
		write_char(len, '-');
		temp = -num;
	}

	while (temp / divisor >= 10)
		divisor *= 10;

	while (divisor != 0)
	{
		digit = '0' + temp / divisor;
		write_char(len, digit);
		temp %= divisor;
		divisor /= 10;
	}
}
