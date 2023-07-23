/*This is a work carried out for the technologist, 
which consisted of making a simple code for the 2048 game, the qualification of this work was approved*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#define size 4
#define objetivo 2048
#define objetivo2 2048

void imprimir(int matriz[size][size])
{
    // Limpiar la pantalla
    system("cls");
    // Imprimir la matriz
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%4d", matriz[i][j]);
        }
        printf("\n\n");
    }
}

void matrizNula(int matriz[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void casilleroAleatorio(int matriz[size][size])
{
    int valor = (rand() % 2 + 1) * 2;
    int fila, col;
    do
    {
        fila = rand() % size;
        col = rand() % size;
    } while (matriz[fila][col] != 0);
    matriz[fila][col] = valor;
}

void moverArriba(int matriz[size][size], int &score)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 1; i < size; i++)
        {
            if (matriz[i][j] != 0)
            {
                int k = i;
                while (k > 0 && matriz[k - 1][j] == 0)
                {
                    matriz[k - 1][j] = matriz[k][j];
                    matriz[k][j] = 0;
                    k--;
                }
                if (k > 0 && matriz[k - 1][j] == matriz[k][j])
                {
                    matriz[k - 1][j] *= 2;
                    matriz[k][j] = 0;
                    score += 5;
                }
            }
        }
    }
}

void moverIzquierda(int matriz[size][size], int &score)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (matriz[i][j] != 0)
            {
                int k = j;
                while (k > 0 && matriz[i][k - 1] == 0)
                {
                    matriz[i][k - 1] = matriz[i][k];
                    matriz[i][k] = 0;
                    k--;
                }
                if (k > 0 && matriz[i][k - 1] == matriz[i][k])
                {
                    matriz[i][k - 1] *= 2;
                    matriz[i][k] = 0;
                    score += 5;
                }
            }
        }
    }
}

void moverDerecha(int matriz[size][size], int &score)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 2; j >= 0; j--)
        {
            if (matriz[i][j] != 0)
            {
                int k = j;
                while (k < size - 1 && matriz[i][k + 1] == 0)
                {
                    matriz[i][k + 1] = matriz[i][k];
                    matriz[i][k] = 0;
                    k++;
                }
                if (k < size - 1 && matriz[i][k + 1] == matriz[i][k])
                {
                    matriz[i][k + 1] *= 2;
                    matriz[i][k] = 0;
                    score += 5;
                }
            }
        }
    }
}

void moverAbajo(int matriz[size][size], int &score)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = size - 2; i >= 0; i--)
        {
            if (matriz[i][j] != 0)
            {
                int k = i;
                while (k < size - 1 && matriz[k + 1][j] == 0)
                {
                    matriz[k + 1][j] = matriz[k][j];
                    matriz[k][j] = 0;
                    k++;
                }
                if (k < size - 1 && matriz[k + 1][j] == matriz[k][j])
                {
                    matriz[k + 1][j] *= 2;
                    matriz[k][j] = 0;
                    score += 5;
                }
            }
        }
    }
}

bool derrota(int matriz[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((i > 0 && matriz[i][j] == matriz[i - 1][j]) || (i < size - 1 && matriz[i][j] == matriz[i + 1][j]) || (j > 0 && matriz[i][j] == matriz[i][j - 1]) || (j < size - 1 && matriz[i][j] == matriz[i][j + 1]))
            {
                return false; // There are adjacent cells with the same value, valid moves are still possible
            }
            if (matriz[i][j] == 0)
            {
                return false; // There is an empty cell, valid moves are still possible
            }
        }
    }
    return true; // No valid moves left, it's a defeat
}

bool movimientoValido(int matriz[size][size], char movimiento)
{
    bool movimientoValido = false;

    switch (movimiento)
    {
    case 'W':
    case 'w':
        for (int j = 0; j < size; j++)
        {
            for (int i = 1; i < size; i++)
            {
                if (matriz[i][j] != 0 && (matriz[i - 1][j] == 0 || matriz[i - 1][j] == matriz[i][j]))
                {
                    return true;
                }
            }
        }
        break;

    case 'S':
    case 's':
        for (int j = 0; j < size; j++)
        {
            for (int i = size - 2; i >= 0; i--)
            {
                if (matriz[i][j] != 0 && (matriz[i + 1][j] == 0 || matriz[i + 1][j] == matriz[i][j]))
                {
                    return true;
                }
            }
        }
        break;
    case 'A':
    case 'a':
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j < size; j++)
            {
                if (matriz[i][j] != 0 && (matriz[i][j - 1] == 0 || matriz[i][j - 1] == matriz[i][j]))
                {
                    return true;
                }
            }
        }
        break;

    case 'D':
    case 'd':
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 2; j >= 0; j--)
            {
                if (matriz[i][j] != 0 && (matriz[i][j + 1] == 0 || matriz[i][j + 1] == matriz[i][j]))
                {
                    return true;
                }
            }
        }
        break;
    }
    return false;
}

bool victoria(int matriz[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matriz[i][j] == objetivo)
            {
                return true;
            }
        }
    }
    return false;
}

void menuprincipal (char op, int a[size][size], bool &jugar){
        printf("Menu:\n");
        printf("# Jugar (W)\n");
        printf("# Salir (Z)\n");
        printf("Ingresa una opcion: ");
        scanf(" %c", &op);
switch (op) {
            case 'W':
            case 'w':

                matrizNula(a);
                casilleroAleatorio(a);
                casilleroAleatorio(a);
                imprimir(a);
                printf("\n");
                printf("Utiliza las teclas WASD para mover. Alcanza el %d para ganar.\n", objetivo);
                jugar = true;
                break;




            case 'Z':
            case 'z':
                printf("Seguro que quieres salir? Y/N ? \n");
                char salir;
                scanf(" %c", &salir);
                if(salir == 'y' || salir == 'Y'){
                    printf("Saliendo \n");
                    exit(0);
                }
                break;






        }
        printf("\n");
    }

    int main()
{
        char reiniciar = 's';
        while (reiniciar == 's' || reiniciar == 'S') {

        char movimientos;
        char volver;
        bool jugando = false;
        bool abortada = false;
        char opcion;
        int score = 0;
        srand(time(NULL));
        int a[size][size];
        matrizNula(a);
        casilleroAleatorio(a);
        casilleroAleatorio(a);


        while (!jugando) {

        menuprincipal(opcion, a, jugando);


        while (jugando)
        {


        printf("Hace un movimiento. Puntaje actual: %d\n", score);
        printf("Para Dejar la Partida y Abortar apreta M\n");
        scanf(" %c", &movimientos);
        switch (movimientos)
        {
        case 'W':
        case 'w':
            if (movimientoValido(a, 'w'))
            {
                moverArriba(a, score);
                casilleroAleatorio(a);
                imprimir(a);
            }
            else
            {
                printf("\nMovimiento no valido. Intentalo de nuevo.\n");
            }
            break;

        case 'S':
        case 's':
            if (movimientoValido(a, 's'))
            {
                moverAbajo(a, score);
                casilleroAleatorio(a);
                imprimir(a);
            }
            else
            {
                printf("\nMovimiento no valido. Intentalo de nuevo.\n");
            }
            break;

        case 'A':
        case 'a':
            if (movimientoValido(a, 'a'))
            {
                moverIzquierda(a, score);
                casilleroAleatorio(a);
                imprimir(a);
            }
            else
            {
                printf("\nMovimiento no valido. Intentalo de nuevo.\n");
            }
            break;

        case 'D':
        case 'd':
            if (movimientoValido(a, 'd'))
            {
                moverDerecha(a, score);
                casilleroAleatorio(a);
                imprimir(a);
            }
            else
            {
                printf("\nMovimiento no valido. Intentalo de nuevo.\n");
            }
            break;

        case 'M':
        case 'm':
            printf("Volviendo al menu principal...\n");
            abortada = true;
            jugando = false;


           while (!jugando) {

        menuprincipal(opcion, a, jugando);

        printf("\n");
                            }
        break;
        default:
            printf("\nMovimiento no valido. Utiliza las teclas WASD para mover las piezas.\n");
            break;
        }


        if (victoria(a)) {
                printf("Victoria! Alcanzaste el %d!\n", objetivo);
                jugando = false;
                printf("Para Volver al Menu y Jugar de Nuevo apreta S \n");
                scanf(" %c", &reiniciar);
            }

        if (derrota(a)) {

                printf("Perdiste! No hay movimientos posibles. Puntaje: %d\n", score);
                jugando = false;
                printf("Para Volver al Menu y Jugar de Nuevo apreta S \n");
                scanf(" %c", &reiniciar);

                    }
                }
            }
        }
    return 0;
}
