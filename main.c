#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_USUARIOS 10  // Limite de usuários que o sistema pode gerenciar

typedef struct {
    char nome[100];
    char cpf[12];     // CPF com 11 dígitos + '\0'
    char senha[7];    // Senha de até 6 dígitos + '\0'
} Usuario;

// Protótipos das funções
void cadastrar();
void login();
void menuopcoes();
void deposito();
void saque();
void extrato();
void compracripto();
void vendacripto();
void cotacao();

// Função principal
int main() {
    setlocale(LC_ALL, "");
    int opcao;

    while (1) {
        printf(" /$$$$$$$  /$$$$$$ /$$$$$$$$ /$$$$$$$  /$$   /$$ /$$     /$$ \n");
        printf("| $$__  $$|_  $$_/|__  $$__/| $$__  $$| $$  | $$|  $$   /$$/\n");
        printf("| $$  \\ $$  | $$     | $$   | $$  \\ $$| $$  | $$ \\  $$ /$$/ \n");
        printf("| $$$$$$$   | $$     | $$   | $$$$$$$ | $$  | $$  \\  $$$$/  \n");
        printf("| $$__  $$  | $$     | $$   | $$__  $$| $$  | $$   \\  $$/   \n");
        printf("| $$  \\ $$  | $$     | $$   | $$  \\ $$| $$  | $$    | $$    \n");
        printf("| $$$$$$$/ /$$$$$$   | $$   | $$$$$$$/|  $$$$$$/    | $$    \n");
        printf("|_______/ |______/   |__/   |_______/  \\______/     |__/    \n");
        printf("\n");
        printf("\n1. Cadastrar\n2. Login\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar();
        } else if (opcao == 2) {
            login();
        } else if (opcao == 3) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

// Implementação da função para cadastrar um usuário
void cadastrar() {
    FILE *file = fopen("usuarios.txt", "a");  // Abre o arquivo em modo de adição (append)
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    Usuario novoUsuario;

    printf("Digite o nome: ");
    scanf(" %[^\n]", novoUsuario.nome);  // Lê a string até encontrar uma nova linha

    printf("Digite o CPF (somente números): ");
    scanf("%s", novoUsuario.cpf);
    if (strlen(novoUsuario.cpf) != 11) {
        printf("CPF deve ter 11 dígitos. Tente novamente.\n");
        fclose(file);
        return;
    }

    printf("Digite a senha (6 dígitos numéricos): ");
    scanf("%s", novoUsuario.senha);
    if (strlen(novoUsuario.senha) != 6) {
        printf("A senha deve ter exatamente 6 dígitos. Tente novamente.\n");
        fclose(file);
        return;
    }

    // Escreve os dados do novo usuário no arquivo
    fprintf(file, "%s %s %s\n", novoUsuario.nome, novoUsuario.cpf, novoUsuario.senha);

    printf("Usuário cadastrado com sucesso!\n");

    fclose(file);  // Fecha o arquivo
}

// Implementação da função para verificar o login
void login() {
    FILE *file = fopen("usuarios.txt", "r");  // Abre o arquivo em modo de leitura
    if (file == NULL) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    char cpf[12], senha[7], input_cpf[12], input_senha[7];
    char nome[100];
    int encontrado = 0;

    printf("Digite o CPF: ");
    scanf("%s", input_cpf);

    printf("Digite a senha: ");
    scanf("%s", input_senha);

    // Procura o CPF e a senha no arquivo
    fscanf(file, "%s %s %s", nome, cpf, senha);
        if (strcmp(cpf, input_cpf) == 0 && strcmp(senha, input_senha) == 0) {
            printf("Login bem-sucedido! Bem-vindo(a), %s.\n", nome);
            menuopcoes();
        }
    }

void menuopcoes(){

    int respmenu;
    printf("O que deseja fazer? \n");
    printf("1 - Deposito \n");
    printf("2 - Saque \n");
    printf("3 - Consultar extrato \n");
    printf("4 - Compra de Cripto \n");
    printf("5 - Venda de Cripto \n");
    printf("6 - Atualizar Cotaçãò \n");
    printf("7 - Sair \n");

    scanf("%d", &respmenu);

    if(respmenu == 1){
        deposito();
    }
    else if(respmenu == 2){
        saque();
    }
    else if(respmenu == 3){
        extrato();
    }
    else if(respmenu == 4){
        compracripto();
    }
    else if(respmenu == 5){
        vendacripto();
    }
    else if(respmenu == 6){
        cotacao();
    }
    else if(respmenu == 7){
        printf("Saindo...\n");
    }

    
}

void deposito(){
    FILE *file = fopen("usuarios.txt", "a");
    printf("Deposito \n");
    menuopcoes();
}

void saque(){
    printf("Saque \n");
    menuopcoes();
}

void extrato(){
    printf("Consulta de extrato \n");
    menuopcoes();
}

void compracripto(){
    printf("Compra de cripto \n");
    menuopcoes();
}

void vendacripto(){
    printf("Venda de Cripto \n");
    menuopcoes();
}

void cotacao(){
    printf("Atualizacao da cotacao \n");
    menuopcoes();
}