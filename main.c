#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[250];
    char cpf[13];
    char senha[7];
} pessoas;

void cadastro() {
    pessoas pessoa[5];
    char nomeuser[250];
    char cpfuser[13];
    char senhauser[7];

    printf("Digite seu nome: \n");
    fgets(nomeuser, 250, stdin);
    printf("Digite seu cpf: \n");
    fgets(cpfuser, 13, stdin);
    printf("Digite sua senha: \n");
    fgets(senhauser, 7, stdin);

    strcpy(pessoa[0].nome, nomeuser);
    strcpy(pessoa[0].cpf, cpfuser);
    strcpy(pessoa[0].senha, senhauser);


    printf("Nome: %s \n", pessoa[0].nome);
    printf("CPF: %s \n", pessoa[0].cpf);
    printf("Senha: %s \n", pessoa[0].senha);

}


int main(){
    setlocale(LC_ALL, "portuguese");
    int resplogin;
    printf("O que deseja fazer? 1 - Login | 2 - Cadastro \n");
    scanf("%d", &resplogin);

    if(resplogin == 1){
        printf("Login \n");
    }
    else if(resplogin == 2){
        cadastro();
        
    }
}