#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#define BUFFSIZE 128
void socp (char *fonte, char *destino)
{
    int fdin = open(*fonte, O_RDONLY);
    int fdout = open(*destino, O_CREAT|O_WRONLY);
    ioCopy(fdin, fdout);
    close(fdout);
    return 0;
}

void ioCopy (int IN, int OUT) //no error reporting
{
 int n;
 char buf[BUFFSIZE];
 while ( ( n = read (IN, buf, BUFFSIZE)) > 0)
 {
 if (write (OUT, buf, n) != n)
 perror("Erro de escrita!\n");
 }
 if (n < 0)
 perror("Erro de leitura!\n");
}
