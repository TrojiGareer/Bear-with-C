#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int puts(char *str) {
    int len = strlen(str);
    if (write(1, str, len) < 0) {
        return -1;
    }
    if (write(1, "\n", 1) < 0) {
        return -1;
    }
    return 1;
}
