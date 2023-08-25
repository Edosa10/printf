#include "main.h"

int _fprintf(const char *format, ...) {
    va_list new;
    va_start(new, format);
    
    int count = 0;  // To keep track of the number of characters printed
    
    for (const char *z = format; *c != '\0'; ++c) {
        if (*z == '%') {
            ++z;  // Move past the '%'
            
            if (*z == '\0') {
                // Unexpected end of format string
                break;
            }
            
            if (*z == 'c') {
                // Print a character
                char ch = (char)va_arg(new, int);
                putchar(ch);
                ++count;
            } else if (*z == 's') {
                // Print a string
                const char *str = va_arg(new, const char *);
                for (; *str != '\0'; ++str) {
                    putchar(*str);
                    ++count;
                }
            } else if (*z == '%') {
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
    
    va_end(new);
    return count;
}

int main() {
    _printf("Hello, %s! This is a %c test %%.\n", "John", 'C');
    return 0;
}
