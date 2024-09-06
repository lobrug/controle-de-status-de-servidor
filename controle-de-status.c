//Este é um código de teste sem função comercial
//Esta é uma versão melhorada de um outro código meu todo transformado para funções

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Funcao A
void receba(char cidade[5][20], int servidores[5][3]){
    for (int i = 0; i < 5; i++){
        printf("Cidade %d: ", i+1);
        fgets(cidade[i], 20, stdin);

        do{
        printf("Quantos servidores estao ativos nesta cidade?: ");
        scanf("%d", &servidores[i][0]);
        }while(servidores[i][0] < 0);

        do{
        printf("E inativos?: ");
        scanf("%d", &servidores[i][1]);
        }while(servidores[i][1] < 0);

        setbuf(stdin, NULL);

        servidores[i][2] = servidores[i][0] + servidores[i][1];
    }
    
}

int total(int servidores[5][3]){
    for(int i = 0; i < 5; i++){
        servidores[i][2] = servidores[i][0] + servidores[i][1];
    }
}

char tabela(char cidade[5][20], int servidores[5][3]){
    printf("Cidades              |     Servidores\n");
    printf("---------------------|------------------------------------------------------------\n");

    for(int i = 0; i < 5; i++){
        printf("%-20s | ", cidade[i]);

            for(int j = 0; j < 3; j++){
                printf("%-20d | ", servidores[i][j]);
            }

        printf("\n");
      }

}

char pesquisar(char cidade[5][20], char pesquisa[20], int servidores[5][3], int *verifica){
    *verifica = 0;
    printf("Pesquisa: ");
    fgets(pesquisa, 20, stdin);

    for(int i = 0; i < 5; i++){
        if(strcmp(cidade[i], pesquisa)==0){
            printf("%s  |  %d  |  %d  |  %d  |\n", cidade[i], servidores[i][0], servidores[i][1], servidores[i][2]);
            *verifica = 1;
            break;
        }
    }

    if(*verifica == 0){
        printf("Servidores nao encontrado\n");
    }
}

void porcentagemErro(char cidade[5][20], int servidores[5][3], float percentual[5], float *verifica, char maiorErro[20]){
    *verifica = 0.0;

    for(int i = 0; i < 5; i++){
        percentual[i] = (servidores[i][1] * 100) / servidores[i][2];
        if(percentual[i] > *verifica){
            *verifica = percentual[i];
            strcpy(maiorErro, cidade[i]);
        }
    }

    printf("A cidade com maior taxa de erro é a %s com %.2f por cento\n", maiorErro, *verifica);

}

void porcentagemAi(int servidores[5][3], float porcentoAtivo, float porcentoInativo, int AuxA, int AuxI, int Total){
    AuxA = 0;
    AuxI = 0;
    Total = 0;
    porcentoAtivo = 0.0;
    porcentoInativo = 0.0;

    for(int i = 0; i < 5; i++){
        AuxA = AuxA + servidores[i][0];
        AuxI = AuxI + servidores[i][1];
    }

    Total = AuxA + AuxI;

    porcentoAtivo = (AuxA * 100) / Total;
    porcentoInativo = (AuxI * 100) / Total;

    printf("%.2f de servidores Estao ATIVOS e %.2f estao INATIVOS\n", porcentoAtivo, porcentoInativo);

}

void defeat(int servidores[5][3], char cidade[5][20]){
    for(int i = 0; i < 5; i++){
        if(servidores[i][1] > servidores[i][0]){
            strcat(cidade[i], " Defeated");
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%s\n", cidade[i]);
    }
}



int main(){
    char cidade[5][20];
    char pesquisa[20];
    char maiorErro[20] =  "";

    float verifica = 0;
    float percentual[5] = {0.0};
    float ativo = 0.0;
    float inativo = 0.0;

    int servidores[5][3];
    int auxa = 0;
    int auxi = 0;
    int totalo = 0;

    receba(cidade, servidores);

    printf("\n");

    total(servidores);

    printf("\n");

    tabela(cidade, servidores);

    printf("\n");

    pesquisar(cidade, pesquisa, servidores, &verifica);

    printf("\n");

    porcentagemErro(cidade, servidores, percentual, &verifica, maiorErro);

    printf("\n");

    porcentagemAi(servidores, ativo, inativo, auxa, auxi, totalo);

    printf("\n");

    defeat(servidores, cidade);

    return 0;


}