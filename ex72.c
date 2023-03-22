main(int argc, char *argv[])
{
	int fdIn, fdOut;

	fdIn = open(argv[1]);
	if (fdIn < 0){
		perror("Erro ao abrir ficheiro\n");
	}
	fdOut = creat(argv[2]);
	
	void ioCopy(fdIn, fdOut);
}
