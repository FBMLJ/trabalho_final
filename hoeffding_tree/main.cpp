#include<stdio.h>
#include"util.h"
#include<stdlib.h>
#define PATH_OUTPUT "output/cenario_6.csv"
#define PATH_MEMORY "memory/cenario_6.csv"



void _save_model(ATRIBUTO** atributos, ARVORE * arv, FILE *f){
    fwrite(arv,sizeof(ARVORE),1,f);
    if (arv->id_atributo == -1)
    for (int i = 0; i < NUMERO_ATRIBUTO; i++){
        
        fwrite(arv->contador[i],sizeof(CONTADOR), 1, f );
        fwrite(arv->contador[i]->vetor, sizeof(int), arv->contador[i]->tamanho,f);

    }
    
    for(int i = 0; i < arv->num_de_filhos; i++){
        _save_model(atributos,arv->filhos[i],f);
    }

}

void save_model(ATRIBUTO** atributos, ARVORE * arv){  
    FILE *f = fopen("model.bin", "wb");
    _save_model(atributos,arv,f);
    fclose(f);
}

int main(){
    
    ATRIBUTO** atributos =  criar_instancia_de_atributos();
    ARVORE* arv = criar_arvore(atributos);
    FILE  *f = fopen("input/cenario_6.csv","r");
    FILE *f1 = fopen(PATH_OUTPUT,"w");
    FILE *f2 = fopen(PATH_MEMORY, "w");
    printf("%d", NUMERO_ATRIBUTO);
    
    int *dados = (int*)malloc(sizeof(int)*( NUMERO_ATRIBUTO+1));
    for (int i=0; i < 113931;i++){

        for(int j=0; j< NUMERO_ATRIBUTO+1;j++){

            fscanf(f,"%d",&dados[j]);
            char c = fgetc(f);

        }
        
        
        int predict = predicao(dados,arv,atributos);

        adiciona_na_arvore(dados, arv,atributos    );
        fprintf( f2,"%d,%d\n",i, calcula_memoria(arv,atributos));
        fprintf(f1,"%d,%d\n", predict, dados[NUMERO_ATRIBUTO]);

    }

    free(dados);
    fclose(f);
    fclose(f2);
    fclose(f1);
    
    save_model(atributos, arv);



}