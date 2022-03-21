package main;

public class MatrixNative implements Matrix {

    public double[][] multiply(double[][] m1, double[][] m2){
        /*try {
            Thread.sleep(1000);
        }catch (InterruptedException e){

        }*/
        return this.nativeMultiply(m1, m2);
        // throw new UnsupportedOperationException();
    }

    public native double[][] nativeMultiply(double[][] m1, double[][] m2);

}