#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _strlen(char *s);
int print_number(int num);
void _itoa(int num, char *str);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
#endif /* MAIN_H */
