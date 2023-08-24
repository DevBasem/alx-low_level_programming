#include "main.h"
/**
 * *rot13 - encodes a string using rot13.
 * @input: string to encode.
 * Return: encoded string.
 */
char *rot13(char *input) {
    if (input == NULL) {
        return NULL;
    }

    char *result = (char *)malloc(strlen(input) + 1);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        int diff = 0;

        if ('a' <= input[i] && input[i] <= 'z') {
            diff = 'a';
        } else if ('A' <= input[i] && input[i] <= 'Z') {
            diff = 'A';
        }

        if (diff != 0) {
            result[i] = (input[i] - diff + 13) % 26 + diff;
        } else {
            result[i] = input[i];
        }
    }

    result[strlen(input)] = '\0';
    return result;
}
