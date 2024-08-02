// 821811 - Felipe Rivetti Mizher

/*
 Exemplo1018 - v0.0. - 29 / 10 / 2023
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
   Definicao de tipo arranjo com inteiros 
   baseado em estrutura 
 */ 
typedef 
 struct s_int_Array 
 { 
   int   length; 
   ints data  ; 
   int   ix    ; 
 } int_Array; 
 
/** 
   Definicao de referencia para arranjo com inteiros 
   baseado em estrutura 
 */ 
typedef int_Array* ref_int_Array;  
/** 
   new_int_Array - Reservar espaco para arranjo com inteiros 
   @return referencia para arranjo com inteiros 
   @param n - quantidade de datos 
 */ 
ref_int_Array new_int_Array ( int n ) 
{ 
 // reserva de espaco 
    ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array)); 
 
 // estabelecer valores padroes 
    if ( tmpArray == NULL ) 
    { 
       IO_printf ( "\nERRO: Falta espaco.\n" ); 
    } 
    else 
    { 
       tmpArray->length     =  0; 
       tmpArray->data        = NULL; 
       tmpArray->ix             = -1; 
       if ( n>0 ) 
       { 
        // guardar a quantidade de dados 
           tmpArray->length =  n; 
        // reservar espaco para os dados 
           tmpArray->data    = (ints) malloc (n * sizeof(int)); 
        // definir indicador do primeiro elemento 
           tmpArray->ix        =  0; 
       } // end if 
    } // end if 
 
 // retornar referencia para espaco reservado 
    return ( tmpArray ); 
} // end new_int_Array ( ) 
 
/** 
   free_int_Array - Dispensar espaco para arranjo com inteiros 
   @param tmpArray - referencia para grupo de valores inteiros 
 */ 
void free_int_Array ( ref_int_Array tmpArray ) 
{ 
 // testar se ha' dados, antes de reciclar o espaco 
    if ( tmpArray != NULL ) 
    { 
       if ( tmpArray->data != NULL ) 
       {  
          free ( tmpArray->data );  
       } // end if 
       free ( tmpArray ); 
    } // fim se 
} // end free_int_Array ( )  
/** 
   printIntArray    - Mostrar arranjo com valores inteiros. 
   @param array  - grupo de valores inteiros 
 */ 
void printIntArray ( int_Array array ) 
{ 
 // mostrar valores no arranjo 
    if ( array.data ) 
    { 
       for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 ) 
       { 
         // mostrar valor 
            printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] ); 
       } // end for 
    } // end if 
} // end printIntArray ( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int_Array array; 
 
 // montar arranjo em estrutura 
    array. length  = 5; 
    array. data     = (ints) malloc (array.length * sizeof(int)); 
 
 // testar a existência de dados 
    if ( array.data ) 
    { 
       array. data [ 0 ] = 1; 
       array. data [ 1 ] = 2; 
       array. data [ 2 ] = 3; 
       array. data [ 3 ] = 4; 
       array. data [ 4 ] = 5; 
    } // fim se 
     
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    printIntArray ( array ); 
 
 // reciclar o espaco 
    if ( array.data ) 
    { 
        free ( array.data ); 
    } // fim se 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

/**
 IO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com valores lidos
*/
int_Array IO_readintArray ( )
{
// definir dados locais
 chars text = IO_new_chars ( STR_SIZE );
 static int_Array array;
// ler a quantidade de dados
 do
 {
 array.length = IO_readint ( "\nlength = " );
 }
 while ( array.length <= 0 );
// reservar espaco para armazenar
 array.data = IO_new_ints ( array.length );
// testar se ha' espaco
 if ( array.data == NULL )
 {
 array.length = 0; // nao ha' espaco
 }
 else
 {
 // ler e guardar valores em arranjo
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // ler valor
 strcpy ( text, STR_EMPTY );
 array.data [ array.ix ]
 = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
 } // end for
 } // end if
