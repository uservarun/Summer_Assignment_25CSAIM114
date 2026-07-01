#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256
int main() {
    char str1[] = "listen";
    char str2[] = "silent";
    int count[NO_OF_CHARS] = {0};
    int i;
    if (strlen(str1) != strlen(str2)) {
        printf("Strings are not anagrams");
        return 0;
    }
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }
    int isAnagram = 1;
    for (i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }
    if (isAnagram) {
        printf("Strings are anagrams");
    } else {
        printf("Strings are not anagrams");
    }
    return 0;
}