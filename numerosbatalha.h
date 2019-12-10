#ifndef numerosbatalha_h   // guardas de cabeçalho, impedem inclusões cíclicas
#define numerosbatalha_h

#include<stdio.h>
#include<conio.h>

int multiplica(int forca, int defesa) //multiplica recebe N1,N2 e retorna um int
{
  int resultado;
  resultado = forca * defesa;
  return(resultado); //retornando o valor para main
}



#endif
