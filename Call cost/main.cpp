#include <stdio.h>
#include <math.h>

int main() {
  int HoraComienzo;
  int HoraFin;
    printf("Ingrese Hora de Comienzo y Fin en formato 0000 separadas por enter\n");
    scanf("%d" "%d", &HoraComienzo, &HoraFin);


  int HHINI=HoraComienzo/10000;
  int MMINI=(HoraComienzo%10000)/100;
  int SSINI=(HoraComienzo%10000)%100;

  int HHFIN=HoraFin/10000;
  int MMFIN=(HoraFin%10000)/100;
  int SSFIN=(HoraFin%10000)%100;


  int TiempodeLlamada;
    TiempodeLlamada=(HHFIN*3600+MMFIN*60+SSFIN)-(HHINI*3600+MMINI*60+SSINI);

   int aux=TiempodeLlamada/60;
   int segundos=TiempodeLlamada%60;
   int minutos=aux%60;
   int horas=aux/60;



  int PrecioHora=horas*900;
  int PrecioMin=minutos*15;
  float aux2=(float)segundos/100;
  float PrecioSegundos=ceil(aux2)*15;

   int PrecioTotal=PrecioHora+PrecioMin+PrecioSegundos;

  printf("Precio Total de la llamada  \n %d", PrecioTotal);





  return 0;
}
