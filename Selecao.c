#include <stdio.h>
#include <stdlib.h>
/*****************
Complexidade: Θ ( n · log n ) 
*****************/



//SELEÇÃO PELO TEMPO DE INICIO
/*int selecaoTempoInicio(int ini[], int fim[], int tam){
	int ultimaS=0;
	int selecionados=0;
	int i;
	if(tam==0) return 0;
	printf("A 0, ");
	selecionados++;
	for (i=1;i<tam;i++)
		if (ini[i]>=fim[ultimaS]){
			printf("A %d, ", i);
			selecionados++;
			ultimaS = i;
		}
	printf("\n");
	return selecionados;
}*/

//SELEÇÃO PELO TEMPO DE TERMINO
int selecaoTempoTermino(int ini[], int fim[], char ativ[], int tam){
	int selecionados=0;
	int i, ig, x, igaux;
	if(tam==0) return 0;
	int fimS=fim[0];
	//PEGANDO A ATIVIDADE QUE TERMINA PRIMEIRO
	for (i=0;i<tam;i++){
		if(fim[i]<fimS){
			fimS=fim[i];
			ig=i;
		}
	}
	int cont;
	printf("%c[%d,%d];", ativ[ig],ini[ig],fim[ig]);
	selecionados++;
	//PEGANDO AS ATIVIDADES QUE TERMINAM PRIMEIRO PÓS A PRIMEIRA
	for(i=0;i<tam;i++){
		igaux=ig;
		if(ini[i]>fim[igaux]){
			fimS=fim[i];
			for(x=0;x<tam;x++){
				if((ini[x]>fim[igaux])&&(fim[x]<=fimS)){
					fimS=fim[x];
					ig=x;
					i=0;
				}
			}
			cont++;
			printf("%c[%d,%d];", ativ[ig],ini[ig],fim[ig]);
			selecionados++;
		}
		if(cont==10){
			break;
		}
	}
	printf("\n");
	return selecionados;
}




int main(){
	//TEMPO DE INICIO
	int ini[]={4,6,13,4,2,6,7,9,1,3,9};
	//TEMPO DE TERMINO
	int fim[]={8,7,14,5,4,9,10,11,6,13,12};
	//ATIVIDADES
	char ativ[]={"ABCDEFGHIJKL"};
	//QUANTIDADE DE ATIVIDADES
	int tam=11;
	//int total=selecaoTempoInicio(ini, fim, tam);
	//printf("Total de atividades: %d\n", total);
	int total=selecaoTempoTermino(ini, fim, ativ, tam);
	printf("Total de atividades: %d\n", total);
	system("pause");
}
