// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0400 - v0.0. - 11 / 09 / 2023
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

/**
 Method_01 - Repeticao para ler certa quantidade de valores.
*/
void method_01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "Method 01 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat ( 
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
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

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 11/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. (OK) identificacao de programa
*/