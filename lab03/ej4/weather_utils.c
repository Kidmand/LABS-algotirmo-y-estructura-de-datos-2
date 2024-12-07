#include <stdbool.h>
//#include "weather.h"
#include "array_helpers.h"
#include "weather_utils.h"

int minima_historica(WeatherTable a) {
   int min;
   min = a[0][0][0]._min_temp;
   
   for (int i=0; i<YEARS; i++) {
    for (int j=0; j<MONTHS; j++) {
     for (int k=0; k<DAYS; k++) {
       if (a[i][j][k]._min_temp < min) {
        min = a[i][j][k]._min_temp;
       }
     }
    }
   }
   
   return min;
}

void mayor_temp_ano(WeatherTable a, int output[YEARS]) {
  int max;
  
  for (int i=0; i<YEARS; i++) {
  max = a[i][0][0]._max_temp;
    for (int j=0; j<MONTHS; j++) {
     for (int k=0; k<DAYS; k++) {
       if (a[i][j][k]._max_temp > max) {
        max = a[i][j][k]._max_temp;
       }
     }
    }
    
    output[i] = max;
   }
}

void maxima_prec_mes_ano(WeatherTable a, int output[YEARS]) {
   int max_mes_prec; // toma el valor de la suma del mes que mayor precipitaciones tuvo
   int suma_prec;   // suma todas las precipitaciones
   int mes; // toma el mes del ano con las mayores precipitaciones
   
  for (int i=0; i<YEARS; i++) {
  max_mes_prec = 0;
    for (int j=0; j<MONTHS; j++) {
     suma_prec = 0; 
     for (int k=0; k<DAYS; k++) {
       suma_prec += a[i][j][k]._rainfall; 
      }
     
     if (max_mes_prec<suma_prec) {
       max_mes_prec = suma_prec;
       mes = (j+1);
      }
    }
    
    output[i] = mes; // me reserva el mes del año con las mayores prec
    
   }
}


void imprimir(int output[YEARS]){
 for (int i=0; i<YEARS; i++) {
  printf ("%d ",output[i]);
 }
 
 printf ("\n");
}
