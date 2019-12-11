#ifndef numerosbatalha_h  
#define numerosbatalha_h

#include<stdio.h>
#include<conio.h>

int ataque(int forca, int mdefesa)
{
  int dano;
  dano = (forca/2) - (mdefesa/2);
  if(dano <= 0){
  	dano = 1;
  }if(dano >= 20){
  	dano = 20;
  }
  return(dano); 
}

int ataquemagico(int inteligencia,int espirito ,int mdefesa ,int mespirito)
{
  int dano;
  dano = (inteligencia + (espirito/4)) - (mdefesa + (mespirito/4));
  if (dano <= 0)
  {
  	dano = 1;
  }if(dano >= 20)
  {
  	dano = 20;
  }
  return(dano);
  
  
}

int efeitocura(int espirito, int inteligencia)
{
	int cura;
	cura = ((espirito/3) + (inteligencia/4));
	if(cura <= 0)
	{
		cura = 1;
	}
	return(cura);	
}

int danoinimigofisico(int mforca, int defesa)
{
	int mdano;
	mdano = mforca - (defesa/2);
	if(mdano <= 0)
	{
		mdano = 1;
		
	}if(mdano >= 20){
  	mdano = 20;
  	}
	return(mdano);	
}

int danoinimigomagico(int minteligencia , int mespirito , int defesa , int espirito)
{
	int mdano;
	mdano = ((minteligencia) + (mespirito/4)) - (defesa + (espirito/4)); 
	if (mdano <= 0){
  	mdano = 1;
 	}
	if(mdano >= 20){
  	mdano = 20;
  	}
  return(mdano);
	
}

#endif
