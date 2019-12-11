#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "numerosbatalha.h"

int main(){
	
	system("color 3F");
	
	int opcao = 0;
	
	do{
		
	printf("	SEJA BEM VINDO A..... \n\n");
	printf("/////////////////////\n");
	printf("//CAVERNA  	   //\n");
	printf("//	DA	   //\n");
	printf("//        MANTICORA//\n");
	printf("/////////////////////\n");

	printf("Escolha uma opcao:\n");
	printf("1 -  Campanha\n");
	printf("2 -  Ranking de pontos\n");
	printf("3 -  Creditos\n");
	printf("4 -  Sair\n");
	
	scanf("%d", &opcao);
	char comple[10];
	char nome[10];
	char classe[15];
	int posicao;
	int score;
	FILE * ranking;
	ranking = fopen("ranking.txt","a");

  if(opcao == 1){

		printf("Digite o seu nome!:");
		
		scanf("%s", nome);
		
		printf("Qual a sua classe ?\n");
		printf("Sugestoes:: Guerreiro , Cavaleiro , Mago , Clerigo , Sacerdote \n");
		scanf("%s",classe);
		
		int forca,defesa,inteligencia,espirito;
		srand(time(NULL));
		int hp = 20 + (rand() % 10);
		int item;
		do{
		
		printf("e o seus atributos? some no maximo 45 pontos\n atributos sao incrementados por mais 1 a cada vitoria\n");
		printf("1º Forca : dano fisico");
		scanf("%d",&forca);
		printf("2º defesa : dano recebido");
		scanf("%d",&defesa);
		printf("3º inteligencia : dano magico");
		scanf("%d",&inteligencia);
		printf("4º espirito : cura");
		scanf("%d",&espirito);
		
		if(forca+defesa+inteligencia+espirito > 45){
			printf("atributos alem do limite! , tente novamente\n");
		}
		}while(forca+defesa+inteligencia+espirito > 45);
		
		printf("Sua aventura esta prestes para comecar!.....\n\n\n");
		printf("Voce veio ao vilarejo de Yuniep para acabar com Poderosa Manticora que assola o lugar com seus lacaios\n");
		printf("A manticora e uma Criatura com corpo de leao , asas de morcego e cauda de Escorpiao. além de um potencial magico enorme\n");
		printf("Antes de sair a procura, voce deve escolher uma arma e armadura:\nArma: 1 - Espada(forca + 3 , defesa +1)\n 2 - Cajado(inteligencia +3 , espirito + 2)\n 3 - Machado(forca + 4) \n");
		int arma;
		
		do{
		scanf("%d",&arma);
		if(arma == 1){
			forca += 3;
			defesa += 1;
		}if(arma == 2){
			inteligencia +=3;
			espirito +=2;
		}if(arma == 3){
			forca += 4;
		}
		}while(arma != 1 && arma != 2 && arma != 3 );
		
		printf("Roupa:\n1 - Armadura de corrente(defesa + 4)\n 2 - Capa magica (defesa/inteligencia +2 , espirito + 3)\n 3 - Armadura de Couro(forca + 1 , defesa +3)\n");
		int armadura;
		
		do{
		scanf("%d",&armadura);
		if(armadura == 1){
			defesa += 4;
		}if(armadura == 2){
			defesa += 2;
			inteligencia +=2;
			espirito +=3;
		}if(armadura == 3){
			forca += 1;
			defesa += 3;
		}
		}while(armadura != 1 && armadura != 2 && armadura != 3 );
		
		printf("status finais: HP: %d , Forca: %d ,Defesa: %d , inteligencia: %d , espirito: %d. \n\n", hp,forca,defesa,inteligencia,espirito);
		
		printf("Voce sai do vilarejo e se depara com 3 caminhos até a Caverna:\n1 - Uma Praia deserta(Normal)\n2 - uma floresta densa(Dificil)\n3 - uma rota pelas montanhas(Facil)");
		int rota;
		int pontuacao;
		int mhp , mforca , mdefesa ,minteligencia , mespirito;
		int opcaobatalha;
		int dano;
		int cura;
		int mdano;
		srand(time(NULL));
		int mmove = 0 + (rand() % 2);
		do{
		scanf("%d",&rota);
			if(rota == 1){
				printf("Voce decide ir pela praia, um caminho nao tao mal para a caverna...\n");
				printf("Sua jornada e tranquila ate que das areias surge um Carangueijo gigante! \n");
				mhp = 15 , mforca = 9, mdefesa = 10, minteligencia  = 1, mespirito = 10;
				do{
					
					printf("						BATALHA EM PROGRESSO					\n\n");
					printf("voce se depara com um crustaceo enorme que bloqueou seu caminho, provavelmente controlado pela manticora\nHP do Carangueijo : %d\n\n",mhp);
					printf("Seu HP: %d\n\nVoce pode... :\n 1 - Atacar \n2 - usar magia\n3 - se curar\n",hp);
					scanf("%d", &opcaobatalha);
					
					if(opcaobatalha == 1){
						printf("voce ataca com sua arma!\n\n");
						dano = ataque(forca , mdefesa);
						printf("dano causado: %d\n", dano);
						mhp = mhp-dano;
					}
					if(opcaobatalha == 2){
						printf("voce conjura uma magia de ataque!\n\n");
						if(inteligencia < 5){
							printf(".....mas falha, não tem inteligencia suficiente!\n\n");
						}if(inteligencia > 5){
						dano = ataquemagico(inteligencia, espirito , mdefesa , mespirito);
						printf("dano causado: %d\n", dano);
						mhp = mhp-dano;
						}
					}
					if(opcaobatalha == 3){
						printf("voce tenta se curar!\n\n");
						cura = efeitocura(espirito,inteligencia);
						printf("Cura feita: %d\n", cura);
						hp = hp+cura;
					
					}
					
					printf("O seu inimigo o ataca!\n");
					mdano = danoinimigofisico(mforca,defesa);
					printf("e causa %d de dano!", mdano);
					hp = hp-mdano;
					
					
					if(mhp <= 0){
						printf("Voce derrota o inimigo, vitoria!\n\n");
						score = score + 300;
						forca++;
						defesa++;
						inteligencia++;
						espirito++;
					}
					
					if(hp <= 0){
						printf("Voce perece nas maos do seu inimigo....\n\n\n FIM DE JOGO \n\n\n");
						return 0;
					}
				}while(hp > 0 && mhp > 0);		
								
			}if(rota == 2){
				printf("Voce decide ir pela floresta, qual desafio se espreita na mata?\n");
				printf("Nada notavel...até que dos cipos aparece um morcego gigante!\n");
				mhp = 25 , mforca = 15, mdefesa = 15, minteligencia  = 15, mespirito = 12;
				do{
					
					printf("						BATALHA EM PROGRESSO					\n\n");
					printf("voce se depara com um morcego enorme no seu caminho, provavelmente controlado pela manticora\nHP do Morcego : %d\n\n",mhp);
					printf("Seu HP: %d\n\nVoce pode... :\n 1 - Atacar \n2 - usar magia\n3 - se curar\n",hp);
					scanf("%d", &opcaobatalha);
					
					if(opcaobatalha == 1){
						printf("voce ataca com sua arma!\n\n");
						dano = ataque(forca , mdefesa);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
					}
					if(opcaobatalha == 2){
						printf("voce conjura uma magia de ataque!\n\n");
						if(inteligencia < 5){
							printf(".....mas falha, não tem inteligencia suficiente!\n\n");
						}if(inteligencia > 5){
						dano = ataquemagico(inteligencia, espirito , mdefesa , mespirito);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
						}
					}
					if(opcaobatalha == 3){
						printf("voce tenta se curar!\n\n");
						cura = efeitocura(espirito,inteligencia);
						printf("Cura feita: %d\n\n", cura);
						hp = hp+cura;
					
					}
					if(mmove == 1){
					printf("O seu inimigo o ataca!\n\n");
					mdano = danoinimigofisico(mforca,defesa);
					printf("E causa %d de dano!\n\n",mdano);
					hp = hp-mdano;
					
					}if(mmove == 2){
					printf("O seu inimigo o ataca com magia!\n\n");
					mdano = danoinimigomagico(minteligencia, mespirito , defesa , espirito);
					printf("E causa %d de dano!\n\n",mdano);
					hp = hp-mdano;
					}
					if(mhp <= 0){
						printf("Voce derrota o inimigo, vitoria!\n\n");
						score = score + 500;
						forca++;
						defesa++;
						inteligencia++;
						espirito++;
					}
					
					if(hp <= 0){
						printf("Voce perece nas maos do seu inimigo....\n\n\n FIM DE JOGO \n\n\n");
						return 0;
					}
					
				}while(hp > 0 && mhp > 0);	
				
			}if(rota == 3){
				printf("Voce decide ir pela montanha, nao deve ser dificil...\n");
				printf("Um passei pelos bosques rochosos é atrapalhado por...um Lobo!\n");
				mhp = 15 , mforca = 10, mdefesa = 8, minteligencia  = 4, mespirito = 4;
				do{
					
					printf("						BATALHA EM PROGRESSO					\n\n");
					printf("Um lobo selvagem o ataca, provavelmente apenas defendendo o seu territorio\nHP do Lobo : %d\n\n",mhp);
					printf("Seu HP: %d\n\nVoce pode... :\n 1 - Atacar \n2 - usar magia\n3 - se curar\n",hp);
					scanf("%d", &opcaobatalha);
					
					if(opcaobatalha == 1){
						printf("voce ataca com sua arma!\n\n");
						dano = ataque(forca , mdefesa);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
					}
					if(opcaobatalha == 2){
						printf("voce conjura uma magia de ataque!\n\n");
						if(inteligencia < 5){
							printf(".....mas falha, não tem inteligencia suficiente!\n\n");
						}if(inteligencia > 5){
						dano = ataquemagico(inteligencia, espirito , mdefesa , mespirito);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
						}
					}
					if(opcaobatalha == 3){
						printf("voce tenta se curar!\n\n");
						cura = efeitocura(espirito,inteligencia);
						printf("Cura feita: %d\n\n", cura);
						hp = hp+cura;
					}
				
					printf("O seu inimigo o ataca!\n\n");
					mdano = danoinimigofisico(mforca,defesa);
					printf("E causa %d de dano!\n\n",mdano);
					hp = hp-mdano;
					
					if(mhp <= 0){
						printf("Voce derrota o inimigo, vitoria!\n\n");
						score = score + 100;
						forca++;
						defesa++;
						inteligencia++;
						espirito++;
					}
					
					if(hp <= 0){
						printf("Voce perece nas maos do seu inimigo....\n\n\n FIM DE JOGO \n\n\n");
						return 0;
					}
					
				}while(hp > 0 && mhp > 0);	
				
				}
		}while(rota != 1 && rota != 2 && rota != 3);
		
		printf("Apos um breve batalha, voce emerge proximo a caverna do seu alvo\n"); 
		printf("A caverna pode ser acessada diretamente, ou por um breve detour ao redor para chegar ao centro rapidamente\n\n");
		printf("1 - Entrar na caverna a frente! \n 2 - tomar cuidado e procurar por outra entrada\n");
		int acesso;	
		do{	
		scanf("%d", &acesso);
		if(acesso == 1){
			printf("voce adentra o covil bravamente, com sua arma e conviccao em maos\n");
				printf("para a sua surpresa (ou nao), algo alem da manticora se encontra na caverna, um Grifo!!\n");
				mhp = 40 , mforca = 22, mdefesa = 19, minteligencia  = 22, mespirito = 21;
				do{
					
					printf("						BATALHA EM PROGRESSO					\n\n");
					printf("O inimigo a sua frente e nada mais que um grifo, criatura tao forte como uma manticora\nHP do Grifo : %d\n\n",mhp);
					printf("Seu HP: %d\n\nVoce pode... :\n 1 - Atacar \n2 - usar magia\n3 - se curar\n",hp);
					scanf("%d", &opcaobatalha);
					
					if(opcaobatalha == 1){
						printf("voce ataca com sua arma!\n\n");
						dano = ataque(forca , mdefesa);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
					}
					if(opcaobatalha == 2){
						printf("voce conjura uma magia de ataque!\n\n");
						if(inteligencia < 5){
							printf(".....mas falha, não tem inteligencia suficiente!\n\n");
						}if(inteligencia > 5){
						dano = ataquemagico(inteligencia, espirito , mdefesa , mespirito);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
						}
					}
					if(opcaobatalha == 3){
						printf("voce tenta se curar!\n\n");
						cura = efeitocura(espirito,inteligencia);
						printf("Cura feita: %d\n\n", cura);
						hp = hp+cura;
					
					}
					
					printf("O seu inimigo o ataca com magia!\n\n");
					mdano = danoinimigomagico(minteligencia, mespirito , defesa , espirito);
					printf("E causa %d de dano!\n\n",mdano);
					hp = hp-mdano;
					
					
					if(mhp < 0){
						printf("Voce derrota o inimigo, vitoria!\n\n");
						score = score + 1000;
						forca++;
						defesa++;
						inteligencia++;
						espirito++;
						forca++;
						defesa++;
						inteligencia++;
						espirito++;
					}
					
					if(hp <= 0){
						printf("Voce perece nas maos do seu inimigo....\n\n\n FIM DE JOGO \n\n\n");
						fprintf(ranking,"%s - %s - %d\n",nome,classe,score);
						return 0;
					}
					
				}while(hp > 0 && mhp > 0);	
				
		}
		if(acesso == 2){
			printf("voce decide tomar uma rota segura e circula o perimetro...até achar um passage secreta!\n");
		}
				printf("os seus esforcos o levam até a criatura temida, A manticora!\n");
				printf("Ela se levanta do seu pedestal e toma voo, circulando e observando a sua proxima presa(voce)!\n");
				mhp = 62 , mforca = 22, mdefesa = 26, minteligencia  = 29, mespirito = 25;
				do{
					
					printf("						BATALHA EM PROGRESSO					\n\n");
					printf("A criatura hibrida e um ser formidavel, mas voce pode vence-la!\n HP da manticora: %d\n\n",mhp);
					printf("Seu HP: %d\n\nVoce pode... :\n 1 - Atacar \n2 - usar magia\n3 - se curar\n",hp);
					scanf("%d", &opcaobatalha);
					
					if(opcaobatalha == 1){
						printf("voce ataca com sua arma!\n\n");
						dano = ataque(forca , mdefesa);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
					}
					if(opcaobatalha == 2){
						printf("voce conjura uma magia de ataque!\n\n");
						if(inteligencia < 5){
							printf(".....mas falha, não tem inteligencia suficiente!\n\n");
						}if(inteligencia > 5){
						dano = ataquemagico(inteligencia, espirito , mdefesa , mespirito);
						printf("dano causado: %d\n\n", dano);
						mhp = mhp-dano;
						}
					}
					if(opcaobatalha == 3){
						printf("voce tenta se curar!\n\n");
						cura = efeitocura(espirito,inteligencia);
						printf("Cura feita: %d\n\n", cura);
						hp = hp+cura;
					
					}
					
					printf("O seu inimigo o ataca com magia!\n\n");
					mdano = danoinimigomagico(minteligencia, mespirito , defesa , espirito);
					printf("E causa %d de dano!\n\n",mdano);
					hp = hp-mdano;
					
					
					if(mhp < 0){
						printf("Voce derrota a manticora, finalmente!!\n\n");
						score = score + 2000;
						fprintf(ranking,"%s - %s - %d\n",nome,classe,score);
					}
					
					if(hp <= 0){
						printf("Voce perde para o vilao, apenas mais uma vitima....\n\n\n FIM DE JOGO \n\n\n");
						fprintf(ranking,"%s - %s - %d\n",nome,classe,score);
						return 0;
					}
					
				}while(hp > 0 && mhp > 0);
				
	
		}while(acesso != 1 && acesso != 2);
		
		printf("voce retorna ao vilarejo com a cabeca da manticora, provando que a derrotou, nao ha maior recompensa do que os habitantes clamando o seu nome(talvez o dinheiro)");
}
	
}while(opcao != 4);

  return 0; //retornando o valor para main

}
