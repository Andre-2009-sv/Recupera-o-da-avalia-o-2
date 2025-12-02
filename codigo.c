#include <stdio.h>
#include <string.h>

#define MAX_ITENS 100
#define TAM_TEXTO 100

typedef struct {
    int id;
    char texto[TAM_TEXTO];
} Item;

int main() {
    Item lista[MAX_ITENS];
    int quantidade = 0;
    int proximoID = 1;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Consultar por palavra-chave\n");
        printf("3 - Listar todos os itens\n");
        printf("4 - Excluir item\n");
        printf("5 - Atualizar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        if (opcao == 1) {
            printf("Digite o conteúdo do item: ");
            fgets(lista[quantidade].texto, TAM_TEXTO, stdin);
            lista[quantidade].texto[strcspn(lista[quantidade].texto, "\n")] = '\0';

            lista[quantidade].id = proximoID++;
            quantidade++;

            printf("Item inserido com sucesso!\n");
        }

        else if (opcao == 2) {
            char palavra[TAM_TEXTO];
            printf("Digite a palavra-chave: ");
            fgets(palavra, TAM_TEXTO, stdin);
            palavra[strcspn(palavra, "\n")] = '\0';

            printf("\nItens encontrados:\n");
            for (int i = 0; i < quantidade; i++) {
                if (strstr(lista[i].texto, palavra) != NULL) {
                    printf("ID %d - %s\n", lista[i].id, lista[i].texto);
                }
            }
        }

        else if (opcao == 3) {
            printf("\nLista completa:\n");
            for (int i = 0; i < quantidade; i++) {
                printf("ID %d - %s\n", lista[i].id, lista[i].texto);
            }
        }

        else if (opcao == 4) {
            char escolha;
            printf("Excluir por (A) ID ou (B) Palavra-chave? ");
            scanf(" %c", &escolha);
            getchar();

            if (escolha == 'A' || escolha == 'a') {
                int idExcluir;
                printf("Digite o ID para excluir: ");
                scanf("%d", &idExcluir);

                int i, encontrado = 0;
                for (i = 0; i < quantidade; i++) {
                    if (lista[i].id == idExcluir) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    for (int j = i; j < quantidade - 1; j++)
                        lista[j] = lista[j+1];

                    quantidade--;
                    printf("Item removido.\n");
                } else {
                    printf("ID não encontrado.\n");
                }
            }

            else if (escolha == 'B' || escolha == 'b') {
                char palavra[TAM_TEXTO];
                printf("Digite a palavra para excluir: ");
                fgets(palavra, TAM_TEXTO, stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                int i = 0;
                while (i < quantidade) {
                    if (strstr(lista[i].texto, palavra) != NULL) {
                        for (int j = i; j < quantidade - 1; j++)
                            lista[j] = lista[j+1];
                        quantidade--;
                    } else {
                        i++;
                    }
                }
                printf("Itens removidos.\n");
            }
        }

        else if (opcao == 5) {
            int idUpdate;
            printf("Digite o ID do item para atualizar: ");
            scanf("%d", &idUpdate);
            getchar();

            int encontrado = 0;

            for (int i = 0; i < quantidade; i++) {
                if (lista[i].id == idUpdate) {
                    encontrado = 1;
                    printf("Digite o novo texto: ");
                    fgets(lista[i].texto, TAM_TEXTO, stdin);
                    lista[i].texto[strcspn(lista[i].texto, "\n")] = '\0';
                    printf("Item atualizado!\n");
                    break;
                }
            }

            if (!encontrado)
                printf("ID não encontrado.\n");
        }

    } while (opcao != 0);

    return 0;
}
