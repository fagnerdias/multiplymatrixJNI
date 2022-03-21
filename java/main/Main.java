package main;

import java.time.Duration;
import java.time.Instant;

public class Main {

    static{
        System.loadLibrary("multi");
    }

    public static void execute(Matrix matrix, int n1, int m1, int n2, int m2){
        Instant start = Instant.now();
        double result[][] = matrix.multiply(matrix.generateMatrix(n1,m1), matrix.generateMatrix(n2,m2));
        Instant end = Instant.now();
        Duration timeElapsed = Duration.between(start, end); 
        exibiMatriz(result);
        System.out.println("Duração: "+timeElapsed.toMillis()+" ms");
    }

    public static void exibiMatriz(double[][] matriz){              
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
        int n1,m1,n2,m2=2;

        if (args.length < 3){
            System.out.println("Você deve passar quatro parâmetros: Ex: java main.Main 2 3 3 2");
            System.exit(-1);
        }

        n1 = Integer.valueOf(args[0]);
        m1 = Integer.valueOf(args[1]);
        n2 = Integer.valueOf(args[2]);
        m2 = Integer.valueOf(args[3]);

        System.out.println("Multiplicando matrizes não nativas " + n1 + "x" + m1 + " por " + n2 + "x" + m2);
        Main.execute(MatrixFactory.create(false), n1, m1, n2, m2);
        System.out.println("Multiplicando matrizes nativas " + n1 + "x" + m1 + " por " + n2 + "x" + m2);
        Main.execute(MatrixFactory.create(true), n1, m1, n2, m2);
    }

}