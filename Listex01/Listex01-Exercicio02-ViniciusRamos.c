#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ehPrimo (int n);

int numOperacoes = 0;

int main(){

    int numero;

    printf("Aula 02 - Exercicio 02 - Primalidade: \n\n");

    srand (time(NULL));
    numero = rand() % 100;

    printf("Numero inteiro gerado aleatoriamente (1-100): %d",numero);

    if (ehPrimo(numero)==1){
        printf("\nO numero %d eh Primo (Num. Operacoes = %d)",numero,numOperacoes);
    }
    else{
       printf("\nO numero %d NAO eh Primo (Num. Operacoes = %d)",numero,numOperacoes);
    }

    return 0;
}

int ehPrimo(int n){

    int primo = 1;

    for (int i=2; i<=n/2; i++){
        numOperacoes++;
        if (n%i==0){
            numOperacoes++;
            primo = 0;
            break;
        }
    }

    return primo;
}
