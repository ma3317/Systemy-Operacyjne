#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX 512

void handle_request( int client_fifo, char* data){
    char data1[MAX];
    int i;
    for(i=0; i<MAX; i++){
        data[i]=toupper(data[i]);
    }
    write(client_fifo, data1, MAX);
}

int main()
{
    int client_fifo;
    char data[MAX];
    mkfifo("toupperin", 0777);
    client_fifo=open("toupperin",0777;
    
    mkfifo("toupperout", 0777);
    
    while(1){
        if((read(client_fifo, data, Max))==-1)
        {
            return -1;
        }
        
        int client_fifo2= open("toupperout", 0777);
        handle_request(client_fifo2, data);
	close(client_fifo2);
    }
	close(client_fifo);
    
    return 0;
}
