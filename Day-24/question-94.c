#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void compressString(char *str) {
    int len = strlen(str);
    if (len == 0) return;
    char *compressed = (char *)malloc(sizeof(char) * (len * 2 + 1));
    int i, j = 0;
    for (i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        compressed[j++] = str[i];
        int numChars = sprintf(&compressed[j], "%d", count);
        j += numChars;
    }
    compressed[j] = '\0';
    if (strlen(compressed) < len) {
        printf("Compressed string: %s\n", compressed);
    } else {
        printf("Original string: %s\n", str);
    }
    free(compressed);
}
int main() {
    char str[] = "aabcccccaaa";
    compressString(str);
    return 0;
}