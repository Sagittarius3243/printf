#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);

            if (format[i] == 'c')
                printed_chars += _print_char(args);
            else if (format[i] == 's')
                printed_chars += _print_string(args);
            else
            {
                _putchar('%');
                _putchar(format[i]);
                printed_chars += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            printed_chars++;
        }
        i++;
    }

    va_end(args);
    return printed_chars;
}
