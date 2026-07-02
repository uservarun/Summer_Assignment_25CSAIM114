#include <stdio.h>
#include <string.h>
#include <ctype.h>
void findLongestWord(char *str, char *longest) {
    int maxLen = 0;
    int curLen = 0;
    int startIdx = 0;
    int maxStartIdx = 0;
    int i = 0;
    int len = strlen(str);
    while (i <= len) {
        if (i < len && !isspace(str[i]) && !ispunct(str[i])) {
            if (curLen == 0) {
                startIdx = i;
            }
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStartIdx = startIdx;
            }
            curLen = 0;
        }
        i++;
    }
    strncpy(longest, &str[maxStartIdx], maxLen);
    longest[maxLen] = '\0';
}
int main() {
    char str[] = "Find the longest word in this sentence.";
    char longest[100];
    findLongestWord(str, longest);
    printf("Longest word: %s\n", longest);
    return 0;
}