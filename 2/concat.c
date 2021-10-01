#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

const char AND[] = "&amp;";
const char LEFT_ANGLE_BRACKET[] = "&lt;";
const char RIGHT_ANGLE_BRACKET[] = "&gt;";

int append_encoding(char buffer[], const char *encoding, int index, int offset)
{
    for (int i = 0; i < strlen(encoding); i++)
    {
        buffer[index + offset] = encoding[i];
        offset++;
    }

    return --offset;
}

char *update_string(char input[])
{
    if (input == "")
        return "";

    char *buffer = malloc(4 * strlen(input) * sizeof(char) + 1);
    int offset = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
        case '&':
            offset = append_encoding(buffer, AND, i, offset);
            break;
        case '<':
            offset = append_encoding(buffer, LEFT_ANGLE_BRACKET, i, offset);
            break;
        case '>':
            offset = append_encoding(buffer, RIGHT_ANGLE_BRACKET, i, offset);
            break;
        default:
            buffer[i + offset] = input[i];
        }
    }

    return buffer;
}

int main(int argc, char const *argv[])
{
    char input[100];
    printf("Enter input:\n");
    scanf("%s", input);

    char *result = update_string(input);
    printf("\nResult:\n%s\n", result);
    free(result);

    return 0;
}
