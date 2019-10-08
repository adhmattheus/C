#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max 100

char valorBase[Max];
int valorDecimal;

void vetorinvertido(char *Vetor, int cont){
    int j= 0, k= 0;
    char aux_troca[Max];
    j= 0;
    k= cont-1;
    while (j < k) {
        aux_troca[j]= Vetor[j];
        Vetor[j]= Vetor[k];
        Vetor[k]= aux_troca[j];
        j++;
        k--;
    }
}
char* decimaltodasbases(int Valordecimal, int Base){
    int i= 0, valor= 0;
    while (Valordecimal) {
        valor= Valordecimal%Base;
        if (Base<= 10 || valor< 10) {
            valorBase[i]= valor+48;
        }
        else {
            valorBase[i]= valor+55;
        }
        Valordecimal/= Base;
        i++;
    }
    valorBase[i]= '\0';
    vetorinvertido(valorBase, i);
    return valorBase;
}
int todasbasesdecimal(char *N, int Base){
    int tamanho= 0,i;
    tamanho= (int)strlen(N);
    vetorinvertido(N, (int)strlen(N));
    for (i= 0; i< tamanho; i++) {
        if (N[i]>=48&&N[i]<= 59) {
            valorDecimal+= pow(Base, i)*(N[i]-48);
        }
        else {
            valorDecimal+= pow(Base, i)*(N[i]-65+10);
        }
    }
    return valorDecimal;
}
void converter(int opcao){
    int value= 0, base= 0;
    switch (opcao) {
        case 1:
            printf("Insira o número decimal: ");
            scanf("%d", &value);
            printf("Insira a base que deseja converter (2, 8 e 16): ");
            scanf("%d", &base);
            printf("O valor convertido é: %s\n", decimaltodasbases(value, base));
            break;

        case 2:
            printf("Insira um número em binario para converter para qualquer base: ");
            scanf("%s", valorBase);
            printf("Digite a base para qual deseja converter (8, 10 e 16): ");
            scanf("%d", &base);
            printf("O valor convertido é: %s\n", decimaltodasbases(todasbasesdecimal(valorBase, 2), base));
            break;

        case 3:
            printf("Insira um número em octal converter para qualquer base: ");
            scanf("%s", valorBase);
            printf("Insira a base para qual deseja converter (2, 10 e 16): ");
            scanf("%d", &base);
            printf("O valor convertido é: %s\n", decimaltodasbases(todasbasesdecimal(valorBase, 8), base));
            break;

        case 4:
            printf("Insira um número em octal converter para qualquer base: ");
            scanf("%s", valorBase);
            printf("Insira a base para qual deseja converter (2, 8 e 10): ");
            scanf("%d", &base);
            printf("O valor convertido é: %s\n", decimaltodasbases(todasbasesdecimal(valorBase, 16), base));
            break;

        default:
            break;
    }
}
int main(){
    int option= 0;
            printf("\n-------CONVERSOR DE BASES NUMÉRICAS--------");
            printf("\n1-Decimal.\n");
            printf("2-Binario.\n");
            printf("3-Octal.\n");
            printf("4-Hexadecimal.\n");
            printf("Insira sua opção: ");
            scanf("%d", &option);
            converter(option);

return 0;
}