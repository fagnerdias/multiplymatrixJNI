#include "main_MatrixNative.h"

JNIEXPORT jobjectArray JNICALL Java_main_MatrixNative_nativeMultiply (JNIEnv * env, jobject jobj, jobjectArray jobjArrayM1, jobjectArray jobjArrayM2){
  //Declaração de Variáveis
    jsize qtd_linhas_m1 = (*env)->GetArrayLength(env, jobjArrayM1);
    jsize qtd_linhas_m2 = (*env)->GetArrayLength(env, jobjArrayM2);
  //M1
    jintArray array_m1;
    jsize qtd_colunas_m1;
    jint *data_m1;

    //M2
    jintArray array_m2;
    jsize qtd_colunas_m2;
    jint *data_m2;

    jint** m1 = (jint**)calloc(qtd_linhas_m1, sizeof(jint*));
    jint** m2 = (jint**)calloc(qtd_linhas_m1, sizeof(jint*));

    //Formação da Matriz M1
    for(int i = 0; i < qtd_linhas_m1; i++){
        array_m1 = (*env)->GetObjectArrayElement(env, jobjArrayM1, i);
        qtd_colunas_m1 = (*env)->GetArrayLength(env, array_m1);
        m1[i] = (*env)->GetIntArrayElements(env, array_m1, 0);

        //(*env)->ReleaseIntArrayElements(env, array_m1, jobjArrayM1, 0);
    }

    //Formação da Matriz M2
    for(int i = 0; i < qtd_linhas_m2; i++){
        array_m2 = (*env)->GetObjectArrayElement(env, jobjArrayM2, i);
        qtd_colunas_m2 = (*env)->GetArrayLength(env, array_m2);
        m2[i] = (*env)->GetIntArrayElements(env, array_m2, 0);

        //(*env)->ReleaseIntArrayElements(env, array_m2, jobjArrayM2, 0);
    }

    //Alocação de Memória para Matriz Resultado
    jint **matrizResult = (jint**)calloc(qtd_linhas_m1,sizeof(jint*));
    for(int i = 0; i < qtd_linhas_m1; i++){
        matrizResult[i] = (jint*)calloc(qtd_colunas_m2,sizeof(jint));
    }

    //Produto de Matriz M1 e M2
    jint aux = 0;
    for(int i = 0; i < qtd_linhas_m1; i++){
        for(int j = 0; j < qtd_colunas_m2; j++){
            for(int x = 0; x < qtd_colunas_m1; x ++){                
                //printf("m1: %d m2: %d\n",m1[i][x], m2[x][j]);
                aux += m1[i][x] * m2[x][j];
            }
            //printf("aux: %d\n", aux);
            matrizResult[i][j] = aux;
            aux = 0;
            //printf("matrizResult: %d\n",matrizResult[i][j]);
        }
    }

    //Retornando Matriz -- Conversão Inteiro para Objeto_Array
    jclass AUX1 = (*env)->FindClass(env, "[I");
    jintArray AUX2 = (*env)->NewIntArray(env, qtd_linhas_m1);
    jobjectArray result = (*env)->NewObjectArray(env, qtd_linhas_m1, AUX1, AUX2);

    for(int i = 0 ; i < qtd_linhas_m1 ; i++){
        jintArray AUX3 = (*env)->NewIntArray(env, qtd_linhas_m1);
        (*env)->SetIntArrayRegion(env, AUX3, 0, qtd_linhas_m1, matrizResult[i]);
        (*env)->SetObjectArrayElement(env, result, i, AUX3);
        (*env)->DeleteLocalRef(env, AUX3);
    }

    return result;
}