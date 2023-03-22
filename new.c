#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd, i;
	short vec[10];

	for (i = 0; i < 10; i++){
		vec[i] = i + 512;
	}

	fd = open("test.bin", O_RDONLY);
	if (fd < 0){
		perror("Erro com o ficheiro");
		return 1;
	}

	int bytesRead = read(fd, vec, sizeof(short)*10);
	if (bytesRead != 10 * sizeof(short)){
		fprintf(stderr, "Not enough bytes\n");
	}

	for (i = 0; i < 10; i++){
		printf("%d\n", vec[i]);
	}

	return (0);
}
