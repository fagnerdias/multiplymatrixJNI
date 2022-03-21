package main;

public interface Matrix {

    double[][] multiply(double[][] m1, double[][] m2);

    public default double[][] generateMatrix(int n, int m){
        double data[][] = new double[n][m];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                data[i][j] = Math.random();
            }
        }
        return data;
    }

}