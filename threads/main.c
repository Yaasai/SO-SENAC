#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int contar_palavras(FILE *f) {
    int palavras = 0;
    char x[1024];
    while (fscanf(f, " %1023s", x) == 1) {
        palavras++;
    }
    return palavras;
}

void *ler_arquivo(char *filename) {
  FILE *fp;
  if((fp = fopen(filename, "r")) != NULL) {
    int numeroPalavras = contar_palavras(fp);
    printf("%d\n", numeroPalavras);
  }
  fclose(fp);

  return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("Pelo menos um arquivo é necessário.");
      return 1;
    }

    pthread_t t[argc-1];

    for (int i=1; i < argc; i++) { 
        pthread_create(&t[i-1], NULL, (void *)ler_arquivo, argv[i]); 
    }
    for (int i=1; i < argc; i++) { 
        pthread_join(t[i-1], NULL); 
    }

    return 0;
}