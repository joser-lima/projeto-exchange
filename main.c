#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_USUARIOS 10  // Limite de usuários que o sistema pode gerenciar

typedef struct {
    char nome[100];
    char cpf[12];     // CPF com 11 dígitos + '\0'
    char senha[7]; // Senha de até 6 dígitos + '\0'
    float reais;
    float btc;
    float eth;
    float xrp;
} Usuario;

// Protótipos das funções
void saldo();
void cadastro(Usuario *user);
void login(Usuario *user);
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

    Usuario user;

    int opcao;

    
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
            cadastro(&user);
        } else if (opcao == 2) {
            login(&user);
        } else if (opcao == 3) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    

    return 0;
}

// Implementação da função para cadastrar um usuário
void cadastro(Usuario *user) {
    char lixo;

    printf("Digite seu nome: ");
    scanf("%s", user->nome);

    scanf("%s", &lixo);

    printf("Digite seu CPF: ");
    scanf("%s", user->cpf);

    printf("Digite sua senha: ");
    scanf("%s", user->senha);

    login(user);
}

// Implementação da função para verificar o login
void login(Usuario *user) {
    char cpfuser[12];
    char senhauser[7];

    printf("Digite seu CPF: ");
    scanf("%s", cpfuser);

    printf("Digite sua senha: ");
    scanf("%s", senhauser);

    // Comparação utilizando strcmp para comparar strings
    if (
        strcmp(cpfuser, user->cpf) == 0 &&
        strcmp(senhauser, user->senha) == 0) {
        printf("Bem-vindo, %s!\n", user->nome);
        menuopcoes();
    } else {
        printf("Nome de usuário, CPF ou senha incorretos.\n");
    }
}

void menuopcoes(){

    Usuario user;

    printf("%f", user.reais);

    int respmenu;
    printf("O que deseja fazer? \n");
    printf("1 - Consulta de saldo \n");
    printf("2 - Deposito \n");
    printf("3 - Saque \n");
    printf("4 - Consultar extrato \n");
    printf("5 - Compra de Cripto \n");
    printf("6 - Venda de Cripto \n");
    printf("7 - Atualizar Cotaçãò \n");
    printf("8 - Sair \n");

    scanf("%d", &respmenu);

    if(respmenu == 1){
        saldo();
    }
    else if(respmenu == 2){
        deposito();
    }
    else if(respmenu == 3){
        saque();
    }
    else if(respmenu == 4){
        extrato();
    }
    else if(respmenu == 5){
        compracripto();
    }
    else if(respmenu == 6){
        vendacripto();
    }
    else if(respmenu == 7){
        cotacao();
    }
    else if(respmenu == 8){
        printf("Saindo...\n");
    }

    
}

void saldo(){
    printf("Consulta de saldo");
}

void deposito(){
    Usuario user;

    float valor;

    printf("Digite o valor que deseja depositar: \n");
    scanf("%f", &valor);

    user.reais = user.reais + valor;
    printf("Seu novo saldo agora é de: %2.f", user.reais);

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