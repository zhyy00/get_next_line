//TODO: make header

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd)
{
    char    *readbuf;
    size_t  bufsize = BUFFER_SIZE;
    char    *nextline;
    size_t  i;

    readbuf = malloc(bufsize * sizeof(char));
    if (readbuf == NULL)
        return (NULL);
    // loop continuously over reading of the file
    // until a EOF is detected
    //      in every loop, read from file with bufsize
    //      check if there is '\n' present of '\EOF'
    //      return all until including first occurence of '\n'
    if (!read(fd, readbuf, bufsize))
        return (NULL);
    i = 0;
    nextline = malloc(bufsize * sizeof(char));
    while (i < bufsize && readbuf[i] != 4)
    {
        nextline[i] = readbuf[i];
        if (readbuf[i] == '\n')
            break ;
        i++;
    }
    free(readbuf);
    return ((char *)nextline);
}

#endif
