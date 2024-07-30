// 821811 - Felipe Rivetti Mizher

/*
  exercicio02 - v0.0. - 25 / 10 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )

int somaDivisoresImpares(int numeros){
 // definir dados
    int soma = 0;
    int x = 0;
 
 // looping para verificar os dvisores impares de cada valor do array e somar esses divisores caso exista.
    for(x = 1; x <= numeros; x = x + 1){
        if(numeros % x == 0 && numeros % 2 != 0){
             soma = soma + x;
        }
    }
 // retornar o valor da soma
    return soma;
} // end somaDivisoresImpares
void method_01(){
 // definir dados
    int n = 0;
    int x = 0;
 // identificar
    printf("exercicio_01\n");
    
 // pedir dados
    printf("\n%s", "Digite a quantidade 'n': ");
    scanf("%d", &n); getchar();
    
 // declarar um array para salvar os valores
    int valores[n];
    
 // ler os 'n' valores para o array
    for(x = 1; x <= n; x = x + 1){
        printf("Digite o %d° valor: ", x);
        scanf("%d", &valores[x]); getchar();
    }
    
 // chamar a função para mostrar a soma dos divisores impares de cada numero do array
    printf("\nSomas dos divisores ímpares para cada valor:\n");
    for (x = 1; x <= n; x = x + 1) {
        printf("%d - a soma dos divisores ímpares e': %d\n", valores[x], somaDivisoresImpares(valores[x]));
    }
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_01

int verificarPrimo(int numero){
 // definir dados
    int i = 0;
    
 // verificar se o valor do array é menor ou igual a 1, caso seja retornara '0' indicando que não é um numero primo
    if(numero <= 1){
        return 0;
    }
    
 // verificar se um numero é primo ou não
    for (i = 2; i * i <= numero; i = i + 1) {
        if (numero % i == 0) {
            return 0; // retornar '0' para não primos
        }
    }
    return 1; // retornar '1' para primos
} // end verificarPrimo
void method_02(){
 // definir dados
    int n = 0;
    int x = 0;
    int resultado = 0;
    
 // identificar
    printf("exercicio_02\n");
    
 // pedir dados
    printf("\n%s", "Digite a quantidade 'n': ");
    scanf("%d", &n); getchar();
    
 // declarar um array com 'n' termos
    int valores[n];
    
 // looping para ler os 'n' valores do array
    for(x = 1; x <= n; x = x + 1){
        printf("Digite o %d° valor: ", x);
        scanf("%d", &valores[x]); getchar();
    }
    
 // exibir o resultado para saber se cada numero inserido no array é primo ou nao
    printf("\nResultado:\n");
    for (x = 1; x <= n; x = x + 1) {
        resultado = verificarPrimo(valores[x]);
        if(resultado == 1){
            printf("%d - E' um numero primo.\n", valores[x]);
        } else{
            printf("%d - Nao e'um numero primmo.\n", valores[x]);
        }
    }
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_02

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "exercicio_02 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 -  exercicio_01" );
 IO_println ( "2 -  exercicio_02" );   
 //IO_println ( "3 -  exercicio_03" ); 
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;  
 //case 3: method_03 ( ); break; 
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )