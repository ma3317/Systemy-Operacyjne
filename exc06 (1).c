#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * (i) Zaimplementować program który jako pierwszy parametr przyjmuje ścieżkę do pliku z kodem źródłowym c, kompiluje go
 *     i uruchamia plik wyjściowy.
 *
 * (ii) Umożliwić przekazywanie parametrów.
 *
 * (*) Przekazać stdin, stdout i stderr.
 *
 * (**) Niech program nie pozostawia żadnych nowych plików w folderze, tj. plik wykonywalny powinnien zostać usunięty
 *      po zakończeniu.
 *
 */
void zad1(char* path)
{
  char buf[100];
  char buf2[100];
  sprintf(buf,"gcc %s -o %s",path);
  sprintf(buf2,"./%s",path);
  system(buf);
  system(buf2);
    
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    zad1(*argv);
    return 0;
}
