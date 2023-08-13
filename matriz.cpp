
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 4

/* Dada una matriz cuadrada de enteros y su orden n, devuelve su
traza */
void imprimir( int a[n][n]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
}

/* Procedimiento que, dada una matriz cuadrada de enteros y su orden n, la inicializa en una matriz aleatoria 
i.e. aquella que verifica que todas sus entradas son nÚmeros elegidos aleatoriamente. 
Dichas entradas deben ser enteros en I = [0, 100) ∩ N.*/

void matrizAleatoria(int matriz[n][n]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matriz[i][j] = rand() % /*100*/10;
}

/* Procedimiento que, dada una matriz cuadrada de enteros y su orden n, la
inicializa en la matriz nula.
*/
void matrizNula( int matriz[n][n]){
 
 for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matriz[i][j] = 0;
}

/* Procedimiento que, dada una matriz cuadrada de enteros y su orden n, la inicializa en la matriz identidad.*/

void matrizidentidad( int matriz[n][n]){
 
 for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(i==j){
         matriz[i][j] = 1;
      }
      else{
        matriz[i][j] = 0;
        }
  }

/* funciÓn que, dada una matriz cuadrada de enteros y su orden n, devuelve su
traza.
*/

/*SOLUCION MEJOR y + EFICIENTE*/

int trazaMatriz(const int matriz[n][n]){
  int traza=0;
  for(int i=0; i<n; i++){
    traza += matriz[i][i];
    }
  return traza;
  }

/*SOLUCION FACIL DE PENSAR*/

int trazaMatriz2(const int matriz[n][n]){
  int traza=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ //DIFERENCIA
      if(i==j){            //DIFERENCIA
         traza += matriz[i][j]; //DIFERENCIA
      }
    }
    }
  return traza;
  }

/* Escriba una funciÓn que, dada una matriz cuadrada de enteros y su orden n, devuelve la traza de la diagonal secundaria.
*/

int trazaSecMatriz(const int matriz[n][n]){
  int traza=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ 
      if(i+j==n-1){            
         traza += matriz[i][j];
        }
      }
    }
  return traza;
  }
  
/* Procedimiento que, dadas dos matrices cuadrada de enteros a y b de igual tamaño
y el orden n de estas, devuelve su suma.*/

void sumarMatrices(const int a[n][n], const int b[n][n], int res[n][n]){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      res[i][j]=a[i][j]+b[i][j];
      
}

/*La transpuesta de una matriz A es otra matriz tal que cambia la fila i−´esima por la columna i−´esima.
Este es un procedimiento que, dada una matriz cuadrada de enteros y su tamaño, la transpone. 
Para la codificación de este subprograma no se use arreglos auxiliares.*/

void transponer(int a[n][n]){
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      int aux=a[i][j];
      a[i][j]=a[j][i];
      a[j][i]=aux;
    }
  }
}

/* Funcion que, dadas dos matrices cuadradas de enteros a y b de igual orden n, devuelve true si y solamente si A = B.*/

bool sonIguales(const int a[n][n], const int b[n][n]){
  int i=0; // int j=0;
  bool iguales=true;
  while(i<n && iguales){
    int j=0;
    while (j<n && a[i][j]==b[i][j]){
      j++;
      if(j<n){
        iguales =false;
      }else {
        i++;
       // j=0;
      }
    }
  }return iguales;
}

int main() {
  srand(time(NULL));
  int a[n][n]; 
  int b[n][n]; 
  int res[n][n]; 
  matrizAleatoria(a);
 imprimir(a);
   printf("\n");
  /*transponer(a);
  imprimir(a);
   printf("\n");*/
  
 //   matrizAleatoria(b);
 //imprimir(b);
  // printf("\n");
  
  
 /* printf("%d", trazaMatriz(a));
 printf("\n"); */
  /*printf("%d", trazaSecMatriz(a));
 printf("\n");*/
//  matrizNula(res);
  //imprimir(a);
 // printf("\n");

   matrizidentidad(b);
  imprimir(b);
   printf("\n");
// sumarMatrices(a,b,res);
  //imprimir(res);
 if (sonIguales(a,b)){
   printf("%d", 1);
 }else { printf("%d", 0);}
  return 0;
}
