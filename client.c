#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    
	int server_fifo;
	char buf[MAX]
	mkfifo("toupperin", 0777);
	server_fifo=open("toupperin", 0777);
	write(server_fifo, buf,MAX);
	close(server_fifo);

}
