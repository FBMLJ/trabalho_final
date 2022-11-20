# Explicação sobre o codigo

Dentro em cada pasta existe o programa correspondente ao algoritmo implementado referente ao nome da pasta.

Para executa cada programa primeiro entre na paste desejada e execute o seguintes comandos

```
 gcc main.cpp util.cpp -lm  -o main
 ./main
```

Os arquivos de entrada ficam na pasta de input, dependendo do escolhido é preciso fazer algumas alterações no programa para o seu funcionamento.

Primeiro seria no main.cpp e alterar as pastas para a desejada

O segundo seria modificar a constante NUMERO_ATRIBUTO no arquivo util.h para o valor de atributos de entrada do programa

Por fim, seria realizar uma modificaçõa no util.cpp na função criar_instancia_de_atributos
Nessa instância há uma variável chamada denominada "vetor", e cada instancia dessa lista apresenta um atributo onde é preciso informar os valores únicos que eles podem assumir. Exemplo:

```
vetor[0]->numero_de_valor_distinto = 24;
    int* vetor1 =(int*) malloc(sizeof(int)*24);
    for (int i =0;i < 24;i++) vetor1[i] = i;
    vetor[0]->vetor = vetor1;
```

Esse trecho de código irá criar o primeiro atributo, onde ele possui 24 valores distintos que serão informados pelo loop descrito acima.