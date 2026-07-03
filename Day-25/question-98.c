#include <stdio.h>
#include <string.h>
void findCommonChars(char* strs[], int strsSize) {
    int minFreq[26];
    for (int i = 0; i < 26; i++) {
        minFreq[i] = 10000;
    }
    for (int i = 0; i < strsSize; i++) {
        int count[26] = {0};
        for (int j = 0; strs[i][j] != '\0'; j++) {
            count[strs[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (count[j] < minFreq[j]) {
                minFreq[j] = count[j];
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        while (minFreq[i] > 0) {
            printf("%c ", i + 'a');
            minFreq[i]--;
        }
    }
    printf("\n");
}
int main() {
    char* strs[] = {"bella", "label", "roller"};
    int size = sizeof(strs) / sizeof(strs[0]);
    findCommonChars(strs, size);
    return 0;
}