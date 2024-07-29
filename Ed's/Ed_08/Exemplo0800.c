// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0800 - v0.0. - 04 / 10 / 2023
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

/** 
   printIntArray    - Mostrar arranjo com valores inteiros. 
   @param n        - quantidade de valores 
   @param array  - grupo de valores inteiros 
 */ 
void printIntArray ( int n, int array [ ] ) 
{ 
 // definir dado local 
    int x = 0; 
     
 // mostrar valores no arranjo 
    for ( x=0; x<n; x=x+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%2d: %d\n", x, array [ x ] ); 
    } // end for 
} // end printIntArray ( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int array [ ] = { 1, 2, 3, 4, 5 }; 
 
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    printIntArray ( 5, array ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0300 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" ); 
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break; 
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