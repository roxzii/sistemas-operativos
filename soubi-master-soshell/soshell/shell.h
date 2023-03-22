#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>

void parse(char *buf, char **args);

void execute(char **args);

void redirects(char **args);

int builtin (char **args);

typedef struct
{
    char msg[100];
    int tempo;
} aviso_t;

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
