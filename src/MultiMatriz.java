public class MultiMatriz{
    
    static{
        System.loadLibrary("multi");
    }
    
    public native int[][] multiMatrizNativo(int[][] m1, int[][]m2);

    public int[][] MultiMatrizJava(int[][] m1, int[][] m2){

        System.out.println("===== Multiplicação em java =====");
        exibiMatriz(m1);
        exibiMatriz(m2);
        
        int qtd_linhas_m1 = m1.length;
        int qtd_colunas_m1 = m1[0].length;

        int qtd_linhas_m2 = m2.length;
        int qtd_colunas_m2 = m2[0].length;

        int[][] matrizResult = new int[qtd_linhas_m1][qtd_colunas_m2];

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

    public static void exibiMatriz(int[][] matriz){              
        System.out.println("Dimensões da Matriz: "+matriz.length+"X"+matriz[0].length);
        System.out.println("========================");
        
        for(int i = 0; i < matriz.length; i++){
            for(int j = 0; j < matriz[0].length; j++){
                System.out.print(matriz[i][j]+" ");
            }
            System.out.println();            
        }
        System.out.println("========================");
    }
    
    public static void main(String args[]){
        MultiMatriz multi = new MultiMatriz();

        int[][] m1 = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
        int[][] m2 = {{5, 10, 15, 3}, {20, 25, 30, 2}, {35, 40, 45, 1}};

        //int[][] resultJavaM1M2 = multi.MultiMatrizJava(m1, m2);
        int[][] resultNativoM1M2 = multi.multiMatrizNativo(m1, m2);
        
        //exibiMatriz(resultJavaM1M2);
        System.out.println("========================");
        System.out.println("Resultado do Produto de M1 e M2:");
        exibiMatriz(resultNativoM1M2);

    }
}



