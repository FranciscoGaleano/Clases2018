#include <stdio.h>
#include <stdlib.h>


char calcular(char);
int sumar(int, int);
int restar(int, int);
float dividir(float, float);
int multiplicar(int, int);

int main()
{
    int primerOperando;
    int segundoOperando;
    char operador;
    float resultado;

    printf("Ingrese el primer operando \n");
    scanf("%d", &primerOperando);
    printf("Ingrese el segundo operando \n");
    scanf("%d", &segundoOperando);
    printf("Ingrese el operador \n");
    fflush(stdin);
    scanf("%c", &operador);
    while(operador != 's' && operador != 'r' && operador != 'd' && operador != 'm'){
        printf("Ingrese un operador valido \n");
        fflush(stdin);
        scanf("%c", &operador);
    }

    calcular(operador);


    //return 0;
}

    char calcular(char operador){
        if(operador == 's'){
            int sumar(int, int);
        }
        if(operador == 'r'){
            int restar(int, int);
        }
        if(operador == 'd'){
            float dividir(float, float);
        }
        if(operador == 'm'){
            int multiplicar(int, int);
        }
        }

    int sumar(int primerOperando, int segundoOperando){
        int resultado = primerOperando + segundoOperando;
        scanf("El resultado de la suma es %d", resultado);
        }

    int restar(int primerOperando, int segundoOperando){
        int resultado = primerOperando - segundoOperando;
        scanf("El resultado de la resta es %d", resultado);
        }

    float dividir(float primerOperando, float segundoOperando){
        float resultado = primerOperando / segundoOperando;
        scanf("El resultado de la división es %.2f", resultado);
        }

    int multiplicar(int primerOperando, int segundoOperando){
        int resultado = primerOperando * segundoOperando;
        scanf("El resultado de la multipliación es %d", resultado);
        }




