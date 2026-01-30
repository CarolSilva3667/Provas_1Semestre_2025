#include <stdio.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidadeEstoque;
}Produto;

Produto meuProduto;

int produtoCadastrado = 0; 

void cadastrarProduto() {
    printf("\n--- Cadastro de Produto ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", meuProduto.nome);
    printf("Código do produto: ");
    scanf("%d", &meuProduto.codigo);
    printf("Preço do produto: ");
    scanf("%f", &meuProduto.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &meuProduto.quantidadeEstoque);

    produtoCadastrado = 1;
    printf("\nProduto '%s' cadastrado com sucesso!\n", meuProduto.nome);
}

void visualizarProduto() {
    printf("\n--- Informações do Produto ---\n");
    printf("Nome: %s\n", meuProduto.nome);
    printf("Código: %d\n", meuProduto.codigo);
    printf("Preço: R$ %.2f\n", meuProduto.preco);
    printf("Quantidade em Estoque: %d\n", meuProduto.quantidadeEstoque);
}

void realizarCompra() {
    int compra;
    printf("\n--- Realizar Compra ---\n");
    printf("Produto: %s (Estoque atual: %d)\n", meuProduto.nome, meuProduto.quantidadeEstoque);
    printf("Quantos itens de '%s' foram comprados? ", meuProduto.nome);
    scanf("%d", &compra);

    if (compra > meuProduto.quantidadeEstoque) {
        printf("Quantidade insuficiente em estoque! Apenas %d unidades disponíveis.\n", meuProduto.quantidadeEstoque);
    }
    else {
        meuProduto.quantidadeEstoque -= compra;
        printf("Compra de %d unidades de '%s' realizada com sucesso.\n", compra, meuProduto.nome);
        printf("Novo estoque de '%s': %d\n", meuProduto.nome, meuProduto.quantidadeEstoque);
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu SuperMais Estoque ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Visualizar Informações do Produto\n");
        printf("3. Realizar Compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
                
            case 2:
                visualizarProduto();
                break;
                
            case 3:
                realizarCompra();
                break;
                
            case 0:
                printf("\nSaindo do sistema. Até logo!\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
