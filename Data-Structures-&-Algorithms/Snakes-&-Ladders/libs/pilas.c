//pilas.c

#include <stdlib.h>
#define ERRORP '*'

//Funciones básicas

Node* CrearNodoP(elementp e){
    Node* nodo = (Node *)malloc(sizeof(Node));
    //Datos
    nodo->e = e;
    nodo -> siguiente = NULL;
    return nodo;
}
void DestruirNodoP(Node* nodo){
    nodo->siguiente = NULL;
    free(nodo);
}

Pila* CrearPila(){
  Pila* pila = (Pila *)malloc(sizeof(Pila));
  pila -> head = NULL;
  pila->longitud = 0;
  return pila;
}
void DestruirPila(Pila* pila){
    while(pila->head!=NULL){
        Desapilar(pila);
    }
    free(pila);
}
void Desapilar(Pila* pila){
    if(pila->head!=NULL){
        Node* eliminar = pila->head;
        pila->head = pila->head->siguiente;
        DestruirNodoP(eliminar);
        pila->longitud--;
    }
}
//Funciones propias de las pilas

void Push(Pila* pila, elementp e){
    Node* nodo = CrearNodoP(e);
    nodo->siguiente = pila->head;
    pila->head = nodo;
    pila->longitud++;
}
elementp Pop(Pila* pila, Node* ref){
    if(ref==NULL){;
        return ERRORP;
    }else{
        return ref->e;
    }
}
//Funciones adicionales para pilas

elementp Cima(Pila* pila, Node* ref){
    if(ref==NULL){
        return ERRORP;
    }else{
        return ref->e;
    }
}
void Desapilar(Pila* pila){
    if(pila->head!=NULL){
        Node* eliminar = pila->head;
        pila->head = pila->head->siguiente;
        DestruirNodoP(eliminar);
        pila->longitud--;
    }
}
elementp Pop(Pila* pila, Node* ref){
    if(ref==NULL){;
        return ERRORP;
    }else{
        return ref->e;
    }
}
void ShowP(Pila* pila){

    if(pila->head == NULL){
        return;
    }else{
        Node* puntero = pila->head;
        while(puntero!=NULL){

            printf("| %d |", puntero->e);
            puntero = puntero->siguiente;
            
        }
        printf("\n");
        return;
    }

}

int Longitudp(Pila* pila){
    return pila->longitud;
}
Pila* InvertirPila(Pila* pila){
    Node* puntero = pila->head;
    Pila* pila_nueva = CrearPila();

    while(puntero != NULL){

        Push(pila_nueva, Pop(pila, puntero));
        puntero = puntero->siguiente;

    }
    return pila_nueva;
}

/* La función suma se restringe a casos en los que elementp 
es un tipo de dato numérico (int) */

void Suma(Pila* sumando1, Pila* sumando2, Pila* result){
    elementp num1, num2, acarreo=0, suma=0;

    Node* puntero1 = sumando1->head;
    Node* puntero2 = sumando2->head;

    while (puntero1 != NULL || puntero2 != NULL){
        num1 = Cima(sumando1, puntero1);
        num2 = Cima(sumando2, puntero2);
        
        suma = num1 + num2 + acarreo;
        acarreo = 0;
        if(suma>=10){
            acarreo = suma/10;
            suma %= 10;
        }
        Push(result, suma);

        if(puntero1 == NULL){
            puntero2 = puntero2->siguiente;
            continue;
        }

        if(puntero2 == NULL){
            puntero1 = puntero1->siguiente;
            continue;
        }
        puntero2 = puntero2->siguiente;
        puntero1 = puntero1->siguiente;

    }    

}

int verificar_balance(char *formula) {
    Pila* parentesis = CrearPila();
    Pila* corchetes = CrearPila();
    Pila* llaves = CrearPila();
    
    for (int i = 0; formula[i] !='\0'; i++){
  	  if(formula[i] == '('){
            Push(parentesis, '(');
        }else if(formula[i] == '['){
            Push(corchetes, '[');
        }else if(formula[i] == '{'){
            Push(llaves, '{');
        }else if(formula[i] ==')'){

            if(Longitudp(parentesis) != 0 && parentesis->head->e == '(')
                Desapilar(parentesis);
            else
                Push(parentesis, ')');
