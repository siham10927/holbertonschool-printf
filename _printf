#include "main.h"

/**
 * _printf- acts a printf function
 * @format: string to be printed
 * Return: string length or -1 if failed
 **/
int _printf(const char *format, ...)
{
	va_list list;
	int len;
	char *output;
	str_list *h = NULL;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	len = build_str_list(&h, list, format);
	if (len == -1)
		return (-1);

	output = strncopy_list(h, len);
	len = write(1, output, len);

	va_end(list);
	free(output);
	free_strlist(h);

	add_times_user_tried_printing_a_null_byte(len);

	return (len);
}

/**
 * build_str_list - creates a str_list
 * @h: str_list head
 * @list: argument list
 * @str: string
 * Return: number of chars stored
 **/
int build_str_list(str_list **h, va_list list, const char *str)
{
	int len = 0, new_str_len;
	const char *tmp = str;

	if (str == NULL)
		return (-1);

	while (*str)
	{
		if (*str++ != '%')
			continue;
		if (*str == '\0')
			return (-1);
		new_str_len = add_str(h, &str, tmp, list);
		if (new_str_len == -1)
			return (-1);
		len += new_str_len;
		tmp = ++str;
	}
	new_str_len = add_str(h, &str, tmp, list);
	if (new_str_len == -1)
		return (-1);
	len += new_str_len;
	return (len);
}

/**
 * add_str - adds a string and its format specifications to a str list
 * @h: pointer to str list
 * @in: pointer to input string
 * @alt: alternate string to add to list if argument string unavailable
 * @list: argument list containing argument string
 * Return: a filled out config struct
 **/
int add_str(str_list **h, const char **in, const char *alt, va_list list)
{
	str_list *tmp = *h, *f = new_str_list_node();

	if (f == NULL)
		return (-1);
	if (*h)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = f;
	}
	else
		*h = f;

	for (; **in; (*in)++)
		if (**in == '-')
			f->minus = true;
		else if (**in == '+')
			f->plus = true;
		else if (**in == ' ')
			f->space = true;
		else if (**in == '0')
			f->zero = true;
		else if (**in == '#')
			f->hash = true;
		else
			break;

	if (is_digit(**in))
		for (f->has_min = true; is_digit(**in); (*in)++)
			f->width = (f->width * 10) + (**in - '0');
	if (**in == '.')
		for (f->has_max = true, (*in)++; is_digit(**in); (*in)++)
			f->precision = (f->precision * 10) + (**in - '0');
	if (**in == 'l' || **in == 'h')
		f->len = *(*in)++;
	f->type = **in;
	f->str = get_string(f, alt, list);
	if (f->str == NULL)
		return (-1);
	return (_strlen(f->str));
}

/**
 * get_string - gets string
 * @f: format config
 * @alt: alternate string (if format type is unknown)
 * @list: argument list
 * Return: string
 **/
char *get_string(str_list *f, const char *alt, va_list list)
{
	print_dict pd[] = {{"bdiopuxX", p_num}, {"csrRS", p_s}, {"%", p_mod}};
	int i, j, len, arg_len, total_len;
	char *arg = NULL, *tmp = NULL;

	for (i = 0; i < 3; i++)
		if (_strchr(pd[i].type, f->type))
		{
			tmp = pd[i].printer(list, f);
			if (tmp == NULL)
				return (NULL);
			break;
		}

	for (i = 0; alt[i] && alt[i] != '%'; i++)
		;
	arg_len = i;
	if (tmp == NULL && alt[i])
		for (arg_len++; alt[i] != f->type; i++)
			arg_len++;
	len = _strlen(tmp);
	total_len = len + arg_len;
	arg = malloc(total_len + 1);
	if (arg == NULL)
		return (NULL);
	for (i = 0; i < arg_len; i++)
		arg[i] = alt[i];
	for (j = 0; i < total_len; i++, j++)
		arg[i] = tmp[j];
	arg[i] = '\0';
	free(tmp);
	return (arg);
}

/**
 * strncopy_list - copies strings in a str list onto a buffer
 * @h: head of list
 * @n: number of bytes to allocate to string
 * Return: void
 **/
char *strncopy_list(str_list *h, int n)
{
	int len, width, print_spaces, i, j, k;
	char *buf = malloc(n + 1), space = ' ';

	if (buf == NULL)
		return (NULL);

	for (i = 0; h; h = h->next)
	{
		len = _strlen(h->str);
		print_spaces = ~(h->minus);

		if (h->has_max)
			len = min(h->precision, len);
		if (h->has_min)
			width = max(h->width, len);
		else
			width = len;

		if (h->zero && _strchr("bcdiopuxX", h->type))
			space = '0';

		for (k = i; i - k < width; print_spaces = true)
		{
			if (print_spaces == true)
				for (j = i + width - len; i < j; i++, j++)
					buf[i] = space;

			for (j = 0; i - k < len; i++, j++)
				buf[i] = h->str[j];
		}
	}
	buf[i] = '\0';
	return (buf);
}
