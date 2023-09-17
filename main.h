#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_UNSIGNED (1 << 0)  
#define CONVERT_LOWERCASE (1 << 1) 



/**
 * struct parameters - structure for parameters
 * @unsign: unsigned flag
 * @plus_flag: + flag
 * @space_flag: space flag
 * @hashtag_flag: # flag
 * @zero_flag: 0 flag
 * @minus_flag: - flag
 * @width: width of print
 * @percision: precision of print
 * @h_modifier: h modifier
 * @l_modifier: l modifier
 */
typedef struct parameters
{
    unsigned int unsign : 1;
    unsigned int plus_flag : 1;
    unsigned int space_flag : 1;
    unsigned int hashtag_flag : 1;
    unsigned int zero_flag : 1;
    unsigned int minus_flag : 1;
    unsigned int width;
    unsigned int percision;
    unsigned int h_modifier : 1;
    unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - structure for specifier
 * @specifier: specifier string
 * @f: function to handle specifier
 */
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, params_t *params);
} specifier_t;

/* Prints a string to the standard output */
int _puts(char *str);

/* Prints a character to the standard output */
int _putchar(int c);

/* Prints a character argument */
int print_char(va_list ap, params_t *params);

/* Prints an integer argument */
int print_int(va_list ap, params_t *params);

/* Prints a string argument */
int print_string(va_list ap, params_t *params);

/* Prints a percentage symbol */
int print_percent(va_list ap, params_t *params);

/* Prints non-printable characters in a string */
int print_S(va_list ap, params_t *params);

/* Converts and prints an integer in binary */
int print_binary(va_list ap, params_t *params);

/* Converts and prints an integer in hexadecimal (lowercase) */
int print_hex(va_list ap, params_t *params);

/* Converts and prints an integer in hexadecimal (uppercase) */
int print_HEX(va_list ap, params_t *params);

/* Converts and prints an integer in octal */
int print_octal(va_list ap, params_t *params);

/* Prints an unsigned integer argument */
int print_unsigned(va_list ap, params_t *params);

/* Prints the address of a variable */
int print_address(va_list ap, params_t *params);

/* Prints a range of characters from start to stop, excluding except */
int print_from_to(char *start, char *stop, char *except);

/* Prints a string in reverse */
int print_rev(va_list ap, params_t *params);

/* Retrieves flag specification for formatting */
int get_flag(char *s, params_t *params);

/* Prints a string encoded in rot13 */
int print_rot13(va_list ap, params_t *params);

/* Converts a number into a specified base string */
char *convert(long int num, int base, int flags, params_t *params);

/* Retrieves the appropriate specifier function for a format */
int (*get_specifier(char *s))(va_list ap, params_t *params);

/* Retrieves the appropriate print function for a format */
int get_print_func(char *s, va_list ap, params_t *params);

/* Retrieves the modifier for a format */
int get_modifier(char *s, params_t *params);

/* Retrieves the width specification for formatting */
char *get_width(char *s, params_t *params, va_list ap);

/* Checks if a character is a digit */
int _isdigit(int c);

/* Computes the length of a string */
int _strlen(char *s);

/* Prints a number with formatting */
int print_number(char *str, params_t *params);

/* Adjusts the printed number to the right */
int print_number_right_shift(char *str, params_t *params);

/* Adjusts the printed number to the left */
int print_number_left_shift(char *str, params_t *params);

/* Initializes the parameters for formatting */
void init_params(params_t *params, va_list ap);

/* Retrieves the precision specification for formatting */
char *get_percision(char *p, params_t *params, va_list ap);

/* Custom printf implementation */
int _printf(const char *format, ...);

#endif /* MAIN_H_ */
