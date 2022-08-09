#include "conversao.h"

int yearToMonth(int month, int year){
  int mesTotal = 0;
  mesTotal = month +(year*12);
  return mesTotal;
}