// retornar arranjo
 return ( array );
} // end IO_readintArray ( )
/**
 Method_02.
*/
void method_02 ( )
{
// definir dados
 int_Array array;
// identificar
 IO_id ( "Method_02 - v0.0" );
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, int_Array array )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
// gravar quantidade de dados
 fprintf ( arquivo, "%d\n", array.length );
// gravar valores no arquivo, se existirem
 if ( array.data )
 {
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", array.data [ array.ix ] );
 } // end for
 } // end if
 
// fechar arquivo
 fclose ( arquivo );
} // end fprintIntArray ( )
/**
 Method_03.
*/
void method_03 ( )
{
// definir dados
 int_Array array;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar e gravar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 fprintIntArray ( "ARRAY1.TXT", array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 freadArraySize - Ler tamanho do arranjo com valores inteiros.
 @return quantidade de valores lidos
 @param fileName - nome do arquivo
*/
int freadArraySize ( chars fileName )
{
// definir dados locais
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 n = 0;
 } // end if
 fclose ( arquivo );
 } // end if
// retornar dados lidos
 return ( n );
} // end freadArraySize ( )
/**
 fIO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com os valores lidos
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
int_Array fIO_readintArray ( chars fileName )
{
// definir dados locais
 int x = 0;
 int y = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 static int_Array array;
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &array.length );
 // testar se ha' dados
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0; // nao ha' dados
 }
 else
 {
 // reservar espaco
 array.data = IO_new_ints ( array.length );
 // testar a existência
 if ( array.data )
 {
 // ler e guardar valores em arranjo
 array.ix = 0;
 while ( ! feof ( arquivo ) && 
 array.ix < array.length )
 {
 // ler valor
 fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
 // passar ao proximo
 array.ix = array.ix + 1;
 } // end while
 } // end if
 } // end if
 } // end if
// retornar dados lidos
 return ( array );
} // end fIO_readintArray ( )
/**
 Method_04.
*/
void method_04 ( )
{
// definir dados
 int_Array array; // arranjo sem tamanho definido
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method04 ( )

/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @return referencia para copia do arranjo
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
ref_int_Array copyIntArray ( int_Array array )
{
// definir dados locais
 int x = 0;
 int y = 0;
 ref_int_Array copy;
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0;
 }
 else
 {
 // reservar area
 copy = new_int_Array ( array.length );
 // testar se ha' descritor
 if ( copy )
 {
 copy->length = array.length;
 copy->data = IO_new_ints ( copy->length );
 // testar se ha' espaco e dados
 if ( copy->data == NULL || array.data == NULL )
 {
 printf ( "\nERRO: Falta espaco ou dados." );
 }
 else
 {
 // ler e copiar valores
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // copiar valor
 copy->data [ array.ix ] = array.data [ array.ix ];
 } // end for
 } // end if
 } // end if
 } // end if
