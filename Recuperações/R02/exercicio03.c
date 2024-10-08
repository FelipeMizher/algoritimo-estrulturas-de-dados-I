// 821811 - Felipe Rivetti Mizher

/*
 exercicio03 - v0.0. - 20 / 11 / 2023
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
    Função para trocar de lugar os dados
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} // end swap
/**
    Função para verificar se o array esta em ordem
*/
int verificarOrdem(int tamanho, int array[]){
 // definir dados
    int x = 0; 
    
    for(x = 0; x < tamanho - 1; x = x + 1){
        if(array[x] < array[x + 1]){
            return 0; // Não esta em ordem decrescente
        } 
    } 
    return 1; // esta em ordem decrescente
} // end verificarOrdem( )
/**
    Função para colocar os dados em ordem
*/
void ordernar(int tamanho, int array[]){
 // definir dados
    int troca = 0;
    int x = 0;
    
    do{
        troca = 0;
        
        for(x = 0; x < tamanho - 1; x = x + 1){
            if (array[x] < array[x + 1]) {
                swap(&array[x], &array[x + 1]);
                troca = 1;
            }
        }
    } while(troca);
} // end ordernar( )
/** 
   Method_01  
 */ 
void method_01 ( ) 
{ 
 // definir dados
    FILE *arquivo1;
    FILE *arquivo2;
    int tamanho = 0;
    int x = 0;
    
 // identificar 
    IO_id( "Method_01 - v0.0" ); 
    
 // abrir arquivo1
    arquivo1 = fopen("DADOS1.TXT", "rt");
    
 // ler o tamanho do array
    fscanf(arquivo1, "%d", &tamanho);
 
 // ler os dados do array
    int dados[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo1, "%d ", &dados[x]);
    } // end for
    
 // fechar arquivo1
    fclose(arquivo1);
    
 // abrir arquivo2
    arquivo2 = fopen("DECRESCENTE.TXT", "wt");
    
 // verificar se esta em ordem, e se não estiver colocar em ordem
    while(verificarOrdem(tamanho, dados) == 0){
        ordernar(tamanho, dados);
    } // end while
    
 // salvar o tamanho do array
    fprintf(arquivo2, "%d\n", tamanho);
    
 // salvar os dados em ordem no arquivo2
    for(x = 0; x < tamanho; x = x + 1){
        fprintf(arquivo2, "%d ", dados[x]);
    } // end for
    
 // fechar arquivo2
    fclose(arquivo2);
    
 // exibir mensagem de que foi salvo o novo arquivo
    printf("\nArquivo salvo com sucesso.\n");
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
    Função para inverter os dados do array
*/
void inverterArray(int tamanho, int array[]){
 // definir dados
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim) {
 // Trocar o primeiro elemento com o último
        int temp = array[inicio];
        array[inicio] = array[fim];
        array[fim] = temp;
 // Mover os índices para a próxima interação
        inicio++;
        fim--;
    }
}
/** 
   Method_02  
 */ 
void method_02 ( ) 
{ 
 // definir dados
    FILE *arquivo1;
    FILE *arquivo2;
    int x = 0, tamanho = 0;
    
 // identificar 
    IO_id( "Method_02 - v0.0" ); 
    
 // abrir arquivo1
    arquivo1 = fopen("DECRESCENTE.TXT", "rt");
    
 // ler o tamanho do array
    fscanf(arquivo1, "%d", &tamanho);
    
    int array[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo1, "%d", &array[x]);
    } // end for
    
 // fechar arquivo1
    fclose(arquivo1);
    
 // abrir arquivo2
    arquivo2 = fopen("INVERTIDOS.TXT", "wt");
    
 // chamar a função para inverter a ordem do array
    inverterArray(tamanho, array);
    
 // salvar o tamanho do array no novo arquivo
    fprintf(arquivo2, "%d\n", tamanho);
    
 // looping para gravar os dados invertidos no arquivo
    for(x = 0; x < tamanho; x = x + 1){
        fprintf(arquivo2, "%d ", array[x]);
    } // end for
    
 // fechar arquivo2
    fclose(arquivo2);
    
 // exibir mensagem para sinalizar que foi salvo o novo arquivo
    printf("Arranjo invertido salvo com sucesso.\n");
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
    Função para ordenar um array
*/
void arrayOrdenar(int tamanho, int array[]){
 // definir dados
    int i = 0, j = 0;
    
 // colocar os dados em ordem
    for(i = 0; i < tamanho - 1; i = i + 1){
        for(j = 0; j < tamanho - i - 1; j = j + 1){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}
/**
    Função para calcular a mediana do arranjo
*/
float arranjo_mediana(int tamanho, int array[]) {
 // definir dados
    int i = 0, j = 0;
    int meio1 = 0, meio2 = 0;
 
 // chamar a função para colocar os dados em ordem
    arrayOrdenar(tamanho, array);
 
 // Calcular a mediana
    if (tamanho % 2 == 0) {
 // Se o tamanho for par, média dos dois valores do meio
        meio1 = array[tamanho / 2 - 1];
        meio2 = array[tamanho / 2];
        return (float)(meio1 + meio2) / 2.0;
    } else {
 // Se o tamanho for ímpar, valor do meio
        return array[tamanho / 2];
    }
}
/**
    Função para calcular a moda do arranjo
*/
void arranjo_moda(int tamanho, int array[]){
 // definir dados
    int contagem = 0, i = 0, j = 0;
    int moda = array[0];
    int maxContagem = 1;
    int atual = 0, contAtual = 0;

 // calcular a moda
    for(i = 0; i < tamanho - 1; i++){
        atual = array[i];
        contAtual = 1;

        for(j = i + 1; j < tamanho; j++){
            if(array[j] == atual){
                contAtual++;
            }
        }

        if(contAtual > maxContagem){
            moda = atual;
            maxContagem = contAtual;
        }
    }

 // exibir o valor da moda calculado
    printf("Moda: %d\n", moda);
}
/** 
   Method_03  
 */ 
void method_03 ( ) 
{ 
 // definir dados
    FILE *arquivo;
    int tamanho = 0, x = 0;
    float mediana = 0;
    
 // identificar 
    IO_id( "Method_03 - v0.0" ); 
    
 // abrir arquivo
    arquivo = fopen("DADOS1.TXT", "rt");
 
 // ler o tamanho do array
    fscanf(arquivo, "%d", &tamanho);
    
 // ler os elementos do array
    int array[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo, "%d", &array[x]);
    } // end for
 
 // fechar arquivo   
    fclose(arquivo);
    
 // Calcular e imprimir a mediana
    mediana = arranjo_mediana(tamanho, array);
    printf("Mediana: %.2f\n", mediana);
    
 // Calcular e imprimir a moda
    arranjo_moda(tamanho, array);
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXERCICIO-03 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - exercicio_01" );
 IO_println ( "2 - exercicio_02" );
 IO_println ( "3 - exercicio_03" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,3] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )