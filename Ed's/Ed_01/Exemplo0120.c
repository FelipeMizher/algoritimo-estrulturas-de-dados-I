// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0120 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0120 exemplo0120.c
 Windows: gcc -o exemplo0120 exemplo0120.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0120
 Windows: exemplo0120
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular o volume de uma esfera.
void calcularVolume(double X){
// Declarar variavel;
    double area;
    
// Calculos para descobrir o valor do volume.
    X = X * 0.375;
    area = (4.0/ 3.0) * M_PI * pow(X , 3);
    
// Exibir o valor do volume com o parametro do raio.
    printf("O volume da esfera com três oitavos do raio e': %lf\n" , area);
}

int main(){
// Declarar variavel.
    double raio;

// Pedir ao usuario o valor do raio.
    printf("Digite o valor do raio: ");
    scanf("%lf" , &raio); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função passando o 'RAIO' como parametro.
    calcularVolume(raio);

// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}