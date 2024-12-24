#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int posi;
    int posj;
}Peca;

void TesteVitoria(char matriz[3][3], int *finjogo);
void LocalizaPeca(char matriz[3][3], int *seq, int *posi, int *posj, int *k, int *l, char OX);
void RiscosPecas(char matriz[3][3], Peca *Espaco);

int main(){
    char matriz[3][3];
    int jogada = 0, seq_o = 0, seq_x = 0;
    int k, l;
    int fimJogo=0;
    Peca X, O;
    srand(time(0));

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz[i][j] = '-';
        }
    }

    while(!fimJogo){
        if (jogada % 2 == 0){
            // Entrada do jogador
            int m, n;
            int valido = 0;
            while(!valido){
                for (m = 0; m < 3; m++){
                    for (n = 0; n < 3; n++){
                        printf(" %c ", matriz[m][n]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf("Escolha a posicao(0 a 2): linha x coluna\n");
                scanf("%d %d", &m, &n);
                if(matriz[m][n] == '-'){
                    matriz[m][n] = 'X';
                    valido = 1;
                }
            }
            jogada++;
        }
        else{
            if(jogada==1){
                if(matriz[1][1] == '-'){
                    matriz[1][1] = 'O';
                }
                else{
                    int canto = 0;
                    while(canto < 5){
                        canto = rand() % 4;
                        //printf("%d", canto);
                        if(canto == 0){
                            if(matriz[0][0] == '-'){
                                matriz[0][0] = 'O';
                                canto = 5;
                            }
                        }
                        if(canto == 1){
                            if(matriz[0][2] == '-'){
                                matriz[0][2] = 'O';
                                canto = 5;
                            }
                        }
                        if(canto == 2){
                            if(matriz[2][0] == '-'){
                                matriz[2][0] = 'O';
                                canto = 5;
                            }
                        }
                        if(canto == 3){
                            if(matriz[2][2] == '-'){
                                matriz[2][2] = 'O';
                                canto = 5;
                            }
                        }
                    }
                }
                jogada++;
            }
            if(jogada == 3){
                
                LocalizaPeca(matriz, &seq_x, &X.posi, &X.posj, &k, &l, 'X');

                // Escolhe a posicao para jogar
                //printf("%d \n", seq_x);
                if(seq_x == 2 && X.posi == 0 && X.posj == 0){
                    if(k == 0 && l == 1 )
                        matriz[0][2] = 'O';
                    if(k == 0 && l == 2)
                        matriz[0][1] = 'O';  
                    if(k == 1 && l == 0) 
                        matriz[2][0] = 'O';
                    if(k == 2 && l == 0)
                        matriz[1][0] = 'O';
                    if(k == 1 && l == 1){
                        if(matriz[2][2] == '-')
                            matriz[2][2] == 'O';
                        else{
                            int escolha = rand() % 2;
                            switch(escolha){
                            case 0:
                                matriz[1][2] = 'O';
                                break;
                            case 1:
                                matriz[2][1] = 'O';
                                break;
                            }
                        }
                    }
                    if(k == 2 && l == 2){
                        int escolha = rand() % 6;
                        switch(escolha){
                        case 0:
                            matriz[0][1] = 'O';
                            break;
                        case 1:
                            matriz[0][2] = 'O';
                            break;
                        case 2:
                            matriz[1][2] = 'O';
                            break;
                        case 3:
                            matriz[1][0] = 'O';
                            break;
                        case 4:
                            matriz[2][0] = 'O';
                            break;
                        case 5:
                            matriz[2][1] = 'O';
                            break;
                        }
                    }
                }
                if(seq_x == 2 && X.posi == 0 && X.posj == 1){
                    if(k == 0 && l == 2)
                        matriz[0][0] = 'O';
                    if(k == 1 && l == 1)
                        matriz[2][1] = 'O';
                    if(k == 2 && l == 1){
                        int escolha = rand() % 6;
                        switch(escolha){
                        case 0:
                            matriz[0][0] = 'O';
                            break;
                        case 1:
                            matriz[1][2] = 'O';
                            break;
                        case 2:
                            matriz[1][0] = 'O';
                            break;
                        case 3:
                            matriz[2][2] = 'O';
                            break;
                        case 4:
                            matriz[2][0] = 'O';
                            break;
                        case 5:
                            matriz[2][2] = 'O';
                            break;
                        }
                    }
                }
                if(seq_x == 2 && X.posi == 0 && X.posj == 2){
                    if(k==1 && l==2)
                        matriz[2][2] = 'O';
                    if(k == 2 && l == 2){
                        matriz[1][2] = 'O';
                    }
                    if(k == 1 && l == 1){
                        if(matriz[2][0] == '-'){
                            matriz[2][0] = 'O';
                        }
                        else{
                            int escolha = rand() % 2;
                            switch(escolha){
                            case 0:
                                matriz[1][0] = 'O';
                                break;
                            case 1:
                                matriz[2][1] = 'O';
                                break;
                            }
                        }
                    }
                    if(k==2 && l==0){
                        int escolha = rand() % 6;
                        switch(escolha){
                        case 0:
                            matriz[0][0] = 'O';
                            break;
                        case 1:
                            matriz[0][1] = 'O';
                            break;
                        case 2:
                            matriz[1][0] = 'O';
                            break;
                        case 3:
                            matriz[2][1] = 'O';
                            break;
                        case 4:
                            matriz[1][2] = 'O';
                            break;
                        case 5:
                            matriz[2][2] = 'O';
                            break;
                        }
                    }
                }
                if(seq_x == 2 && X.posi == 1 && X.posj == 0){
                    if(k==2 && l==0)
                        matriz[0][0] = 'O';
                    if(k==1 && l == 1)
                        matriz[1][2] = 'O';
                    if(k==1 && l == 2 ){
                        int escolha = rand() % 6;
                        switch(escolha){
                        case 0:
                            matriz[0][0] = 'O';
                            break;
                        case 1:
                            matriz[0][1] = 'O';
                            break;
                        case 2:
                            matriz[0][2] = 'O';
                            break;
                        case 3:
                            matriz[2][1] = 'O';
                            break;
                        case 4:
                            matriz[2][0] = 'O';
                            break;
                        case 5:
                            matriz[2][2] = 'O';
                            break;
                        }
                    }
                }
                if(seq_x == 2 && X.posi == 1 && X.posj == 1){
                    if(k == 1 && l == 2){
                        matriz[1][0] = 'O';
                    }
                    if(k==2 && l == 1){
                        matriz[0][1] = 'O';
                    }
                    if(k==2 && l == 0){
                        if(matriz[0][2] == '-'){
                            matriz[0][2] = 'O';
                        }
                        else{
                            int escolha = rand() % 2;
                            switch(escolha){
                            case 0:
                                matriz[0][1] = 'O';
                                break;
                            case 1:
                                matriz[1][2] = 'O';
                                break;
                            }
                        }
                    }
                    if(k == 2 && l == 2){
                        if(matriz[0][0] == '-'){
                            matriz[0][0] = 'O';
                        }
                        else{
                            int escolha = rand() % 2;
                            switch(escolha){
                            case 0:
                                matriz[0][1] = 'O';
                                break;
                            case 1:
                                matriz[1][0] = 'O';
                                break;
                            }
                        }
                    }
                }
                if(seq_x == 2 && X.posi == 1 && X.posj == 2){
                    if(k==2 && l==2){
                        matriz[0][2] = 'O';
                    }
                }
                if(seq_x == 2 && X.posi == 2 && X.posj == 1){
                    if(k==2 && l==1){
                        matriz[2][2] = 'O';
                    }
                    if(k==2 && l==2){
                        matriz[2][1] = 'O';
                    }
                }
                if(seq_x == 2 && X.posi == 2 && X.posj == 1){
                    if(k==2 && l==2){
                        matriz[2][0] = 'O';
                    }
                }
                if(seq_x == 1){
                    int escolha = rand() % 2;
                    switch(escolha){
                    case 0:
                    if(matriz[0][2] = '-')
                            matriz[0][2] = 'O';
                        else
                            matriz[2][0] = 'O';
                        break;
                    case 1:
                    if(matriz[2][0] = '-')
                            matriz[2][0] = 'O';
                        else
                            matriz[0][2] = 'O';
                        break;
                    }
                }

                jogada++;
            }
            if(jogada == 5){
                int naojogou = 0;

                LocalizaPeca(matriz, &seq_o, &O.posi, &O.posj, &k, &l,'O');
                
                if(seq_o == 2 && O.posi == 0 && O.posj == 0){
                    if(k==0 &&  l== 1){
                        if(matriz[0][2] == '-'){
                            matriz[0][2] = 'O';
                        }
                        else
                            naojogou = 1;
                        
                    }
                    if(k== 0 && l == 2){
                        if(matriz[0][1] == '-'){
                            matriz[0][1] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 1 && l == 0){
                        if(matriz[2][0] == '-'){
                            matriz[2][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 2 && l == 0){
                        if(matriz[1][0] == '-'){
                            matriz[1][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 1 && l == 1){
                        if(matriz[2][2] == '-'){
                            matriz[2][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                }
                if(seq_o == 2 && O.posi == 0 && O.posj == 1){
                    if(k == 0 && l == 2){
                        if(matriz[0][0] == '-'){
                            matriz[0][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k==1 & l == 1){
                        if(matriz[2][1] == '-'){
                            matriz[2][1] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    else
                        naojogou = 1;
                }
                if(seq_o == 2 && O.posi == 0 && O.posj == 2){
                    if(k == 1 && l == 1){
                        if(matriz[2][0] == '-'){
                            matriz[2][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k== 1 && l == 2){
                        if(matriz[2][2] == '-'){
                            matriz[2][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                }
                if(seq_o == 2 && O.posi == 1 && O.posj == 0){
                    if(k == 1 && l == 1){
                        if(matriz[1][2] == '-'){
                            matriz[1][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k==2 && l == 0){
                        if(matriz[0][0] == '-'){
                            matriz[0][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                }
                if(seq_o == 2 && O.posi == 1 && O.posj == 1){
                    if(k==1 && l == 2){
                        if(matriz[1][0] == '-'){
                            matriz[1][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 2 && l == 1){
                        if(matriz[0][1] == '-'){
                            matriz[0][1] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 2 && l == 2){
                        if(matriz[0][0] == '-'){
                            matriz[0][0] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    else
                        naojogou = 1;
                    if(k == 2 && l == 0){
                        if(matriz[0][2] == '-'){
                            matriz[0][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                }
                if(seq_o == 2 && O.posi == 1 && O.posj == 2){
                    if(k == 2 && l == 2){
                        if(matriz[0][2] == '-'){
                            matriz[0][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    else
                        naojogou = 1;
                }
                if(seq_o == 2 && O.posi == 2 && O.posj == 0){
                    if(k == 2 && l == 1){
                        if(matriz[2][2] == '-'){
                            matriz[2][2] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                    if(k == 2 && l == 2){
                        if(matriz[2][1] == '-'){
                            matriz[2][1] = 'O';
                        }
                        else
                            naojogou = 1;
                    }
                }
                if(naojogou == 1){
                    Peca Espaco;
                    RiscosPecas(matriz, &Espaco);
                    matriz[Espaco.posi][Espaco.posj] = 'O';
                }
                jogada++;
            }
            if(jogada == 7){
                Peca Espaco;
                RiscosPecas(matriz, &Espaco);
                matriz[Espaco.posi][Espaco.posj] = 'O';
                jogada++;
            }
            if(jogada == 9){
                printf("Deu Velha!! \n");
                fimJogo = 1;
            }
        }
        TesteVitoria(matriz, &fimJogo);  
    }
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


void TesteVitoria(char matriz[3][3], int *fimjogo){
    int seq_x = 0, seq_o = 0;

    // Teste de linhas
    for(int i=0; i<3; i++){
        seq_x = 0;
        seq_o = 0;
        for(int j=0; j<3; j++){
            if(matriz[i][j] == 'X'){
                seq_x++;
            } 
            else if(matriz[i][j] == 'O'){
                seq_o++;
            }
        }
        if(seq_x == 3){
            printf("Vitoria do Jogador!! \n");
            *fimjogo = 1;
            return;
        }
        if(seq_o == 3){
            printf("Vitoria do Robo!! \n");
            *fimjogo = 1;
            return;
        }
    }

    // Teste coluna
    for(int i=0; i<3; i++){
        seq_x = 0;
        seq_o = 0;
        for(int j=0; j<3; j++){
            if(matriz[j][i] == 'X'){
                seq_x++;
            } 
            else if(matriz[j][i] == 'O'){
                seq_o++;
            }
        }
        if(seq_x == 3){
            printf("Vitoria do Jogador!! \n");
            *fimjogo = 1;
            return;
        }
        if(seq_o == 3){
            printf("Vitoria do Robo!! \n");
            *fimjogo = 1;
            return;
        }
    }

    // Teste de diagonal principal
    seq_x = 0;
    seq_o = 0;
    for(int i = 0; i<3; i++){
        if(matriz[i][i] == 'X'){
            seq_x++;
        } 
        else if(matriz[i][i] == 'O'){
            seq_o++;
        }
    }
    if(seq_x == 3){
            printf("Vitoria do Jogador!! \n");
            *fimjogo = 1;
            return;
        }
        if(seq_o == 3){
            printf("Vitoria do Robo!! \n");
            *fimjogo = 1;
            return;
        }

    // Teste de diagonal secundaria
    seq_x = 0;
    seq_o = 0;
    for(int i = 0; i<3; i++){
        if(matriz[i][2-i] == 'X'){
            seq_x++;
        } else if(matriz[i][2-i] == 'O'){
            seq_o++;
        }
    }
   if(seq_x == 3){
            printf("Vitoria do Jogador!! \n");
            *fimjogo = 1;
            return;
        }
        if(seq_o == 3){
            printf("Vitoria do Robo!! \n");
            *fimjogo = 1;
            return;
        }
}


void LocalizaPeca(char matriz[3][3], int *seq, int *posi, int *posj, int *k, int *l, char OX){
    if(OX == 'X'){
        // posicao do 1a peca
        for (int i = 0; i < 3 && *seq == 0; i++){
            for (int j = 0; j < 3 && *seq == 0; j++) {
                if (matriz[i][j] == 'X'){
                    *posi = i;
                    *posj = j;
                    *seq = 1;
                }
            }
        }
        // posicao do 2a peca
        if (*posi == 0) {
            if (*posj == 0) {
                if (matriz[0][1] == 'X'){
                    *k=0; *l=1;
                    *seq = 2;
                }
                if (matriz[0][2] == 'X'){
                    *k=0; *l=2;
                    *seq = 2;
                }
                if (matriz[1][1] == 'X'){
                    *k=1; *l=1;
                    *seq = 2;
                }
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                }
                if (matriz[1][0] == 'X'){
                    *k=1; *l=0;
                    *seq = 2;
                }
                if(matriz[2][0] == 'X'){
                    *k=2; *l=0;
                    *seq = 2;
                }
            }
            if (*posj == 1){
                if (matriz[0][2] == 'X'){
                    *k=0; *l=2;
                    *seq = 2;
                }
                if (matriz[1][1] == 'X'){
                    *k=1; *l=1;
                    *seq = 2;
                }
                if(matriz[2][1] == 'X'){
                    *k=2; *l=1;
                    *seq = 2;
                } 
            }  
            if (*posj == 2){
                if (matriz[1][2] == 'X'){
                    *k=1; *l=2;
                    *seq = 2;
                }
                if(matriz[2][0] == 'X'){
                    *k=2; *l=0;
                    *seq = 2;
                }
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                } 
                if(matriz[1][1] == 'X'){
                    *k=1; *l=1;
                    *seq = 2;
                }
            }
        }
        if (*posi == 1){
            if (*posj == 0)  {
                if (matriz[2][0] == 'X'){
                    *k=2; *l=0;
                    *seq = 2;
                }
                if (matriz[1][1] == 'X'){
                    *k=1; *l=1;
                    *seq = 2;
                }
                if (matriz[1][2] == 'X'){
                    *k=1; *l=2;
                    *seq = 2;
                }
            }
            if (*posj == 1) {
                if (matriz[1][2] == 'X'){
                    *k=1; *l=2;
                    *seq = 2;
                }
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                } 
                if(matriz[2][0] == 'X'){
                    *k=2; *l=0;
                    *seq = 2;
                }
                if(matriz[2][1] == 'X'){
                    *k=2; *l=1;
                    *seq = 2;
                }
            }
            if (*posj == 2){
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
        }
        if (*posi == 2){
            if (*posj == 0){
                if(matriz[2][1] == 'X'){
                    *k=2; *l=1;
                    *seq = 2;
                }
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
            if(*posj==1){
                if(matriz[2][2] == 'X'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
        }
    }
    if(OX == 'O'){
            // posicao do 1a peca
        for (int i = 0; i < 3 && *seq == 0; i++){
            for (int j = 0; j < 3 && *seq == 0; j++) {
                if (matriz[i][j] == 'O'){
                    *posi = i;
                    *posj = j;
                    *seq = 1;
                }
            }
        }
        if (*posj == 0) {
            if (matriz[0][1] == 'O'){
                *k=0; *l=1;
                *seq = 2;
            }
            if (matriz[0][2] == 'O'){
                *k=0; *l=2;
                *seq = 2;
            }
            if (matriz[1][1] == 'O'){
                *k=1; *l=1;
                *seq = 2;
            }
            if(matriz[2][2] == 'O'){
                *k=2; *l=2;
                *seq = 2;
            }
            if (matriz[1][0] == 'O'){
                *k=1; *l=0;
                *seq = 2;
            }
            if(matriz[2][0] == 'O'){
                *k=2; *l=0;
                *seq = 2;
            }
        }
        if (*posj == 1){
            if (matriz[0][2] == 'O'){
                *k=0; *l=2;
                *seq = 2;
            }
            if (matriz[1][1] == 'O'){
                *k=1; *l=1;
                *seq = 2;
            }
            if(matriz[2][1] == 'O'){
                *k=2; *l=1;
                *seq = 2;
            } 
        }  
        if (*posj == 2){
            if (matriz[1][2] == 'O'){
                *k=1; *l=2;
                *seq = 2;
            }
            if(matriz[2][0] == 'O'){
                *k=2; *l=0;
                *seq = 2;
            }
            if(matriz[2][2] == 'O'){
                *k=2; *l=2;
                *seq = 2;
            } 
            if(matriz[1][1] == 'O'){
                *k=1; *l=1;
                *seq = 2;
            }
        }
        if (*posi == 1){
            if (*posj == 0)  {
                if (matriz[2][0] == 'O'){
                    *k=2; *l=0;
                    *seq = 2;
                }
                if (matriz[1][1] == 'O'){
                    *k=1; *l=1;
                    *seq = 2;
                }
                if (matriz[1][2] == 'O'){
                    *k=1; *l=2;
                    *seq = 2;
                }
            }
            if (*posj == 1) {
                if (matriz[1][2] == 'O'){
                    *k=1; *l=2;
                    *seq = 2;
                }
                if(matriz[2][2] == 'O'){
                    *k=2; *l=2;
                    *seq = 2;
                } 
                if(matriz[2][0] == 'O'){
                    *k=2; *l=0;
                    *seq = 2;
                }
                if(matriz[2][1] == 'O'){
                    *k=2; *l=1;
                    *seq = 2;
                }
            }
            if (*posj == 2){
                if(matriz[2][2] == 'O'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
        }
        if (*posi == 2){
            if (*posj == 0){
                if(matriz[2][1] == 'O'){
                    *k=2; *l=1;
                    *seq = 2;
                }
                if(matriz[2][2] == 'O'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
            if(*posj==1){
                if(matriz[2][2] == 'O'){
                    *k=2; *l=2;
                    *seq = 2;
                }
            }
        }
    }

    //printf("Ref = %c: posi = %d, posj = %d, k = %d, l = %d \n", OX, *posi, *posj, *k, *l);
}

void RiscosPecas(char matriz[3][3], Peca *Espaco){
    Espaco->posi = 3;
    // Risco linhas
    for(int i=0; i<3 ; i++){
        if(matriz[i][0] == 'X' && matriz[i][1] == 'X' && matriz[i][2] == '-'){
            Espaco->posi = i;
            Espaco->posj = 2;
        }
        if(matriz[i][0] == 'X' && matriz[i][1] == '-' && matriz[i][2] == 'X'){
            Espaco->posi = i;
            Espaco->posj = 1;
        }
        if(matriz[i][0] == '-' && matriz[i][1] == 'X' && matriz[i][2] == 'X'){
            Espaco->posi = i;
            Espaco->posj = 0;
        }
        if(Espaco->posi != 3){
            return;
        }
    }
    // Risco colunas
    for(int i=0; i<3 ; i++){
        if(matriz[0][i] == 'X' && matriz[1][i] == 'X' && matriz[2][i] == '-'){
            Espaco->posj = i;
            Espaco->posi = 2;
        }
        if(matriz[0][i] == 'X' && matriz[1][i] == '-' && matriz[2][i] == 'X'){
            Espaco->posj = i;
            Espaco->posi = 1;
        }
        if(matriz[0][i] == '-' && matriz[1][i] == 'X' && matriz[2][i] == 'X'){
            Espaco->posj = i;
            Espaco->posi = 0;
        }
        if(Espaco->posi != 3){
            return;
        }
    }
    // Risco diagonais
    if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == '-'){
        Espaco->posi = 2; Espaco->posj = 2;
    }
    if(matriz[0][0] == 'X' && matriz[1][1] == '-' && matriz[2][2] == 'X'){
        Espaco->posi = 1; Espaco->posj = 1;
    }
    if(matriz[0][0] == '-' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){
        Espaco->posi = 0; Espaco->posj = 0;
    }
    if(matriz[0][2] == '-' && matriz[1][1] == 'X' && matriz[2][0] == 'X'){
        Espaco->posi = 0; Espaco->posj = 2;
    }
    if(matriz[0][2] == 'X' && matriz[1][1] == '-' && matriz[2][0] == 'X'){
        Espaco->posi = 1; Espaco->posj = 1;
    }
    if(matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == '-'){
        Espaco->posi = 0; Espaco->posj = 2;
    }
    if (Espaco->posi != 3){
        return;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j] == '-'){
                Espaco->posi = i;
                Espaco->posj = j;
            }
        }
    }
    if (Espaco->posi != 3){
        return;
    }
}