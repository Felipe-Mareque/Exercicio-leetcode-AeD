/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {

if (matSize == 0){
    *returnSize = 0;
    return NULL;
}

    int quantidadeLinha = matSize;
    int quantidadeColuna = matColSize[0];
    int todosElementos = quantidadeLinha * quantidadeColuna;
    *returnSize = todosElementos;
    int* resultado = malloc(sizeof(int)*todosElementos);


    int linha = 0;
    int coluna = 0;
  int direcao = 1; // o primeiro numero sobe, se descer fica = a -1 a direcao;


    //numero de diagonais em uma matriz é igual a linha+coluna;

    for( int x = 0; x<todosElementos; x++){
        resultado[x] = mat[linha][coluna];

    if (direcao == 1){
        if (coluna == quantidadeColuna - 1){ 
             linha++; 
             direcao = -1;
        } else if (linha == 0) { // vai pra direita, e o proximo desce
                coluna++;
                direcao = -1;
        } else {
                linha--;
                coluna++;
            }
    } else { // quando entrar aqui desce
         if (linha == quantidadeLinha - 1) {
                coluna++;
                direcao = 1;
            } else if (coluna == 0) {
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