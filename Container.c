#include <stdio.h>
#include <stdlib.h>
/*****************
Complexidade: Como cada chamada leva um tempo fixo de O(n), 
e temos que fazer W chamadas, o tempo total de execu��o ser� de O(n . W).
*****************/


int container(int W, int wt[], int b[], int n){
	// tabela que ser� preenchida
	int V[n + 1][W + 1];
	int z, i;
	// inicializando a primeira linha e primeira coluna com 0
	for(z = 0; z <= W; z++){
		V[0][z] = 0;
	}
	// inicializando a primeira linha e primeira coluna com 0
	for(i = 1; i <= n; i++){
		V[i][0] = 0;
	}

	for(i = 1; i <= n; i++)
	{
		for(z = 1; z <= W; z++)
		{	
			// elemento pode fazer parte da solu��o
			if(wt[i - 1] <= z){
				// max...
				if((b[i - 1] + V[i - 1][z - wt[i - 1]]) > V[i - 1][z]){
					V[i][z] = b[i - 1] + V[i - 1][z - wt[i - 1]];
				}else{
					V[i][z] = V[i - 1][z];
				}
			}
			else{
				V[i][z] = V[i - 1][z]; // wi > w
			}
		}
	}

	// retorna o valor m�ximo colocado no container
	return V[n][W];
}

int main(){
	// capacidade m�xima do container: W
	int W = 15;

	// n�mero de elementos
	int n = 11;

	// vetor com os valores (benef�cio) de cada elemento
	int b[] = {6, 6, 10, 10, 10, 10, 12, 12, 12, 12, 11, 11};

	// vetor com os pesos de cada elemento
	int wt[] = {3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5};

	// obt�m o m�ximo valor que pode ser colocado no container
	int max_valor = container(W, wt, b, n);

	printf("Valor maximo: %d\n", max_valor);

	return 0;
}
