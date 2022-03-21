package main;

public class MatrixNonNative implements Matrix {

    public double[][] multiply(double[][] m1, double[][] m2){
        int qtd_linhas_m1 = m1.length;
        int qtd_colunas_m1 = m1[0].length;

        int qtd_linhas_m2 = m2.length;
        int qtd_colunas_m2 = m2[0].length;

        double[][] matrizResult = new double[qtd_linhas_m1][qtd_colunas_m2];

        int aux = 0;
        
        for(int i = 0; i < qtd_linhas_m1; i++){
            for(int j = 0; j < qtd_colunas_m2; j++){
                for(int x = 0; x < qtd_linhas_m2; x++){
                    aux += m1[i][x] * m2[x][j];
                }
                matrizResult[i][j] = aux;
                aux = 0;
            }
        }

        return matrizResult;
    }

}