#include "MultiMatriz.h"
#include <stdio.h>
#include <stdlib.h>

JNIEXPORT jobjectArray JNICALL Java_MultiMatriz_multiMatrizNativo(JNIEnv *env, jobject jobj, jobjectArray jobjArrayM1, jobjectArray jobjArrayM2){
    
    jsize qtd_linhas_m1 = (*env)->GetArrayLength(env, jobjArrayM1);
    jsize qtd_linhas_m2 = (*env)->GetArrayLength(env, jobjArrayM2);
    
    jintArray array_m1;
    jsize qtd_colunas_m1;
    jint *data_m1;

    jintArray array_m2;
    jsize qtd_colunas_m2;
    jint *data_m2;

    jint** m1 = (jint**)calloc(qtd_linhas_m1, sizeof(jint*));
    jint** m2 = (jint**)calloc(qtd_linhas_m1, sizeof(jint*));

    for(int i = 0; i < qtd_linhas_m1; i++){
        array_m1 = (*env)->GetObjectArrayElement(env, jobjArrayM1, i);
        qtd_colunas_m1 = (*env)->GetArrayLength(env, array_m1);
        m1[i] = (*env)->GetIntArrayElements(env, array_m1, 0);

        //(*env)->ReleaseIntArrayElements(env, array_m1, jobjArrayM1, 0);
    }
    for(int i = 0; i < qtd_linhas_m2; i++){
        array_m2 = (*env)->GetObjectArrayElement(env, jobjArrayM2, i);
        qtd_colunas_m2 = (*env)->GetArrayLength(env, array_m2);
        m2[i] = (*env)->GetIntArrayElements(env, array_m2, 0);

        //(*env)->ReleaseIntArrayElements(env, array_m2, jobjArrayM2, 0);
    }

    jint **matrizResult = (jint**)calloc(qtd_linhas_m1,sizeof(jint*));
    for(int i = 0; i < qtd_linhas_m1; i++){
        matrizResult[i] = (jint*)calloc(qtd_colunas_m2,sizeof(jint));
    }
    jint aux = 0;
    printf("===== Multiplicação em C =====\n");
    printf("========= M1 ============\n");
    for(int i = 0; i < qtd_linhas_m1; i++){
        for(int j = 0; j < qtd_colunas_m1; j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    printf("========= M2 ============\n");
    for(int i = 0; i < qtd_linhas_m2; i++){
        for(int j = 0; j < qtd_colunas_m2; j++){
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < qtd_linhas_m1; i++){
        for(int j = 0; j < qtd_colunas_m2; j++){
            for(int x = 0; x < qtd_colunas_m1; x ++){                
                printf("m1: %d m2: %d\n",m1[i][x], m2[x][j]);
                aux += m1[i][x] * m2[x][j];
            }
            printf("aux: %d\n", aux);
            matrizResult[i][j] = aux;
            aux = 0;
            printf("matrizResult: %d\n",matrizResult[i][j]);
        }
    }
    
    printf("========= Matriz produto ============\n");
    for(int i = 0; i < qtd_linhas_m1; i++){
        for(int j = 0; j < qtd_colunas_m2; j++){
            printf("%d ",matrizResult[i][j]);
        }
        printf("\n");
    }

    /*for(int i = 0; i < qtd_linhas_m1; i++){
        free(m1[i]);
    }
    free(m1);    
    for(int i = 0; i < qtd_linhas_m2; i++){
        free(m2[i]);
    }
    free(m2); */
       
    return matrizResult;

}