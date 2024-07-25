// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0211 - v0.0. - 29 / 08 / 2023
 Author: ___Felipe Rivetti Mizher_______
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0211 exemplo0211.c
 Windows: gcc -o exemplo0211 exemplo0211.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0211
 Windows: exemplo0211
*/
// Dependencias
#include <stdio.h> // Para as entradas e saidas
#include <stdlib.h> // Para outras funcoes de uso geral

/**
 Method_01.
*/
void method_01 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", "Method_01" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero é impar ou par.
    if(X % 2 == 0){
        printf("O numero e' par (%d)\n" , X);
    } else {
        printf("O numero e' impar (%d)\n" , X);
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_01 ( )

/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// Definir dado
 int opcao = 0;
// Identificar
 printf ( "%s\n", "Exemplo0200 - Programa = v0.0" );
 printf ( "%s\n", "Autor: ______Felipe Rivetti Mizher______" );
 printf ( "\n" ); // Mudar de linha
// Acoes
// Repetir
 do
 {
 // Para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Method_01" );
 printf ( "\n" );
 // Ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // Para limpar a entrada de dados
 // Para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 // Escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: /* nao fazer nada */ break;
 case 1: method_01 ( ); break;
 default: // Comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // Rnd switch
 }
 while ( opcao != 0 );
// Encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // Aguardar por ENTER
 return ( 0 ); // Voltar ao SO (sem erros)
} // End main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios

    Sem erros ao executar o problema.
    
----------------------------------------------------------
*/