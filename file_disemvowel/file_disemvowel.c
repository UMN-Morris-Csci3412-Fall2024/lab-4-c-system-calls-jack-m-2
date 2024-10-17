#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// Function to check if a character is a vowel
int vowel(char c) {
    int lowercase, uppercase;

    // Check if the character is a lowercase vowel
    lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // Check if the character is an uppercase vowel
    uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // Return true if the character is either a lowercase or uppercase vowel
    return lowercase || uppercase;
}

// Function to read the content of a file into a string
char *read_file(FILE *file) {
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length + 1);
    if (!content) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(content, 1, length, file);
    content[length] = '\0';

    return content;
}

// Function to remove vowels from a string
char *disemvowel(char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!vowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    return result;
}

int main(int argc, char *argv[]) {
    FILE *input_file = stdin;

    if (argc == 2) {
        input_file = fopen(argv[1], "r");
        if (!input_file) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
    } else if (argc > 2) {
        fprintf(stderr, "Usage: %s [input file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_content = read_file(input_file);
    char *output_content = disemvowel(input_content);

    printf("%s", output_content);

    free(input_content);
    free(output_content);

    if (input_file != stdin) {
        fclose(input_file);
    }

    return EXIT_SUCCESS;
}