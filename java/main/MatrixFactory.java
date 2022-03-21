package main;

public class MatrixFactory{

    public static Matrix create(boolean isNative){
        if (isNative){
            return new MatrixNative();
        }else{
            return new MatrixNonNative();
        }
    }

}