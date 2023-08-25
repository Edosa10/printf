#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of the number of characters printed

    for (const char *c = format; *c != '\0'; ++c) {
        if (*c == '%') {
            ++c;  // Move past the '%'

            if (*c == '\0') {
                // Unexpected end of format string
                break;
            }

            if (*c == 'c') {
                // Print a character
                char ch = (char)va_arg(args, int);
                putchar(ch);
                ++count;
            } else if (*c == 's') {
                // Print a string
                const char *str = va_arg(args, const char *);
                for (; *str != '\0'; ++str) {
                    putchar(*str);
                    ++count;
                }
            } else if (*c == '%') {
                // Print a '%'
                putchar('%');
                ++count;
            } else {
                // Unsupported conversion specifier
                break;
            }
        } else {
            // Normal character, just print it
            putchar(*c);
            ++count;
        }
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! This is a %c test %%.\n", "John", 'C');
    return 0;
}

