#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256
int main() {
    char str[] = "sample string";
    int count[NO_OF_CHARS] = {0};
    int i;
    int max = -1;
    char result;
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }
    printf("Maximum occurring character is %c", result);
    return 0;
}