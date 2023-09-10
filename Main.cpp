#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <assert.h>

const int NumberOfRows = 100; // TODO: use a consistent naming style!
//        ^~~~~~~~~~~~ TODO: Is there a way to have variable number of line?

int GetSizeFromFile(); // TODO: add a newline!
int main()
    {
    int sizef = 0; // TODO: what is size_f_? Rename!
    FILE *textfile; // TODO: initialize your variables! Also, what is this naming style?
    if((textfile=fopen("textfile.txt", "rb"))==NULL)
        {
        printf("Cannot open file.\n");

	// TODO: I don't think this is a place for assert. What do you think? Let's discuss :)
        assert(false);
        }
    sizef = GetSizeFromFile(); // TODO: why split initialization?
    char *text[NumberOfRows] = {}; // TODO: abstract this
    char *buffer = (char*) calloc(sizef, sizeof(char));
    fread(buffer, sizef, sizeof(char), textfile); // TODO: you should check fread's return value :) 
    text[0] = buffer;
    int nline = 1; // TODO: this should be extracted, obviously
    for (int i = 0; i < sizef; i++)
        {

        if (buffer[i] == '\n')
            {
            text[nline] = buffer + i + 1;
	    // TODO: do not commit commented code! You have git, learn
	    //       to use it properly (read git-scm, for example)
            //printf("%p\n", text[nline]);  //"Выводит адрес из массива указателей"
            //printf("%p\n", &buffer[i+1]); //"Выводит адрес из char-массива"
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
    sizef = buff.st_size; // TODO: why use intermediate variable?
    return sizef;
    }


// TODO: You shouldn't commit binary files (.exe), save files (.save)
//       and anything that is not the project itself.
