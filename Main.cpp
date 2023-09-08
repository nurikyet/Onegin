#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <assert.h>

const int NumberOfRows = 100;

int GetSizeFromFile();
int main()
    {
    int sizef = 0;
    FILE *textfile;
    if((textfile=fopen("textfile.txt", "rb"))==NULL)
        {
        printf("Cannot open file.\n");
        assert(false);
        }
    sizef = GetSizeFromFile();
    char *text[NumberOfRows] = {};
    char *buffer = (char*) calloc(sizef, sizeof(char));
    fread(buffer, sizef, sizeof(char), textfile);
    text[0] = buffer;
    int nline = 1;
    for (int i = 0; i < sizef; i++)
        {

        if (buffer[i] == '\n')
            {
            text[nline] = buffer + i + 1;
            //printf("%p\n", text[nline]);  //"������� ����� �� ������� ����������"
            //printf("%p\n", &buffer[i+1]); //"������� ����� �� char-�������"
            //printf("%c\n", buffer[i+1]);
            buffer[i] = '\0';
            nline++;
            }
        }
    //printf("abcd\n");
    //printf("%p\n", text);
    //for (int i = 0; i < NumberOfRows; i++)
    //    {
    //    printf("%p\n", text[i]);
    //    printf("%s\n", text[i]);
        }
    fclose(textfile);
    }
int GetSizeFromFile()
    {
    int sizef = 0;
    struct stat buff;
    stat("textfile.txt", &buff);
    sizef = buff.st_size;
    return sizef;
    }
