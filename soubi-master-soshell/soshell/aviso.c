#include "shell.h"


void aviso (char *msg, int tempo)
{
    while (tempo > 0)
    {
        sleep (1);
        tempo--;
    }
    fprintf (stderr, "Aviso : %s\n", msg);
}

void * avisowrapper(void *args)
{
    aviso_t * ptr = (aviso_t *)args;
    aviso(ptr->msg, ptr->tempo);
    free(ptr);
    return NULL;
}