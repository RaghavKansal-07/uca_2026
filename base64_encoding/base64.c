#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *base64Encode(const char *input) {
    const char table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int length = strlen(input);
    int outputLength = 4 * ((length + 2) / 3);

    char *output = malloc(outputLength + 1);

    if (output == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;

    while (i < length) {
        unsigned char a = input[i++];
        unsigned char b = i < length ? input[i++] : 0;
        unsigned char c = i < length ? input[i++] : 0;

        output[j++] = table[a >> 2];
        output[j++] = table[((a & 0x03) << 4) | (b >> 4)];

        if (i - 1 < length) {
            output[j++] = table[((b & 0x0F) << 2) | (c >> 6)];
        } else {
            output[j++] = '=';
        }

        if (i < length + 1) {
            output[j++] = table[c & 0x3F];
        } else {
            output[j++] = '=';
        }
    }

    output[j] = '\0';

    return output;
}

int main() {
    char input[1000];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *result = base64Encode(input);

    if (result == NULL) {
        return 1;
    }

    printf("Base64: %s\n", result);

    free(result);

    return 0;
}
