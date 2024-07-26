// 821811 - Felipe Rivetti Mizhe
/*
 Exemplo0613 - v0.0. - 27 / 09 / 2023
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
 Method_01a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method_01a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 // passar ao proximo
 method_01a ( x - 1 ); // motor da recursividade
 } // end if
} // end method_01a( )
/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "Method_01 - v0.0" );
// executar o metodo auxiliar
 method_01a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method_02a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // passar ao proximo
 method_02a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 } // end if
} // end method_02a( )
/**
 Method_02.
*/
void method_02 ( )
{
// identificar
 IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
 method_02a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method_03a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method_03a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%s\n", "Valor = 1" );
 } // end if
} // end method_03a( )
/**
 Method_03.
*/
void method_03 ( )
{
// identificar
 IO_id ( "Method_03 - v0.0" );
// executar o metodo auxiliar
 method_03a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method_04a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method_04a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", 2*(x-1) );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%s\n", "Valor = 1" );
 } // end if
} // end method_04a( )
/**
 Method_04.
*/
void method_04 ( )
{
// identificar
 IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
 method_04a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method_05a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method_05a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method_05a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%d: %d/%d\n", x, (2*(x-1)), (2*(x-1)+1) );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%d; %d\n", x, 1 );
 } // end if
} // end method_05a( )
/**
 Method_05.
*/
void method_05 ( )
{
// identificar
 IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
 method_05a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 somarFracoes - Somar certa quantidade de fracoes recursivamente.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracoes ( int x )
{
// definir dado local
 double soma = 0.0;
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // separar um valor e passar ao proximo (motor da recursividade)
 soma = (2.0*(x-1))/(2.0*(x-1)+1) + somarFracoes ( x - 1 );
 // mostrar valor
 IO_printf ( "%d: %lf/%lf\n", x, (2.0*(x-1)), (2.0*(x-1)+1) );
 }
 else
 {
 // base da recursividade
 soma = 1.0;
 // mostrar o ultimo
 IO_printf ( "%d; %lf\n", x, 1.0 );
 } // end if
// retornar resultado
 return ( soma );
} // end somarFracoes ( )
/**
 Method_06.
*/
void method_06 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Method_06 - v0.0" );
// chamar a funcao e receber o resultado
 soma = somarFracoes ( 5 );
// mostrar resultado
 IO_printf ( "soma = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados (controle)
 @param soma - valor atual da soma (historia = memoria)
 @param numerador - numerador da parcela a ser somada
 @param denominador - denominador da parcela a ser somada
*/
double somarFracoes2b ( int x, double soma, double numerador, double denominador )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar valores atuais
 IO_printf ( "%d: %lf/%lf\n", x, numerador, denominador );
 // somar o termo atual e passar ao proximo (motor da recursividade)
 soma = somarFracoes2b ( x - 1, // proximo
 soma + ((1.0*numerador) / denominador), // atualizar
 numerador +2.0 , // proximo
 denominador+2.0 ); // proximo
 } //end if
// retornar resultado
 return ( soma );
} // end somarFracoes2b ( )
/**
 somarFracoes2a - Somar certa quantidade de fracoes.
 Funcao de servico para preparar e 
 disparar o mecanismo recursivo.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracoes2a ( int x )
{
// definir dado local
 double soma = 0.0;
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar o ultimo
 IO_printf ( "%d: %lf\n", x, 1.0 );
 // preparar a soma do valor atual e o proximo
 soma = somarFracoes2b ( x-1, 1.0, 2.0, 3.0 );
 } // end if
// retornar resultado
 return ( soma );
} // end somarFracoes2a ( )
/**
 Method_07.
*/
void method_07 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Method_07 - v0.0" );
// chamar a funcao e receber o resultado
 soma = somarFracoes2a ( 5 );
