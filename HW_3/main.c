#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    char *pattern = argv[1];
    char *text = argv[2];
    char *replacement = argv[3];

    regex_t regex;
    regmatch_t match;

    regcomp(&regex, pattern, REG_EXTENDED);

    size_t bufsize = 1024;
    char *result = malloc(bufsize);
    result[0] = '\0';

    char *cursor = text;

    while (regexec(&regex, cursor, 1, &match, 0) == 0) {
        strncat(result, cursor, match.rm_so);
        strcat(result, replacement);

        cursor += match.rm_eo;

        if (strlen(result) + strlen(cursor) + 100 > bufsize) {
            bufsize *= 2;
            result = realloc(result, bufsize);
        }
    }

    strcat(result, cursor);

    printf("%s\n", result);

    regfree(&regex);
    free(result);
    return 0;
}
