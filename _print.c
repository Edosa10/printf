#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void);

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            if (*format == '\0') {
                // If '%' is the last character in the format, break the loop
                break;
            } else if (*format == 'c') {
                // Handle %c conversion specifier
                char c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Handle %s conversion specifier
                char *str = va_arg(args, char*);
                while (*str) {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                // Handle %% conversion specifier (print a single '%')
                putchar('%');
                count++;
            }
        } else {
            // Regular character, just print it
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! The answer is %d%%. A char: %c\n", "world", 42, 'A');
    return 0;
}
