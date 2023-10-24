#include <stdio.h>
#include <locale.h>

int calculaDeterminante(int matrix[3][3])  {
    int det = 0;

    for (int i = 0; i < 3; i++) {
        det += (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
    }

    return det;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int Linhas, Colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &Linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &Colunas);

    int Matriz1[Linhas][Colunas];
    int Matriz2[Linhas][Colunas];
    int MatrizSoma[Linhas][Colunas];
    int MatrizSubtracao[Linhas][Colunas];
    int MatrizMultiplicacao[Linhas][Colunas];
    int MatrizTransposta[Linhas][Colunas];
    int escolha;
    int Varloop = 1;
    int det = 0;

    while (Varloop == 1) {
        int MatrizAux = 0;

        printf("Preencha a matriz 1.\n");
        for (int i = 0; i < Linhas; i++) {
            for (int j = 0; j < Colunas; j++) {
                printf("Digite o número [%d,%d]: ", i + 1, j + 1);
                scanf("%d", &Matriz1[i][j]);
            }
        }

        printf("Preencha a matriz 2.\n");
        for (int i = 0; i < Linhas; i++) {
            for (int j = 0; j < Colunas; j++) {
                printf("Digite o número [%d,%d]: ", i + 1, j + 1);
                scanf("%d", &Matriz2[i][j]);
            }
        }

        printf("\nA matriz 1 é:\n");
        for (int i = 0; i < Linhas; i++) {
            for (int j = 0; j < Colunas; j++) {
                printf("%d ", Matriz1[i][j]);
            }
            printf("\n");
        }

        printf("\nA matriz 2 é:\n");
        for (int i = 0; i < Linhas; i++) {
            for (int j = 0; j < Colunas; j++) {
                printf("%d ", Matriz2[i][j]);
            }
            printf("\n");
        }

        printf("========================================================================================\n");
        printf("CALCULADORA DE MATRIZES.\n");
        printf("1 - para soma.\n2 - para subtração.\n3 - para multiplicação.\n4 - para transposta(matriz1).\n5 - para determinante(matriz1).\n6 - para sair .\n");
        printf("Escolha a operação digitando seu número no menu: ");
        scanf("%d", &escolha);
        printf("========================================================================================\n");

        switch (escolha) {
            case 1:    
            
            for (int i = 0; i < Linhas; i++) {
                for (int j = 0; j < Colunas; j++) {
                    MatrizSoma[i][j] = Matriz1[i][j] + Matriz2[i][j];
                }
            }
            printf("\nA matriz soma é:\n");
            for (int i = 0; i < Linhas; i++) {
                printf("| ");
                for (int j = 0; j < Colunas; j++) {
                    printf("%d | ", MatrizSoma[i][j]);
                }
                printf("\n");
            }
            break;
            case 2:        
            for (int i = 0; i < Linhas; i++) {
                for (int j = 0; j < Colunas; j++) {
                    MatrizSubtracao[i][j] = Matriz1[i][j] - Matriz2[i][j];
                }
            }
            printf("\nA matriz subtração é:\n");
            for (int i = 0; i < Linhas; i++) {
                printf("| ");
                for (int j = 0; j < Colunas; j++) {
                    printf("%d | ", MatrizSubtracao[i][j]);
                }
                printf("\n");
            }
            break;
            case 3:
            for (int i = 0; i < Linhas; i++ ){
                for (int j = 0; j < Colunas; j++) {
                    for ( int k = 0; k < Colunas; k++){
                        MatrizAux = MatrizAux + (Matriz1[i][k] * Matriz2[k][j]);
                    }
                    MatrizMultiplicacao[i][j] = MatrizAux;
                    MatrizAux = 0;
                }
            }
            printf("\nA matriz multiplicação é:\n");
            for (int i = 0; i < Linhas; i++) {
                printf("| ");
                for (int j = 0; j < Colunas; j++) {
                    printf("%d | ", MatrizMultiplicacao[i][j]);
                }
                printf("\n");
            }
            break;
            case 4:
            for (int i = 0; i < Linhas; i++) {
                for (int j = 0; j < Colunas; j++) {
                    MatrizTransposta[i][j] = Matriz1[j][i];
                }
            }
            printf("A matriz transposta é:\n");
            for (int i = 0; i < Linhas; i++) {
                printf("| ");
                for (int j = 0; j < Colunas; j++) {
                    printf("%d | ", MatrizTransposta[i][j]);
                }
                printf("\n");
            }
            break;
            case 5:
                det = calculaDeterminante(Matriz1);
                printf("O determinante da matriz é: %d.\n", det);
                break;
            case 6:
                Varloop = 0;
                printf("Obrigado por usar a calculadora.\n");
            break;
            default:
                printf("Nenhuma operação foi realizada.\n");
            }
            return 0;
        }
    }