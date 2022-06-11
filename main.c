// Junho, 2022
// Trabalho de AEDS [ Descobre estrutura ]
// Artur Gonzaga && Bernardo de Oliveira
// Turma 203, profa. Virgínia Mota
// #ELMAIAFOREVER


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include "listas.h"

// CONSTANTES
#define VERDADEIRO 0
#define FALSO 1
#define INSERIR 1
#define REMOVER 2
#define SUCESSO 0
#define ERRO 1
#define TAM_MAX 14 + 1

typedef uint8_t bool;

void analisarEstados(bool prior, bool fila, bool pilha) {

    int Verdade = 000;

    if (prior == VERDADEIRO) Verdade += 100;
    if (fila == VERDADEIRO) Verdade += 10;
    if (pilha == VERDADEIRO) Verdade += 1;

    switch (Verdade) {
    case 0:
        printf("impossible\n");
        break;
    case 1:
        printf("stack\n");
        break;
    case 10:
        printf("queue\n");
        break;
    case 11:
        printf("not sure\n");
        break;
    case 100:
        printf("priority queue\n");
        break;
    case 101:
        printf("not sure\n");
        break;
    case 110:
        printf("queue\n");
        break;
    case 111:
        printf("not sure\n");
        break;
    }
}


bool whatIF_Fila(lista_t* lst_main, int info) {

    lista_t* i_ponteiro = lst_main;

    while (i_ponteiro->prox != NULL) {

        i_ponteiro = i_ponteiro->prox;
    }

    if (info == i_ponteiro->info){

        return VERDADEIRO;
    }

    else { return FALSO; }
}


bool whatIF_PriorFila(lista_t* lst_main, int info) {
    
    int info_maior = lst_main->info;
    lista_t* i_ponteiro = lst_main;

    while (i_ponteiro != NULL) {

        if (i_ponteiro->info >= info_maior) {

            info_maior = i_ponteiro->info;
        }

        i_ponteiro = i_ponteiro->prox;
    }

    if (info == info_maior) {

        return VERDADEIRO;
    }

    else { return FALSO; }
}

bool whatIF_Pilha(lista_t* lst_main, int info) {

    if (info == lst_main->info) {

        return VERDADEIRO;
    }

    else { return FALSO; }
}

int main(int argc, char** argv){

    setlocale(LC_ALL,"");//Comando pros acentos aparecerem

    FILE *entrada;
    lista_t* lst_main;

    int qtdOperacoes, comparador, valorInserido, tipo;

    bool prior = FALSO;
    bool fila = FALSO;
    bool pilha = FALSO;

    entrada = fopen("./entrada.txt", "r");

    if (entrada == NULL){//Testa se o arquivo foi aberto

        fputs("ERRO: O arquivo não pode ser encontrado\n", stderr);
        return ERRO;
    }

    else if (entrada != NULL){

        while(!feof(entrada)){

            qtdOperacoes = 0;
            fscanf(entrada, "%d", &qtdOperacoes);
            
            prior = FALSO;
            fila = FALSO;
            pilha = FALSO;

            int aux_prior = FALSO;
            int aux_fila = FALSO;
            int aux_pilha = FALSO;

            lst_main = lst_cria();

            for (comparador = 0; comparador < qtdOperacoes; comparador++) {

                fscanf(entrada, "%d %d", &tipo, &valorInserido);

                switch (tipo) {

                case INSERIR:
                    lst_main = lst_insere(lst_main, valorInserido);
                    break;
                case REMOVER:

                    if (lst_vazia(lst_main) == FALSO) {

                        if (aux_prior == FALSO) {

                            if (whatIF_PriorFila(lst_main, valorInserido) == VERDADEIRO) prior = VERDADEIRO;
                            else aux_prior = VERDADEIRO;
                        }

                        if (aux_fila == FALSO) {

                            if (whatIF_Fila(lst_main, valorInserido) == VERDADEIRO) fila = VERDADEIRO;
                            else aux_fila = VERDADEIRO;
                        }

                        if (aux_pilha == FALSO) {

                            if (whatIF_Pilha(lst_main, valorInserido) == VERDADEIRO) pilha = VERDADEIRO;
                            else aux_pilha = VERDADEIRO;
                        }

                        lst_main = lst_retira_objetiva(lst_main, valorInserido);
                    }
                    break;
                   
                default:

                    fputs("ERRO: comando invalido\n", stderr);
                    return ERRO;
                }
            }
                       
            if (qtdOperacoes != 0) {

                analisarEstados(prior, fila, pilha); 
            }

            lst_libera(lst_main);
        }
        fclose(entrada);
    }

    return SUCESSO;
}