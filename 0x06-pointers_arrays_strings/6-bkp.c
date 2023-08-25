#include "main.h"
/**
 * is_separator - checks for sperator.
 * @c: element to check
 * Return: true or false
 */
bool is_separator(char c) {
	int i;
    char separators[] = " \t\n,;.!?\"(){}";
    for (i = 0; separators[i] != '\0'; ++i) {
        if (c == separators[i]) {
            return true;
        }
    }
    return false;
}
/**
 * *cap_string - changes words to uppercase.
 * @str: string to convert.
 * Return: uppercase string
 */
char *cap_string(char *s) {
	int i;
    bool new_word = true;

    for (i = 0; s[i] != '\0'; ++i) {
        if (is_separator(s[i])) {
            new_word = true;
        } else if (new_word && isalpha(s[i])) {
            s[i] = toupper(s[i]);
            new_word = false;
        } else {
            s[i] = tolower(s[i]);
            new_word = false;
        }
    }

    return s;
}
