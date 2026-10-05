#include <stdio.h>
#include <conio.h>
#include <time.h>

int main()
{
    FILE *file;
    char ch;
    int total = 0;
    int backspace = 0;
    int letters = 0;
    int freq[26] = {0};

    time_t start, end;

    file = fopen("keystrokes.log", "w");

    if (file == NULL)
    {
        printf("File could not open");
        return 0;
    }

    printf("===== MY KEY LOGGER =====\n");
    printf("Type something...\n");
    printf("Press ESC to stop.\n\n");

    time(&start);

    while (1)
    {
        ch = _getch();
        if (ch == 27)
        {
            break;
        }
        total++;     
        if (ch == ' ')
        {
            printf("[SPACE] ");
            fprintf(file, "[SPACE]\n");
        }  
        else if (ch == 13)
        {
            printf("[ENTER] ");
            fprintf(file, "[ENTER]\n");
        }
       
        else if (ch == 8)
        {
            printf("[BACKSPACE] ");
            fprintf(file, "[BACKSPACE]\n");
            backspace++;
        }

        else if (ch == 9)
        {
            printf("[TAB] ");
            fprintf(file, "[TAB]\n");
        }

        else
        {
            printf("%c ", ch);
            fprintf(file, "%c\n", ch);

            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z'))
            {
                letters++;

                if (ch >= 'A' && ch <= 'Z')
                {
                    ch = ch + 32;
                }

                freq[ch - 'a']++;
            }
        }
    }

    time(&end);

    fclose(file);

    printf("\n\n______ RESULT yo_____\n");

    printf("Total keys: %d\n", total);
    printf("Letters: %d\n", letters);
    printf("Backspaces: %d\n", backspace);

    printf("Time: %.0f seconds\n",
           difftime(end, start));

  
    if (difftime(end, start) > 0)
    {
        float minutes;
        float wpm;

        minutes = difftime(end, start) / 60;
        wpm = (letters / 5.0) / minutes;

        printf("WPM: %.2f\n", wpm);
    }

    if (total > 0)
    {
        printf("Backspace rate: %.2f%%\n",
               backspace * 100.0 / total);
    }

    printf("\n______KEY FREQUENCY______\n");

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c = %d  ", 'a' + i, freq[i]);

    
            for (int j = 0; j < freq[i]; j++)
            {
                printf("#");
            }

            printf("\n");
        }
    }

    printf("\nLog saved as keystrokes.log\n");

    file = fopen("keystrokes.log", "r+");

    if (file != NULL)
    {
        int x;

        while ((x = fgetc(file)) != EOF)
        {
            fseek(file, -1, SEEK_CUR);
            fputc(x ^ 5, file);
        }

        fclose(file);
    }

    printf("Log file scrambled.\n");
    printf("Program finished!\n");

    return 0;
}