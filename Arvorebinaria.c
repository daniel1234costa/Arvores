#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int dado;
   struct node * direito;
    struct node * esquerdo;


} node;


 node *criarno( int valor){
    node* novoN = (node*)malloc(sizeof(node));
    if (novoN == NULL){
        printf("falha na alocacao");
        return NULL;
    }
    novoN->dado = valor;
    novoN->direito = NULL;
    novoN->esquerdo = NULL;
    return novoN;
   
 }
 node* inserir(node* raiz, int valor) {
    if (raiz == NULL) {
        return criarno(valor);
    }


    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = inserir(raiz->direito, valor);
    } else {
        printf("Valor %d ja existe na arvore. Nao sera inserido novamente.\n", valor);
    }


    return raiz;
}
 node* encontrarMinimo(node* no) {
    while (no != NULL && no->esquerdo != NULL) {
        no = no->esquerdo;
    }
    return no;
}


node* removerNo(node* raiz, int valor) {


    if (raiz == NULL) {
        return NULL;
    }




    if (valor < raiz->dado) {
       
        raiz->esquerdo = removerNo(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
   
        raiz->direito = removerNo(raiz->direito, valor);
    } else {
       
        if (raiz->esquerdo == NULL && raiz->direito == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerdo == NULL) {
   
            node* temp = raiz->direito;
            free(raiz);                
            return temp;                
        } else if (raiz->direito == NULL) {


            node* temp = raiz->esquerdo;
            free(raiz);                
            return temp;                
        }


        else {
            node* sucessor = encontrarMinimo(raiz->direito);


            raiz->dado = sucessor->dado;


       
            raiz->direito = removerNo(raiz->direito, sucessor->dado);
        }
    }
    return raiz;
}
    node* buscarno(node* raiz, int valor){


        if(raiz == NULL){
            return NULL;
        }
           else if(valor == raiz->dado){
                return raiz;
            }
               else if(valor < raiz->dado){
                    return buscarno(raiz->esquerdo, valor);
                }
                    else{
                        return buscarno(raiz->direito, valor);
                    }
    }
    void ordem(node* raiz){
        if(raiz != NULL){
        ordem(raiz->esquerdo);
        printf("%d", raiz->dado);
        ordem(raiz->direito);


        }
       
    }



int main (){



 node* raiz = NULL;
   raiz = inserir(raiz,30);
    raiz = inserir(raiz,20);
     raiz = inserir(raiz,40);
      raiz = inserir(raiz,15);
       raiz = inserir(raiz,25);


ordem(raiz);







    return 0;
}
