// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0704 - v0.0. - 04 / 10 / 2023
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
 writeInts - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeInts ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", y );
 } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeInts ( )
/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// identificar
 IO_id ( "Method_01 - v0.0" );
// executar o metodo auxiliar
 writeInts ( "DADOS1.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 readInts - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readInts ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0;
// tentar ler o primeiro
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
 while ( ! feof ( arquivo ) )
 {
 // mostrar valor
 printf ( "%d\n", x );
 // tentar ler o proximo
 fscanf ( arquivo, "%d", &x );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readInts ( )
/**
 Method_02.
*/
void method_02 ( )
{
// identificar
 IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
 readInts ( "DADOS1.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 writeDoubles - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeDoubles ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// gravar quantidade de valores
 IO_fprintf ( arquivo, "%d\n", x );
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
 } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeDoubles ( )
/**
 Method_03.
*/
void method_03 ( )
{
// identificar
 IO_id ( "Method_03 - v0.0" );
// executar o metodo auxiliar
 writeDoubles ( "DADOS2.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 readDoubles - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readDoubles ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0 ;
 int y = 1 ;
 double z = 0.0;
// tentar ler a quantidade de dados
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados e
// quantidade nao tiver sido alcancada
 while ( ! feof ( arquivo ) && y <= x )
 {
 // tentar ler
 fscanf ( arquivo, "%lf", &z );
 // mostrar valor
 printf ( "%2d: %lf\n", y, z );
 // passar ao proximo
 y = y + 1;
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readDoubles ( )
/**
 Method_04.
*/
void method_04 ( )
{
// identificar
 IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
 readDoubles ( "DADOS2.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 writeText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
 IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
 do
 {
 // ler do teclado
 strcpy ( linha, IO_readln ( "" ) );
 // gravar valor
 IO_fprintf ( arquivo, "%s\n", linha );
 }
 while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeText ( )
/**
 Method_05.
*/
void method_05 ( )
{
// identificar
 IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
 writeText ( "DADOS3.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

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
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
 IO_println ( "4 - method_04" );
 IO_println ( "5 - method_05" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break; 
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
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