#include <stdio.h>
#include <stdlib.h>

/*
====================
findDiagonalOrder
Note: The returned array must be malloced, assume caller calls free().
====================
*/
int * findDiagonalOrder ( int ** mat, int matSize, int * matColSize, int * returnSize ) {
	if ( matSize == 0 ) {
		*returnSize = 0;
		return NULL;
	}

	int				quantidadeLinha = matSize;
	int				quantidadeColuna = matColSize[0];
	int				todosElementos = quantidadeLinha * quantidadeColuna;
	int *			resultado = ( int * ) malloc ( sizeof ( int ) * todosElementos );

	*returnSize = todosElementos;

	int				linha = 0;
	int				coluna = 0;
	int				direcao = 1; // o primeiro numero sobe se for =1 sobe, se descer fica = a -1 a direcao;

	
	for ( int x = 0; x < todosElementos; x++ ) {
		resultado[x] = mat[linha][coluna];

		if ( direcao == 1 ) {
			if ( coluna == quantidadeColuna - 1 ) {
				linha++;
				direcao = -1;
			} else if ( linha == 0 ) { // vai pra direita, e o proximo desce
				coluna++;
				direcao = -1;
			} else {
				linha--;
				coluna++;
			}
		} else { // quando entrar aqui desce
			if ( linha == quantidadeLinha - 1 ) {
				coluna++;
				direcao = 1;
			} else if ( coluna == 0 ) {
				linha++;
				direcao = 1;
			} else {
				linha++;
				coluna--;
			}
		}
	}

	return resultado;
}

/*
====================
main
====================
*/
int main ( void ) {
	int				matSize = 2;
	int				matColSize[2] = { 2, 2 };
	int				returnSize;

	int **			mat = ( int ** ) malloc ( matSize * sizeof ( int * ) );
	for ( int i = 0; i < matSize; i++ ) {
		mat[i] = ( int * ) malloc ( matColSize[i] * sizeof ( int ) );
	}

	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;

	int *			resultado = findDiagonalOrder ( mat, matSize, matColSize, &returnSize );


	for ( int i = 0; i < matSize; i++ ) {
		free ( mat[i] );
	}
	free ( mat );
	free ( resultado );

	return 0;
}
