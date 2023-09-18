#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    count += process_format(format, args);
    va_end(args);
    return (count);
}

/**
 * process_format - Processes the format string.
 * @format: The format string.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters processed.
 */
int process_format(const char *format, va_list args)
{
    int count = 0;

    while (*format)
    {
        if (*format != '%')
        {
            count += write(1, format, 1);
            format++;
        }
        else
        {
            format++;
            if (*format == '\0')
                return (-1);
            if (*format == '%')
            {
                count += write(1, "%", 1);
                format++;
            }
            else
            {
                count += print_arg(*format, args);
                format++;
            }
        }
    }
    return (count);
}

/**
 * print_arg - Prints an argument based on the format specifier.
 * @specifier: The format specifier.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_arg(char specifier, va_list args)
{
    switch (specifier)
    {
        case 'c':
            return (print_char(va_arg(args, int)));
        case 's':
            return (print_string(va_arg(args, char *)));
        default:
            return (-1);
    }
}

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: 1.
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *s)
{
    if (s == NULL)
        s = "(null)";
    return (write(1, s, _strlen(s)));
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}
