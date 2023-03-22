// redirects are handled in reverse order: i) 2> ii) > OU >> iii)<
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define FILE_MODE (S_IRUSR | S_IWUSR)
int redirects(int numargs, char *args[])
{
    if (numargs < 3)
        return numargs; // Guard the following section
    if (strcmp(args[numargs - 2], "2>") == 0)
    {
        int fd = creat(args[numargs - 1], FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1; /*indicar um erro*/
        }
    dup2(fd, STDERR_FILENO);
    close(fd);
    args[numargs - 2] = NULL;
    numargs = numargs - 2;
    }
    else if (strcmp(args[numargs - 2], ">") == 0)
    {
        int fd = creat(args[numargs - 1], FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1; /*indicar um erro*/
        }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    args[numargs - 2] = NULL;
    numargs = numargs - 2;
    }
    else if (strcmp(args[numargs - 2], ">>") == 0)
    {
        int fd = open(args[numargs - 1], O_WRONLY | O_APPEND, FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1; /*indicar um erro*/
        }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    args[numargs - 2] = NULL;
    numargs = numargs - 2;
    }
    else if (strcmp(args[numargs - 2], "<") == 0)
    {
        int fd = open(args[numargs - 1], O_RDONLY, FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1; /*indicar um erro*/
        }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    args[numargs - 2] = NULL;
    numargs = numargs - 2;
    }
    else
    {

        return -1;
    }
return numargs;
}
