#include <stdio.h>
#include <string.h>
int main() {
    char str[200];
    int i, words = 0;
    fgets(str, sizeof(str), stdin);
    for(i = 0; str[i] != '\0'; i++) {
        if((i == 0 && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') || (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && (str[i-1] == ' ' || str[i-1] == '\n' || str[i-1] == '\t'))) {
            words++;
        }
    }
    printf("%d", words);
    return 0;
}