#include<stdio.h>
#include"util.h"
#include<stdlib.h>
#define PATH_OUTPUT "output/cenario_5.csv"
#define PATH_MEMORY "memory/cenario_5.csv"

int main(){
    
    ATRIBUTO** atributos =  criar_instancia_de_atributos();
    ARVORE* arv = criar_arvore(atributos);
    FILE  *f = fopen("input/cenario_5.csv","r");
    FILE *f1 = fopen(PATH_OUTPUT,"w");
    FILE *f2 = fopen(PATH_MEMORY, "w");
    printf("%d", NUMERO_ATRIBUTO);
    
    int *dados = (int*)malloc(sizeof(int)*( NUMERO_ATRIBUTO+1));
    for (int i=0; i < 113931;i++){
        // printf("%d", NUMERO_ATRIBUTO);
        // int n1,n2,n3,n4,n5;
        for(int j=0; j< NUMERO_ATRIBUTO+1;j++){

            fscanf(f,"%d",&dados[j]);
            char c = fgetc(f);
            // printf("%d %d %c\n",dados[j], j, c);
            // if (j == NUMERO_ATRIBUTO) fscanf(f,"\n");
            // else fscanf(f,",");
        }
        // return 0;
        // fscanf(f,"%d,%d,%d,%d,%d\n", &n1,&n2,&n3,&n4,&n5);
        // dados[0] = n1;
        // dados[1] = n2;
        // dados[2] = n3;
        // dados[3] = n4;
        // dados[4] = n5;
        
        int predict = predicao(dados,arv,atributos);

        adiciona_na_arvore(dados, arv,atributos    );
        fprintf( f2,"%d,%d\n",i, calcula_memoria(arv,atributos));
        fprintf(f1,"%d,%d\n", predict, dados[NUMERO_ATRIBUTO]);

    }

    free(dados);
    fclose(f);
    fclose(f2);
    fclose(f1);
    // FILE  *f_ = fopen("file.csv","r");
    // FILE *f3 = fopen("acuracia_final.csv", "w");
    // for (int i=0; i < 113931;i++){
    //     int n1,n2,n3,n4,n5;
    //     fscanf(f_,"%d,%d,%d,%d,%d\n", &n1,&n2,&n3,&n4,&n5);
    //     dados[0] = n1;
    //     dados[1] = n2;
    //     dados[2] = n3;
    //     dados[3] = n4;
    //     dados[4] = n5;
    //     int predict = predicao(dados,arv,atributos);
    //     fprintf(f3,"%d,%d\n", predict, dados[4]);
        

    // }
    // fclose(f3);


}