// mostrar resultado
 IO_printf ( "soma = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 contarDigitos - Contar digitos recursivamente.
 @return quantidade de digitos
 @param x - numero cuja quantidade de digitos sera' calculada
*/
int contarDigitos ( int x )
{
// definir dado
 int resposta = 1; // base
// testar se contador valido
 if ( x >= 10 )
 {
 // tentar fazer de novo com valor menor
 resposta = 1 + contarDigitos ( x/10 ); // motor 1
 }
 else
 {
 if ( x < 0 )
 {
 // fazer de novo com valor absoluto
 resposta = contarDigitos ( -x ); // motor 2
 } // end if
 } // end if
// retornar resposta
 return ( resposta );
} // end contarDigitos ( )
/**
 Method_08.
*/
void method_08 ( )
{
// identificar
 IO_id ( "Method_08 - v0.0" );
// mostrar resultado
 IO_printf ( "digitos (%3d) = %d\n", 123, contarDigitos (123) );
 IO_printf ( "digitos (%3d) = %d\n", 1 , contarDigitos ( 1 ) );
 IO_printf ( "digitos (%3d) = %d\n", -10, contarDigitos ( -10 ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 fibonacci - Gerador de numero de Fibonacci.
 @return numero de Fibonacci
 @param x - numero de ordem cujo valor sera' calculado
*/
int fibonacci ( int x )
{
// definir dado
 int resposta = 0;
// testar se contador valido
 if ( x == 1 || x == 2 )
 {
 // primeiros dois valores iguais a 1
 resposta = 1; // bases
 }
 else
 {
 if ( x > 1 )
 {
 // fazer de novo com valor absoluto
 resposta = fibonacci ( x-1 ) + fibonacci ( x-2 );
 } // end if
 } // end if
// retornar resposta
 return ( resposta );
} // end fibonacci ( )
/**
 Method_09.
*/
void method_09 ( )
{
// identificar
 IO_id ( "Method_09 - v0.0" );
// calcular numero de Fibonacci
 IO_printf ( "fibonacci (%d) = %d\n", 1, fibonacci ( 1 ) );
 IO_printf ( "fibonacci (%d) = %d\n", 2, fibonacci ( 2 ) );
 IO_printf ( "fibonacci (%d) = %d\n", 3, fibonacci ( 3 ) );
 IO_printf ( "fibonacci (%d) = %d\n", 4, fibonacci ( 4 ) );
 IO_printf ( "fibonacci (%d) = %d\n", 5, fibonacci ( 5 ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 contarMinusculas - Contador de letras minusculas.
 @return quantidade de letras minusculas
 @param x - cadeia de caracteres a ser avaliada
*/
int contarMinusculas ( chars cadeia, int x )
{
// definir dado
 int resposta = 0;
// testar se contador valido
 if ( 0 <= x && x < strlen ( cadeia ) )
 {
 // testar se letra minuscula
 if ( cadeia [x] >= 'a' &&
 cadeia [x] <= 'z' )
 {
 // fazer de novo com valor absoluto
 resposta = 1;
 } // end if
 resposta = resposta + contarMinusculas ( cadeia, x+1 );
 } // end if
// retornar resposta
 return ( resposta );
} // end contarMinusculas ( )
/**
 Method_10.
*/
void method_10 ( )
{
// identificar
 IO_id ( "Method_10 - v0.0" );
// contar minusculas em cadeias de caracteres
 IO_printf ( "Minusculas (\"abc\",0) = %d\n", contarMinusculas ( "abc", 0 ) );
 IO_printf ( "Minusculas (\"aBc\",0) = %d\n", contarMinusculas ( "aBc", 0 ) );
 IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarMinusculas ( "AbC", 0 ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

void bloco_11 ( int x )
{
 int valor = 7;
// repetir enquanto valor maior que zero    
 if ( x > 0 )
 {
 valor = valor + (2 * x - 1);
 // passar ao proximo
 bloco_11 ( x - 1 ); // motor da recursividade
 // mostrar valor
 printf( "%s%d\n", "Valor = ", valor );
 } // end if
} // end method_11( )
/**
 Method_11
*/
void method_11 ( )
{
// definir dado
 int x = 0;
// identificar
 IO_id ( "Method_11 - v0.0" );
// ler do teclado
    printf("%s" , "Digite um valor para 'x': ");
    scanf("%d" , &x); getchar();
// executar o metodo auxiliar
 bloco_11 ( x ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_11 ( )

void bloco_12 ( int x )
{
 int valor = 0;
// repetir enquanto valor maior que zero    
 if ( x > 0 )
 {
 valor = valor + (7 * x);
 // mostrar valor
 printf( "%s%d\n", "Valor = ", valor );
// passar ao proximo
 bloco_12 ( x - 1 ); // motor da recursividade
 } // end if
} // end bloco12( )
/**
 Method_12
*/
void method_12 ( )
{
// definir dado
 int x = 0;
// identificar
 IO_id ( "Method_12 - v0.0" );
// ler do teclado
    printf("%s" , "Digite um valor para 'x': ");
    scanf("%d" , &x); getchar();
// executar o metodo auxiliar
 bloco_12 ( x ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_12 ( )

void bloco_13 ( int x )
{
 int valor = 0;
 double fracao = 0;
// repetir enquanto valor maior que zero    
 if ( x > 0 )
 {
 valor = valor + (7 * x);
 fracao = 1.0 / valor;
 // passar ao proximo
 bloco_13 ( x - 1 ); // motor da recursividade
 // mostrar valor
 printf("(1.0 / %d) = %lf\n", valor, fracao );
 } // end if
} // end bloco13( )
/**
 Method_13
*/
void method_13 ( )
{
// definir dado
 int x = 0;
// identificar
 IO_id ( "Method_13 - v0.0" );
// ler do teclado
    printf("%s" , "Digite um valor para 'x': ");
    scanf("%d" , &x); getchar();
// mostrar o valor inicial
    printf("(1.0 / 1.0) = 1\n");
// tirar uma unidade do 'x' para que seja mostrado o valor correto de numeros na tela.
    x = x - 1;
// executar o metodo auxiliar
 bloco_13 ( x ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_13 ( )

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0500 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" );
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
 IO_println ( "4 - method_04" );
 IO_println ( "5 - method_05" );
 IO_println ( "6 - method_06" );   
 IO_println ( "7 - method_07" );
 IO_println ( "8 - method_08" );    
 IO_println ( "9 - method_09" );
 IO_println ( "10 - method_10" ); 
 IO_println ( "11 - method_11" );
 IO_println ( "12 - method_12" );
 IO_println ( "13 - method_13" ); 
 /*IO_println ( "14 - method_14" );    
 IO_println ( "15 - method_15" ); 
 IO_println ( "16 - method_16" );
 IO_println ( "17 - method_17" ); 
 IO_println ( "18 - method_18" );
 IO_println ( "19 - method_19" );
 IO_println ( "20 - method_20" ); */    
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 printf ( "\nx = %d", x );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;         
 case 7: method_07 ( ); break;         
 case 8: method_08 ( ); break;   
 case 9: method_09 ( ); break;         
 case 10: method_10 ( ); break;  
 case 11: method_11 ( ); break;          
 case 12: method_12 ( ); break; 
 case 13: method_13 ( ); break;
 /*case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
 case 17: method_17 ( ); break;
 case 18: method_18 ( ); break;
 case 19: method_19 ( ); break;
 case 20: method_20 ( ); break;*/
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