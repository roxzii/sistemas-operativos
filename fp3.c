#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFFSIZE 1024
#define true 1
#define false 0
typedef char* string;

int compare(string str1, string str2){
    if (str1[0] == '\0' && str1[0] == str2[0]) return true;
    return (str1[0] == str2[0]) ? true * compare(&str1[1], &str2[1]) : false;
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
    if (n < 0)  perror("Erro de leitura!\n");
}

int main(int argv, char* argc[]){
    if (compare("UBI", "UBI")) printf("Hello\n");
    int g = fork();
    lseek;
    int FileIN = open("ints.bin", 0400);
    ioCopy(FileIN, 1);
    if (compare(argc[1], "EX") == true){
        printf("EX\n");
    }   else if (compare(argc[1], "NG") == true){
        printf("NG\n");
    }   else if (compare(argc[1], "NE") == true){
        printf("NE\n");
    }   else printf("Comando desconhecido\n");
    return 0;
}