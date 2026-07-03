#include <stdio.h>
#include <string.h>
void sortWordsByLength(char words[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}
int main() {
    char words[][50] = {"elephant", "cat", "banana", "dog", "at"};
    int n = sizeof(words) / sizeof(words[0]);
    sortWordsByLength(words, n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}