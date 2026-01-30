#include <stdio.h>

#define MAX_PIZZAS 100
#define MAX_CLIENTES 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
    int disponivel;
}Pizza;

typedef struct {
    char nome[MAX_NOME];
    int id;
}Cliente;

Pizza pizzas[MAX_PIZZAS];
Cliente clientes[MAX_CLIENTES];

int numPizzas = 0;
int numClientes = 0;

void cadastrarPizza() {
    if (numPizzas < MAX_PIZZAS) {
        printf("Digite o nome da pizza: ");
        scanf("%s", pizzas[numPizzas].nome);
        printf("Digite o preco da pizza: ");
        scanf("%f", &pizzas[numPizzas].preco);
        pizzas[numPizzas].disponivel = 1;
        numPizzas++;
        printf("Pizza cadastrada com sucesso!\n");
    } else {
        printf("Limite de pizzas atingido!\n");
    }
}

void cadastrarCliente() {
    if (numClientes < MAX_CLIENTES) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[numClientes].nome);
        clientes[numClientes].id = numClientes + 1;
        numClientes++;
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite de clientes atingido!\n");
    }
}

void listarPizzas() {
    printf("Pizzas cadastradas:\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
}

void listarClientes() {
    printf("Clientes cadastrados:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%d. %s\n", clientes[i].id, clientes[i].nome);
    }
}

void venderPizza() {
    int idCliente, idPizza;
    float total = 0;
    printf("Digite o id do cliente: ");
    scanf("%d", &idCliente);
    if (idCliente > 0 && idCliente <= numClientes) {
        printf("Pizzas disponiveis:\n");
        for (int i = 0; i < numPizzas; i++) {
            if (pizzas[i].disponivel == 1) {
                printf("%d. %s - R$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
            }
        }
        printf("Digite o numero da pizza que deseja comprar (0 para finalizar): ");
        scanf("%d", &idPizza);
        while (idPizza != 0) {
            if (idPizza > 0 && idPizza <= numPizzas && pizzas[idPizza - 1].disponivel == 1) {
                total += pizzas[idPizza - 1].preco;
                printf("Pizza %s adicionada ao carrinho!\n", pizzas[idPizza - 1].nome);
            } else {
                printf("Pizza indisponivel ou invalida!\n");
            }
            printf("Digite o numero da pizza que deseja comprar (0 para finalizar): ");
            scanf("%d", &idPizza);
        }
        printf("Compra finalizada!\n");
        printf("Cliente: ");
        for (int i = 0; i < MAX_NOME; i++) {
            if (clientes[idCliente - 1].nome[i] != '\0') {
                printf("%c", clientes[idCliente - 1].nome[i]);
            }
        }
        printf("Total: R$ %.2f\n", total);
    } else {
        printf("Cliente nao encontrado!\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\n------ Pizzaria Nostra Pizza ------\n");
        printf("1 - Cadastrar Pizza\n");
        printf("2 - Cadastrar Cliente\n");
        printf("3 - Listar Pizzas\n");
        printf("4 - Listar Clientes\n");
        printf("5 - Vender Pizza\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarPizza();
                break;
                
            case 2:
                cadastrarCliente();
                break;
                
            case 3:
                listarPizzas();
                break;
                
            case 4:
                listarClientes();
                break;
                
            case 5:
                venderPizza();
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(opcao != 0);
    return 0;
}