// retornar dados lidos
 return ( copy );
} // end copyIntArray ( )
/**
 Method_05.
*/
void method_05 ( )
{
// definir dados
 int_Array array; // arranjo sem tamanho definido
 ref_int_Array other; // referencia para arranjo sem tamanho definido
// identificar
 IO_id ( "Method_05 - v0.0" );
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// copiar dados
 other = copyIntArray ( array );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntArray ( array );
 // mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntArray ( *other ); // dereferenciar a copia
 // reciclar os espacos
 free ( array.data );
 free ( other->data );
 free ( other );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef
struct s_int_Matrix
{
 int rows ;
 int columns;
 ints* data ;
 int ix, iy ;
}
int_Matrix;
/**
 Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix* ref_int_Matrix;
/**
 new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 @return referencia para arranjo com inteiros
 @param rows - quantidade de dados
 @param columns - quantidade de dados
*/
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
// reserva de espaco
 ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
 if ( tmpMatrix != NULL )
 {
 tmpMatrix->rows = 0;
 tmpMatrix->columns = 0;
 tmpMatrix->data = NULL;
 // reservar espaco
 if ( rows>0 && columns>0 )
 {
 tmpMatrix->rows = rows;
 tmpMatrix->columns = columns;
 tmpMatrix->data = malloc (rows * sizeof(ints));
 if ( tmpMatrix->data )
 {
 for ( tmpMatrix->ix=0;
 tmpMatrix->ix<tmpMatrix->rows;
 tmpMatrix->ix=tmpMatrix->ix+1 )
 {
 tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
 } // end for
 } // end if
 } // end if
 tmpMatrix->ix = 0;
 tmpMatrix->iy = 0;
 } // end if
 return ( tmpMatrix );
} // end new_int_Matrix ( )
/**
 free_int_Matrix - Dispensar espaco para arranjo com inteiros
 @param tmpMatrix - referencia para grupo de valores inteiros
*/
void free_int_Matrix ( ref_int_Matrix matrix )
{
// testar se ha' dados
 if ( matrix != NULL )
 {
 if ( matrix->data != NULL )
 {
 for ( matrix->ix=0;
 matrix->ix<matrix->rows;
 matrix->ix=matrix->ix+1 )
 {
 free ( matrix->data [ matrix->ix ] );
 } // end for
 free ( matrix->data );
 } // end if
 free ( matrix );
 } // end if
} // end free_int_Matrix ( )
/**
 printIntMatrix - Mostrar matrix com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntMatrix ( ref_int_Matrix matrix )
{
// testar a existencia
 if ( matrix != NULL && matrix->data != NULL )
 {
 // mostrar valores na matriz
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // mostrar valor
 printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
 } // end for
 printf ( "\n" );
 } // end for
 } // end if
} // end printIntArray ( )
/**
 Method_06.
*/
void method_06 ( )
{
// definir dado
 ref_int_Matrix matrix = new_int_Matrix ( 3, 3 );
 if ( matrix != NULL && matrix->data != NULL )
 {
 matrix->data [0][0] = 1; matrix->data [0][1] = 2; matrix->data [0][2] = 3;
 matrix->data [1][0] = 3; matrix->data [1][1] = 4; matrix->data [1][2] = 5;
 matrix->data [2][0] = 6; matrix->data [2][1] = 7; matrix->data [2][2] = 8;
 } // fim se
// identificar
 IO_id ( "Method_06 - v0.0" );
// executar o metodo auxiliar
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix IO_readintMatrix ( )
{
// definir dados locais
 int rows = 0;
 int columns = 0;
 chars text = IO_new_chars ( STR_SIZE );
// ler a quantidade de dados
 do
 { rows = IO_readint ( "\nrows = " ); }
 while ( rows <= 0 );
 do
 { columns = IO_readint ( "\ncolumns = " ); }
 while ( columns <= 0 );
// reservar espaco para armazenar valores
 ref_int_Matrix matrix = new_int_Matrix ( rows, columns );
// testar se ha' espaco
 if ( matrix != NULL )
 {
 if ( matrix->data == NULL )
 {
 // nao ha' espaco
 matrix->rows = 0;
 matrix->columns = 0;
 matrix->ix = 0;
 matrix->iy = 0;
 }
 else
 {
 // ler e guardar valores na matriz
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // ler e guardar valor
 strcpy ( text, STR_EMPTY );
 matrix->data [ matrix->ix ][ matrix->iy ]
 = IO_readint ( IO_concat (
 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
 } // end for
 printf ( "\n" );
 } // end for
 } // end if
 } // end if
// retornar dados lidos
 return ( matrix );
} // end IO_readintMatrix ( )
/**
 Method_07.
*/
void method_07 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
// identificar
 IO_id ( "Method_07 - v0.0" );
// ler dados
 matrix = IO_readintMatrix ( );
// mostrar dados
 IO_printf ( "\n" );
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
// testar se ha' dados
 if ( matrix == NULL )
 {
 printf ( "\nERRO: Nao ha' dados." );
 }
 else
 {
 // gravar quantidade de dados
 fprintf ( arquivo, "%d\n", matrix->rows );
 fprintf ( arquivo, "%d\n", matrix->columns );
 
 if ( matrix->data != NULL )
 {
 // gravar valores no arquivo
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
 } // end for
 } // end for
 } // end if
 // fechar arquivo
 fclose ( arquivo );
 } // end if
} // end fprintIntMatrix ( )
/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
// identificar
 IO_id ( "Method_08 - v0.0" );
