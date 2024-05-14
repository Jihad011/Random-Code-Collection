#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPerfectMatchString(char *str) {
    char *expected = "Hello,World!";
    if (strcmp(str, expected) == 0)
        return true;
    else
        return false;
}

int main() {
    char str[16];

    scanf("%s", str);

    if (isPerfectMatchString(str))
        printf("AC\n");
    else
        printf("WA\n");

    return 0;
}

