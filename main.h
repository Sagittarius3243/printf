#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _print_char(va_list args);
int _print_string(va_list args);
int _printf(const char *format, ...);
int process_format(const char *format, va_list args);
int process_specifier(char spec, va_list args);

/**
 * struct print_fn - Function pointer to print functions
 * @fn: The print function
 * @specifier: The format specifier associated with the function
 */
typedef struct print_fn
{
    int (*fn)(va_list);
    char specifier;
} print_fn_t;

#endif /* MAIN_H */