// ler dados
 matrix = IO_readintMatrix ( );
// gravar dados
 fprintIntMatrix( "MATRIX1.TXT", matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
 @param fileName - nome do arquivo
*/
ref_int_Matrix freadintMatrix ( chars fileName )
{
// definir dados locais
 ref_int_Matrix matrix = NULL;
 int rows = 0;
 int columns = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 fscanf ( arquivo, "%d", &rows );
 fscanf ( arquivo, "%d", &columns );
 if ( rows <= 0 || columns <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // reservar espaco para armazenar
 matrix = new_int_Matrix ( rows, columns );
 // testar se ha' espaco
 if ( matrix != NULL && matrix->data == NULL )
 {
 // nao ha' espaco
 matrix->rows = 0;
 matrix->columns = 0;
 matrix->ix = 0;
 matrix->iy = 0;
 }
 else
 {
 // testar a existência
 if ( matrix != NULL )
 {
 // ler e guardar valores na matriz
 matrix->ix = 0;
 while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
 {
 matrix->iy = 0;
 while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
 {
 // guardar valor
 fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
 // passar ao proximo
 matrix->iy = matrix->iy+1;
 } // end while
 // passar ao proximo
 matrix->ix = matrix->ix+1;
 } // end while
 matrix->ix = 0;
 matrix->iy = 0;
 } // end if
 } // end if
 } // end if
// retornar matriz lida
 return ( matrix );
} // end freadintMatrix ( )
/**
 Method_09.
*/
void method_09 ( )
{
// identificar
 IO_id ( "Method_09 - v0.0" );
// ler dados
 ref_int_Matrix matrix = freadintMatrix ( "MATRIX1.TXT" );
// mostrar dados
 IO_printf ( "\n" );
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 copyIntMatrix - Copiar matriz com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix copyIntMatrix ( ref_int_Matrix matrix )
{
// definir dados locais
 ref_int_Matrix copy = NULL;
 if ( matrix == NULL || matrix->data == NULL )
 {
 IO_printf ( "\nERRO: Faltam dados.\n" );
 }
 else
 {
 if ( matrix->rows <= 0 || matrix->columns <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // reservar espaco
 copy = new_int_Matrix ( matrix->rows, matrix->columns );
 // testar se ha' espaco e dados
 if ( copy == NULL || copy->data == NULL )
 {
 printf ( "\nERRO: Falta espaco." );
 }
 else
 {
 // copiar valores
 for ( copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1 )
 {
 for ( copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1 )
 {
 // copiar valor
 copy->data [ copy->ix ][ copy->iy ]
 = matrix->data [ copy->ix ][ copy->iy ];
 } // end for
 } // end for
 } // end if
 } // end if
 } // end if
 
// retornar copia
 return ( copy );
} // end copyIntMatrix ( )
/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
 ref_int_Matrix other = NULL;
// identificar
 IO_id ( "Method_10 - v0.0" );
// ler dados
 matrix = freadintMatrix ( "MATRIX1.TXT" );
// copiar dados
 other = copyIntMatrix ( matrix );
// mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntMatrix ( matrix );
// mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntMatrix ( other );
// reciclar espaco
 free_int_Matrix ( matrix );
 free_int_Matrix ( other );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method10 ( )

int numeroAleatorio(int inicio,  int fim){
 // definir dados
    int numero = 0;
 
 // gerar os numeros aleatorios e armazenar na variavel 'numero'
    numero = rand() % (fim - inicio + 1) + inicio;
 
 // retornar o valor que esta em 'numero'
    return numero;
}
void method_11(){
 // definir dados
    int inicio = 0, fim = 0, valor = 0;
    int n = 0, x = 0;
    FILE *arquivo;
  
 // identificar
       IO_id ( "Method_11 - v0.0" );
    
 // pedir dados
    printf("%s", "Digite um valor para o inicio do limite: ");
    scanf("%d", &inicio); getchar();
    printf("%s", "Digite um valor para o fim do limite: ");
    scanf("%d", &fim); getchar();
    printf("%s", "Digite a quantidade de elementos a serem gerados dentro dos limites: ");
    scanf("%d", &n); getchar();
   
 // inicializar a função para gerar numeros aleatorios
    srand(time(NULL));
 
 // abrir arquivo
    arquivo = fopen("DADOS.TXT", "wt");
   
 // exibir para o usuario e gravar em um arquivo o numero de elementos e esse elementos gerados aleatoriamente
    printf("\n%d\n", n);
    fprintf(arquivo, "%d\n", n);
    
    for(x = 1; x <= n; x = x + 1){
        valor = numeroAleatorio(inicio, fim);
        printf("%d\n", valor);
        fprintf(arquivo, "%d\n", valor);
    }
  
 // fechar arquivo
    fclose(arquivo);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );    
} // end method_11

int* readArrayFromFile(char* fileName, int* size) {
 // definir e abrir o arquivo
    FILE* arquivo = fopen(fileName, "rt");

 // ler o primeiro valor do arquivo, que é o tamanho do array
    fscanf(arquivo, "%d", size);
    
 // alocar um espaço na memoria para o tamanho do array
    int* array = (int*)malloc(sizeof(int) * (*size));

 // ler todos os dados do array
    for (int i = 0; i < *size; i++) {
        fscanf(arquivo, "%d", &array[i]);
    } // end for

 // fechar arquivo
    fclose(arquivo);
   
 // retornar o array
    return array;
}
int arraySearch(int valor, int* array, int size){
 // definir dados
    int x = 0;
    
 // looping para verificar se o valor digitado pelo usuario esta entre os elementos do array
    for(x = 0; x < size; x = x + 1){
        if(array[x] == valor){
            return x;
        }
    } // end for
    return 0;
} // end arraySearch
void method_12(){
 // definir dados
    char* fileName = "DADOS.TXT";
    int* array;
    int size;
    int valor = 0, resultado = 0;
    
 // identificar
    IO_id ( "Method_12 - v0.0" );

 // chamar a função para ler os dados do arquivo
    array = readArrayFromFile(fileName, &size);
    
 // pedir o valor a ser procurado
    printf("Digite o valor que deseja procurar: ");
    scanf("%d", &valor); getchar();

 // chamar a função para verificar se existe o valor dentro do array
    resultado = arraySearch(valor, array, size);

 // exibir o resultado caso exista ou não o valor no array
    if (resultado != 0) {
        printf("\nO valor %d foi encontrado no índice %d do arranjo.\n", valor, resultado);
    } else {
        printf("\nO valor %d não foi encontrado no arranjo.\n", valor);
    }

 // liberar a memoria
    free(array);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_12

int arrayCompare(int* arr1, int size1, int* arr2, int size2){
 // definir dados
    int x = 0;
    
 // verificar se o tamanho dos arrays são compatíveis
    if (size1 != size2) {
        printf("\nO tamanho dos arrays sao incompativeis");
    }

 // passar pelos valores em cada arquivo para verificar se são iguais ou não
    for (int x = 0; x < size1; x++) {
        if (arr1[x] != arr2[x]) {
            return 0;
        }
    }

    return 1;
}
void method_13(){
 // definir dados
    char* fileName1 = "DADOS1.TXT";
    char* fileName2 = "DADOS2.TXT";
    int* array1;
    int* array2;
    int size1, size2, resultado;
    
 // identificar
    IO_id ( "Method_13 - v0.0" );

 // chamar a função 'readArrayFromFile' para os dois arquivos
    array1 = readArrayFromFile(fileName1, &size1);
    array2 = readArrayFromFile(fileName2, &size2);

 // chamar a função para comparar os arquivos
    resultado = arrayCompare(array1, size1, array2, size2);

 // exibir o resultado de acordo com o resultado que vier da função
    if (resultado == 1) {
        printf("\nOs arranjos são iguais.\n");
    } else {
        printf("\nOs arranjos são diferentes.\n");
    }

 // liberar o espaço da memoria
    free(array1);
    free(array2);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_13

int* arrayAdd(int* array1, int size1, int* array2, int constante) {
 // definir dados
    int* resultado = 0;
    int i = 0;

 // alocar um espaço para o array
    resultado = (int*)malloc(sizeof(int) * size1);

 // fazer a soma do primeiro array com o segundo multiplicado pela constante
    for (i = 0; i < size1; i++) {
        resultado[i] = array1[i] + constante * array2[i];
    }

 // retornar o resultado da soma dos arrays
    return resultado;
}
void method_14(){
 // definir dados
    char* fileName1 = "DADOS1.TXT";
    char* fileName2 = "DADOS2.TXT";
    int* array1;
    int* array2;
    int size1, size2;
    int* soma = 0, constante = 0;
    
 // identificar
    IO_id ( "Method_14 - v0.0" );

 // chamar a função para ler os dois arrays
    array1 = readArrayFromFile(fileName1, &size1);
    array2 = readArrayFromFile(fileName2, &size2);

 // pedir dados
    printf("%s", "Digite a constante: ");
    scanf("%d", &constante); getchar();

 // chamar a função para somar os arrays
    soma = arrayAdd(array1, size1, array2, constante);

 // condição para se os tamanhos forem diferentes não fazer a soma
    if (size1 != size2) {
        printf("\nTamanhos dos arranjos incompatíveis.\n\n");
    } else{
        printf("Resultado da soma com escala:\n");
        for (int i = 0; i < size1; i++) {
            printf("%d\n", soma[i]);
        }
    }

 // liberar a memoria
    free(array1);
    free(array2);
    free(soma);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_14

int isArrayDecrescent(int* array, int size){
 // definir dados
    int i = 0;

 // lopping para verificar se um numero é maior que o proximo
    for (i = 0; i < size - 1; i++) {
        if (array[i] < array[i + 1]) {
            return 0;
        }
    }
    return 1;
}
void method_15(){
 // definir dados
    char *fileName = "DADOS1.TXT";
    int* array;
    int size;
    int resultado = 0;
    
 // identificar
    IO_id ( "Method_15 - v0.0" );

 // chamar função para ler o array
    array = readArrayFromFile(fileName, &size);

 // chamar a função para mostrar o resultado
    resultado = isArrayDecrescent(array, size);

 // exibir resultado de acordo com o é retornado da função
    if (resultado) {
        printf("\nO arranjo está em ordem decrescente.\n");
    } else {
        printf("\nO arranjo não está em ordem decrescente.\n");
    }
 // liberar a memoria
    free(array);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );  
} // end method_15

int** readMatrixFromFile(const char* fileName, int* rows, int* cols){
 // definir dados
    FILE* file = fopen(fileName, "rt");
    int** matrix;
    int i = 0, j = 0;

 // ler os dois primeiros termos do arquivo que são as linhas e as colunas
    fscanf(file, "%d", rows);
    fscanf(file, "%d", cols);

 // definir um espaço para o array na memoria
    matrix = (int**)malloc(sizeof(int*) * (*rows));

 // looping para ler os termos da matrix
    for (i = 0; i < *rows; i = i + 1) {
        matrix[i] = (int*)malloc(sizeof(int) * (*cols));
        for (j = 0; j < *cols; j = j + 1) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

 // fechar o arquivo
    fclose(file);
    
 // retornar a matrix 
    return matrix;
}
int** matrixTranspose(int** matrix, int rows, int cols){
 // definir dados
    int** transpose;
    int i = 0, j = 0;

 // alocar um espaço para a transposta da matrix
    transpose = (int**)malloc(sizeof(int*) * cols);
    
 // looping para montar a transposta da matrix do arquivo
    for (i = 0; i < cols; i = i + 1){
        transpose[i] = (int*)malloc(sizeof(int) * rows);
        for (j = 0; j < rows; j = j + 1){
            transpose[i][j] = matrix[j][i];
        }
    }

 // retornar a matrix transposta
    return transpose;
}
void method_16(){
 // definir dados
    char* fileName = "DADOS1.TXT";
    int** matrix1;
    int** matrix2;
    int rows1, cols1;
    int i = 0, j = 0;
    
  // identificar
    IO_id ( "Method_16 - v0.0" );

 // chamar as funções 
    matrix1 = readMatrixFromFile(fileName, &rows1, &cols1);
    matrix2 = matrixTranspose(matrix1, rows1, cols1);

 // mostrar a matrix original e sua tranposta
    printf("\nMatriz original:\n");
    for (i = 0; i < rows1; i = i + 1) {
        for (j = 0; j < cols1; j = j + 1) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Transposta da matriz:\n");
    for (i = 0; i < cols1; i = i + 1) {
        for (j = 0; j < rows1; j = j + 1) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // Libere a memória alocada para as matrizes
    for (i = 0; i < rows1; i = i + 1) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (i = 0; i < cols1; i = i + 1) {
        free(matrix2[i]);
    }
    free(matrix2);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end metod_16

int matrixZero(int** matrix, int rows, int cols) {
 // definir dados
    int i = 0, j = 0;
    
 // compara os valores da matrix com o numero '0'
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}
void method_17(){
 // definir dados
    char *fileName = "DADOS1.TXT";
    int** matrix1;
    int rows1, cols1;
    int resultado = 0;
    
  // identificar
    IO_id ( "Method_17 - v0.0" );

 // chamar a função para ler a matrix do arquivo
    matrix1 = readMatrixFromFile(fileName, &rows1, &cols1);

 // chamar a função para mostrar o resultado
    resultado = matrixZero(matrix1, rows1, cols1);

 // exibir o resultado de acordo com o da função
    if (resultado) {
        printf("A matriz contém apenas zeros.\n");
    } else {
        printf("A matriz não contém apenas zeros.\n");
    }

 // Libere a memória alocada para a matriz
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_17

int matrixCompare(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2){
 // definir dados
    int i = 0, j = 0;
    
 // verificar se o numero de linhas e colunas sao iguais
    if (rows1 != rows2 || cols1 != cols2) {
        return 0;
    }

 // compara os elementos das linhas e das colunas das duas matrizes
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}
void method_18(){
 // definir dados
    char* fileName1 = "DADOS1.TXT";
    char* fileName2 = "DADOS2.TXT";
    int** matrix1;
    int** matrix2;
    int rows1, cols1, rows2, cols2;
    int resultado = 0; 

  // identificar
    IO_id ( "Method_18 - v0.0" );
    
 // chmar a função para ler as matrizes 
    matrix1 = readMatrixFromFile(fileName1, &rows1, &cols1);
    matrix2 = readMatrixFromFile(fileName2, &rows2, &cols2);

 // chamar a função para mostrar o resultado
    resultado = matrixCompare(matrix1, rows1, cols1, matrix2, rows2, cols2);

 // exibir o resultado de acordo com o que foi retornado
    if (resultado) {
        printf("\nAs matrizes são iguais.\n");
    } else {
        printf("\nAs matrizes não são iguais.\n");
    }

 // Libere a memória alocada para as matrizes
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_18

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO1018 - Programa - v0.0" );
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
 IO_println ( "14 - method_14" );
 IO_println ( "15 - method_15" );
 IO_println ( "16 - method_16" );
 IO_println ( "17 - method_17" );
 IO_println ( "18 - method_18" );
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
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 case 11: method_11 ( ); break;
 case 12: method_12 ( ); break;
 case 13: method_13 ( ); break;
 case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
 case 17: method_17 ( ); break;
 case 18: method_18 ( ); break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,18] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )