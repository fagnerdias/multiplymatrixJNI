# Tutorial 
Tutorial de Compilação e Execução do Projeto utilizando Linux

## Compilação

- Para compilar o arquivo C, dentro da pasta em que se encontra o arquivo, execute no terminal: 
    gcc -o libmulti.so -shared -I/usr/lib/jvm/java-1.11.0-openjdk-amd64/include -I/usr/lib/jvm/java-1.11.0-openjdk-amd64/include/linux MultiMatriz.c

OBS: 'java-1.11.0-openjdk-amd64' é a versão do jdk instalada. Substituir caso seja diferente. 
Para verificar sua versão, execute: ls /usr/lib/jvm/

- Para compilar o arquivo Java, dentro da pasta em que se encontra o arquivo, execute no terminal: 
    javac MultiMatriz.java


## Execução 

- Para executar o arquivo Java, dentro da pasta em que se encontra o arquivo, execute no terminal: 
    java MultiMatriz 

- Caso surja um erro informando que a lib não está na mesma máquina, especifique o caminho. Para isso, execute no terminal:
    java -Djava.library.path=../c MultiMatriz

