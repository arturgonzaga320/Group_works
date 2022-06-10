//Trabalho AEDS

//Vou escrever diversos comentários pra você poder saber o que cada coisa faz, depois pode apagar se quiser

#include <stdio.h>
#include <locale.h>//Biblioteca para incluir acentos
#define SUCESSO 0
#define ERRO 1
#define ASPAS '"'

int main(int argc, char** argv){

    setlocale(LC_ALL,"");//Comando pros acentos aparecerem

    FILE *entrada;//Declaração do arquivo de entrada
    int qtdOperacoes, comparador, Teste, numero;//Vetores teste para colocar tudo certinho

    //Interação com o usuário
    printf("\nCrie um arquivo chamado %centrada.txt%c e o coloque no MESMO DIRETÓRIO desse programa", ASPAS, ASPAS);
    printf("\nNo arquivo entrada.txt, digite os comandos que você queira que o programa realize");
    printf("\nInstruções:\n\nQuantidade de comandos que deseja fazer\n1 x- Coloca o elemento x");
    printf("\n2 x- Retira o elemento x\n\nAperte enter quando já houver colocado: ");
    getchar();
    
    entrada = fopen("./entrada.txt", "r");//Abre o arquivo

    if (entrada == NULL){//Testa se o arquivo foi aberto

        fputs("ERRO: O arquivo não pode ser encontrado\n", stderr);
        return ERRO;//Retorna erro se o arquivo não for encontrado

    }
    else if (entrada != NULL){

        printf("Arquivo aberto com sucesso\n");//Mostra ao usuário que o arquivo foi aberto

        while(!feof(entrada)){//Enquanto o fim do arquivo não chegar...

            fscanf(entrada, "%d", &qtdOperacoes);//Lê a quantidade de operações
            printf("\nQuantidade: %d\n", qtdOperacoes);//e as salva
            
            for (comparador = 0; comparador < qtdOperacoes; comparador++){

                fscanf(entrada, "%d %d", &numero, &Teste);//Lê os números e os salva num vetor (depois a gente coloca na lista)
                printf("\nTipo: %d Valor: %d\n", numero, Teste);//Imprime pra ver se tá indo

            }   

        }

        fclose(entrada);
    }

    

    return SUCESSO;
}