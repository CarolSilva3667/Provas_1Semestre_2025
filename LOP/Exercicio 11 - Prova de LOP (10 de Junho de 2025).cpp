#include <stdio.h>

typedef struct {
    char banda[50];
    int quantidade;
    float preco;
}CD;

CD cds[100];
int total = 0;

void cadastrarCD() {
    printf("Nome da banda: ");
    scanf(" %[^\n]", cds[total].banda);

    printf("Quantidade: ");
    scanf("%d", &cds[total].quantidade);

    printf("Preço: ");
    scanf("%f", &cds[total].preco);

    total++;
    printf("CD cadastrado!\n");
}

void venderCD() {
    char nome[50];
    int qtd;
    printf("Nome da banda: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < total; i++) {
        int j = 0;
        while (nome[j] == cds[i].banda[j] && nome[j] != '\0') j++;
        if (nome[j] == '\0' && cds[i].banda[j] == '\0') {
            printf("Quantidade a vender: ");
            scanf("%d", &qtd);
            if (qtd <= cds[i].quantidade) {
                cds[i].quantidade -= qtd;
                printf("Total: R$ %.2f\n", qtd * cds[i].preco);
            } else {
                printf("Estoque insuficiente!\n");
            }
            return;
        }
    }
    printf("CD não encontrado!\n");
}

void listarCD() {
    for (int i = 0; i < total; i++) {
        printf("Banda: %s | Quantidade: %d | Preço: R$ %.2f\n",
               cds[i].banda, cds[i].quantidade, cds[i].preco);
    }
}

int main() {
    int opcao;
    do {
      printf("--==Loja Som&Arte==--\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Listar CD\n");
        printf("0 - Sair\n");
        printf("Escolha a opçao que deseja: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
            cadastrarCD();
            break;
            case 2:
            venderCD();
            break;
            case 3:
            listarCD();
            break;
            case 0:
            printf("Saindo...\n");
            default:
            printf("Opcao inválida.\n");
        }
    } while(opcao != 0);
    
    return 0;
}