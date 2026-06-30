#include <stdio.h>
#include <string.h>
int main() {
    char str[200];
    int i, count[256] = {0};
    fgets(str, sizeof(str), stdin);
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != '\n') {
            count[(unsigned char)str[i]]++;
        }
    }
    for(i = 0; i < 256; i++) {
        if(count[i] > 0) {
            printf("%c: %d\n", i, count[i]);
        }
    }
    return 0;
}