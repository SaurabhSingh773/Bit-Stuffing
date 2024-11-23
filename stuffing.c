#include <stdio.h>
#include <string.h>

#define FLAG "111111"

void bitStuffing(char *input, char *stuffed) {
    int count = 0, j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        stuffed[j++] = input[i];

        if (count == 5) {
            stuffed[j++] = '0';
            count = 0;
        }
    }

    stuffed[j] = '\0';
}

void bitDestuffing(char *stuffed, char *destuffed) {
    int count = 0, j = 0;

    for (int i = 0; stuffed[i] != '\0'; i++) {
        if (stuffed[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        destuffed[j++] = stuffed[i];

        if (count == 5 && stuffed[i + 1] == '0') {
            i++;
            count = 0;
        }
    }

    destuffed[j] = '\0';
}

int main() {
    char input[100], stuffed[200], destuffed[100];

    printf("Enter the binary data (without spaces): ");
    scanf("%s", input);

    bitStuffing(input, stuffed);
    printf("After bit stuffing: %s\n", stuffed);

    bitDestuffing(stuffed, destuffed);
    printf("After bit destuffing: %s\n", destuffed);

    if (strcmp(input, destuffed) == 0) {
        printf("Destuffing successful, original data matches!\n");
    } else {
        printf("Destuffing failed, original data does not match.\n");
    }

    return 0;
}
