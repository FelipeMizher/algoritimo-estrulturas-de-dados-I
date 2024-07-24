// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0118 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0118 exemplo0118.c
 Windows: gcc -o exemplo0118 exemplo0118.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0118
 Windows: exemplo0118
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular o volume do paralelepipedo.
void CalcularParalelepipedo(double X, double Y, double Z){
// Declarar variavel para o calculo.
    double volume;
    
// Calculos para descobrir o valor do volume.
    X = X / 6;
    Y = Y / 6;
    Z = Z / 6;
    volume = X * Y * Z;
    
// Exibir o valor do volume com os parametros valendo um sexto.
    printf("O volume do paralelepipedo e': %lf\n" , volume);
}

int main(){
// Declarar variaveis.
    double comprimento, largura, altura;
    
// Pedir ao usuario os valores para os calculos.
    printf("Digite o valor do comprimento do paralelepipedo: ");
    scanf("%lf" , &comprimento); getchar();
    printf("Digite o valor do largura do paralelepipedo: ");
    scanf("%lf" , &largura); getchar();
    printf("Digite o valor do altura do paralelepipedo: ");
    scanf("%lf" , &altura); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'COMPRIMENTO', 'LARGURA' e 'ALTURA' e exibir o volume.
    CalcularParalelepipedo(comprimento, largura, altura);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}
