#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256
int main() {
    char str[] = "geeksforgeeks";
    int count[NO_OF_CHARS] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    int index = -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("All characters are repeating or string is empty");
    } else {
        printf("First non-repeating character is %c", str[index]);
    }
    return 0;
}