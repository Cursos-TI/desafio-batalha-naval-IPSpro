#include <stdio.h>
#include <string.h> //biblioteca de manipulação de strings para uso da função strcmp

// Desafio Batalha Naval - MateCheck

int main() {

    int tabuleiro [10] [10] = {0}; //definindo a matriz tabuleiro com tamanho de 10 linhas e 10 colunas e todas as células iguais a 0.
    
    //Local do navio horizontal
    tabuleiro [7] [7] = 3;
    tabuleiro [7] [8] = 3;
    tabuleiro [7] [9] = 3;

    //Local do navio vertical
    tabuleiro [2] [4] = 3;
    tabuleiro [3] [4] = 3;
    tabuleiro [4] [4] = 3;
    tabuleiro [5] [4] = 3;

    //Local do navio diagonal 1
    tabuleiro [7] [0] = 3;
    tabuleiro [6] [1] = 3;
    tabuleiro [5] [2] = 3;

    //Local do navio diagonal 2
    tabuleiro [0] [1] = 3;
    tabuleiro [1] [2] = 3;
    

    printf("--- Bem Vindo ao Tabuleiro de Batalha Naval em C! O único \"BattleShip-C\" ---\n\n"); //Título. A \ é necessária para " em printf

    printf("   A  B  C  D  E  F  G  H  I  J\n"); //primeira linha do tabuleiro. As letras.

    for (int i = 0; i < 10; i++) { //loop for com 10 repetições (0 a 9). Loop Aninhado externo.

        //bloco if para corrigir espaçamento extra do dígito 10.
        if (i < 9) { //se i for igual a 8:
        printf("%d  ", i+1); //imprimir no console de 1 a 9 com dois espaços na frente
        } else {printf("%d ", i+1);} //caso contrário, imprimir o valor 10 com um espaço apenas

        for (int j = 0; j < 10; j++) { //loop for com mais 10 repetições (0 a 9). Loop aninhado interno.

            printf("%d  ", tabuleiro [j] [i]); //imprimir no console todas as células da matriz.
        }
        printf("\n"); //descer uma linha após o término do loop interno(cada loop interno imprime uma linha da matriz)
    }
    printf("\n");


    char tab1 [10] = {'A','B','C','D','E','F','G','H','I','J'}; //Vetor de Letras
    int  tab2 [10] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10}; //Vetor de numeros (1 a 10)
    char tabela [10]/*linhas*/ [10]/*colunas*/ [4]/*tamanho max dos elementos*/; //inicialização de uma matriz de posições (para facilitar utilização do programa pelo usuário)
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sprintf(tabela[i][j], "%c%d", tab1[i], tab2[j]); //A função Sprintf serve, neste caso, para IMPRIMIR o valor dos dois vetores na matriz Tabela.
        }
        
    }
    

    int poder = 0;
    char casa[3];
    printf ("É hora do Ataque!\nEscolha qual PODER utilizar:\n\n");

    while (poder < 1 || poder > 3) {
        printf ("1. Cone\n2. Cruz\n3. Octaedro\n");
        scanf("%d", &poder);

        switch (poder)
        {

            case 1:
                printf("Escolha a casa para lançar o PODER: (Ex: A1, B2, E3)\n");
                scanf("%s", casa); //%s para STRINGS(conjuntos de caracteres que ocupam mesmo indice)
                for (int j = 0; j < 10; j++) {
                    for (int i = 0; i < 10; i++) {
                        if (strcmp(tabela[i][j], casa) == 0) { 
                            /*a função strcmp é utilizada para testes de igualdade ou diferença entre Strings.
                            Destaca-se que esta matriz (tabela [10] [10]) não é uma string. O teste da função, neste caso,
                            está sendo feito no conteúdo desta matriz, que são as Strings aqui utilizadas para indicar a posição (A1, B5, F1...).
                            O que esta comparaç~~ao faz. É descobrir qual é a posição que o usuário escolheu na matriz(Descobre o valor numérico).
                            */
                            tabuleiro[i] [j] = 1; //posição central do efeito, sendo trasnformada em 1
                            //variações com somas e subtrações para formar o desenho do efeito no tabuleiro(matriz)
                            tabuleiro[i] [j+1] = 1;
                            tabuleiro[i] [j-1] = 1;
                            tabuleiro[i+1] [j] = 1;
                            tabuleiro[i-1] [j] = 1;
                            tabuleiro[i+1] [j+1] = 1;
                            tabuleiro[i+2] [j+1] = 1;
                            tabuleiro[i-1] [j+1] = 1;
                            tabuleiro[i-2] [j+1] = 1;
                        }
                    }
                }

                printf("\nBOOM!\n\n");

                printf("   A  B  C  D  E  F  G  H  I  J\n");
                for (int i = 0; i < 10; i++) { //loop for com 10 repetições (0 a 9). Loop Aninhado externo.

                    //bloco if para corrigir espaçamento extra do dígito 10.
                    if (i < 9) { //se i for igual a 8:
                    printf("%d  ", i+1); //imprimir no console de 1 a 9 com dois espaços na frente
                    } else {printf("%d ", i+1);} //caso contrário, imprimir o valor 10 com um espaço apenas
            
                    for (int j = 0; j < 10; j++) { //loop for com mais 10 repetições (0 a 9). Loop aninhado interno.
            
                        printf("%d  ", tabuleiro [j] [i]); //imprimir no console todas as células da matriz.
                    }
                    printf("\n");
                }

                break;
            
            case 2:
                printf("Escolha a casa para lançar o PODER: (Ex: A1, B2, E3)\n");
                scanf("%s", casa);
                for (int j = 0; j < 10; j++) {
                    for (int i = 0; i < 10; i++) {
                        if (strcmp (tabela[i] [j], casa) == 0) {
                            tabuleiro [i] [j] = 1;
                            tabuleiro [i] [j+1] = 1;
                            tabuleiro [i] [j-1] = 1;
                            tabuleiro [i+1] [j] = 1;
                            tabuleiro [i-1] [j] = 1;
                        }
                    }
                }

                printf("\nBOOM!\n\n");

                printf("   A  B  C  D  E  F  G  H  I  J\n");
                for (int i = 0; i < 10; i++) { //loop for com 10 repetições (0 a 9). Loop Aninhado externo.

                    //bloco if para corrigir espaçamento extra do dígito 10.
                    if (i < 9) { //se i for igual a 8:
                    printf("%d  ", i+1); //imprimir no console de 1 a 9 com dois espaços na frente
                    } else {printf("%d ", i+1);} //caso contrário, imprimir o valor 10 com um espaço apenas
            
                    for (int j = 0; j < 10; j++) { //loop for com mais 10 repetições (0 a 9). Loop aninhado interno.
            
                        printf("%d  ", tabuleiro [j] [i]); //imprimir no console todas as células da matriz.
                    }
                    printf("\n");
                }

                break;

            case 3:
                
                printf("Escolha a casa para lançar o PODER: (Ex: A1, B2, E3)\n");
                scanf("%s", casa);
                for (int j = 0; j < 10; j++) {
                    for (int i = 0; i < 10; i++) {
                        if (strcmp (tabela[i] [j], casa) == 0) {
                            tabuleiro [i] [j] = 1;
                            tabuleiro [i] [j+1] = 1;
                            tabuleiro [i] [j-1] = 1;
                            tabuleiro [i+1] [j] = 1;
                            tabuleiro [i+2] [j] = 1;
                            tabuleiro [i-1] [j] = 1;
                            tabuleiro [i-2] [j] = 1;
                        }
                    }
                }

                printf("\nBOOM!\n\n");

                printf("   A  B  C  D  E  F  G  H  I  J\n");
                for (int i = 0; i < 10; i++) { //loop for com 10 repetições (0 a 9). Loop Aninhado externo.

                    //bloco if para corrigir espaçamento extra do dígito 10.
                    if (i < 9) { //se i for igual a 8:
                    printf("%d  ", i+1); //imprimir no console de 1 a 9 com dois espaços na frente
                    } else {printf("%d ", i+1);} //caso contrário, imprimir o valor 10 com um espaço apenas
            
                    for (int j = 0; j < 10; j++) { //loop for com mais 10 repetições (0 a 9). Loop aninhado interno.
            
                        printf("%d  ", tabuleiro [j] [i]); //imprimir no console todas as células da matriz.
                    }
                    printf("\n");
                }

            break;

            default:
                printf("Esta não é uma opção válida!");
                break;
        }
    }
    
    printf("\n");
    return 0;
}