// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0119 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0119 exemplo0119.c
 Windows: gcc -o exemplo0119 exemplo0119.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0119
 Windows: exemplo0119
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular a area de um semi-circulo.
void calcularArea(double X){
// Declara variavel para o calculo
    double area;
    
// Calculos para descobrir o valor do volume.
    X = X / 2;
    area = (M_PI * pow(X, 2)) / 2;
    
// Exibir o valor do volume com o raio valendo a metade.
    printf("A area do semi-circulo e': %lf\n" , area);
}

int main(){
// Declarar variavel
    double raio;

// Pedir ao usuario o valor do raio.
    printf("Digite um valor para o raio: ");
    scanf("%lf" , &raio); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função passando o 'RAIO' como um parametro.
    calcularArea(raio);

// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}