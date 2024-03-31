#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Fork, fork, fork...
 *
 * (i) Zaimplementować program który utworzy dokłanie 32 procesy.
 *
 * (ii) Zaimplementować program, który czyta ze standardowego wejścia liczbę całkowitą i tworzy dokładnie tyle procesów.
 *
 * (iii) Zaimplementować program, który czyta ze standardowego wejścia liczby całkowite p, o, z, t.że p >= o + z
 *       i tworzy dokładnie p processów z których to o procesów jest sierotami i z procesów jest zombie.
 *       Zaobserwować co się dzieje z peleceniem `ps -al`.
 *
 * (iv) Dodać wypisywane informacji kiedy tworzony jest nowy proces i z jakim pid oraz kiedy się kończy.
 *
 */

void zadanie1()
{
	fork();
	fork();
	fork();
	fork();
	fork();
}

void zadanie2()
{
	int num;
    scanf("%d",&num);
    for(int i = 0; i < num; ++i)
    {
        if(fork() == 0)
        {
            printf("x");
            return 0;
        }
        wait(NULL);
    }
	

}

void zadanie3_4()
{
	int p, o, z;

    printf("Podaj liczby p, o, z: ");
    scanf("%d %d %d", &p, &o, &z);

    if (p < o + z) {
        fprintf(stderr, "Niepoprawne dane wejściowe.\n");
        exit(EXIT_FAILURE);
    }
    
    //zwykle procesy
    p=p-o-z;
    for(int i = 0; i < p; ++i)
    {
        if(fork() != 0)
        {
            printf("p ");
            printf("%d ", getpid());
        }
        wait(NULL);
       
    }
    //sieroty
    for(int i = 0; i < o; ++i)
    {
        if(fork() != 0)
        {
            printf("o ");
            printf("%d ", getpid());
            sleep(30);
            exit(0);
        }
        
    }
    
    //zombie
    for(int i = 0; i < z; ++i)
    {
        if(fork() != 0)
        {
           
            printf("z ");
            printf("%d ", getpid());
            exit(0);
        }
        
    }
    
}

int main() {
    
zadanie1();
zadanie2();
zadanie3_4();


    return 0;
}

