#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;  // To keep track of the number of characters printed
    
    while (*format) {
        if (*format != '%') {
            // Ordinary character, just write it
            write(1, format, 1);
            count++;
        } else {
            format++;  // Move past the '%'
            
            // Check the conversion specifier
            switch (*format) {
                case 'c':
                    // Print a character
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    // Print a string
                    char *str = va_arg(args, char *);
                    for (int i = 0; str[i]; i++) {
                        write(1, &str[i], 1);
                        count++;
                    }
                    break;
                case '%':
                    // Print a literal '%'
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    // Unknown conversion specifier, just print the '%'
                    write(1, "%", 1);
                    count++;
                    break;
            }
        }
        
        format++;  // Move to the next character in the format string
    }
    
    va_end(args);
    return count;
}
