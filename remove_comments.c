#include <stdio.h>

int main()
{
    FILE *input, *output;

    input = fopen("input.c", "r");
    output = fopen("output.c", "w");

    if (input == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    if (output == NULL)
    {
        printf("Cannot create output file.\n");
        fclose(input);
        return 1;
    }

    int ch, next;
    int singleComment = 0;
    int multiComment = 0;
    int inString = 0;
    int inChar = 0;

    while ((ch = fgetc(input)) != EOF)
    {
        if (singleComment)
        {
            if (ch == '\n')
            {
                singleComment = 0;
                fputc(ch, output);
            }
        }
        else if (multiComment)
        {
            if (ch == '*')
            {
                next = fgetc(input);

                if (next == '/')
                    multiComment = 0;
                else if (next != EOF)
                    ungetc(next, input);
            }
        }
        else if (inString)
        {
            fputc(ch, output);

            if (ch == '\\')
            {
                ch = fgetc(input);
                if (ch != EOF)
                    fputc(ch, output);
            }
            else if (ch == '"')
            {
                inString = 0;
            }
        }
        else if (inChar)
        {
            fputc(ch, output);

            if (ch == '\\')
            {
                ch = fgetc(input);
                if (ch != EOF)
                    fputc(ch, output);
            }
            else if (ch == '\'')
            {
                inChar = 0;
            }
        }
        else
        {
            if (ch == '/')
            {
                next = fgetc(input);

                if (next == '/')
                {
                    singleComment = 1;
                }
                else if (next == '*')
                {
                    multiComment = 1;
                }
                else
                {
                    fputc(ch, output);

                    if (next != EOF)
                        ungetc(next, input);
                }
            }
            else
            {
                if (ch == '"')
                    inString = 1;
                else if (ch == '\'')
                    inChar = 1;

                fputc(ch, output);
            }
        }
    }

    fclose(input);
    fclose(output);

    printf("Comments removed successfully.\n");

    return 0;
}
