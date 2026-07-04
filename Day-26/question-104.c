#include <stdio.h>
int main() {
    int score = 0, answer;
    printf("--- Welcome to the Quiz Application ---\n");
    printf("\nQ1. What is the size of an int data type in C (usually)?\n");
    printf("1. 1 Byte\n2. 2 Bytes\n3. 4 Bytes\n4. 8 Bytes\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 3. 4 Bytes\n");
    }
    printf("\nQ2. Which keyword is used to prevent any changes to a variable?\n");
    printf("1. static\n2. const\n3. volatile\n4. immutable\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 2. const\n");
    }
    printf("\nQ3. Which of the following is the correct file extension for a C source file?\n");
    printf("1. .cpp\n2. .c\n3. .obj\n4. .exe\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 2. .c\n");
    }
    printf("\n--- Quiz Finished ---\n");
    printf("Your final score is: %d out of 3\n", score);
    return 0;
}