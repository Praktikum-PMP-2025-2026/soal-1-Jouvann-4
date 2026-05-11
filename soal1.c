/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5 - Foundation Algorithm
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Joe Steven Hardy (13224065)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program Analisis Adjacency Matrix
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
char *token = NULL;
int dimensi = -1;
int tempArray[100];
int counter = 0;
int maxVertex[20];
int idxMax = -1;
int temp = -1;
int kosong = 100;
int listKosong[20];


void readInput(){
    fgets(input, 100, stdin);

    token = strtok(input, " ");

    while (token != NULL){
        if (dimensi == -1){
            dimensi = atoi(token); 
        }
        else{
            tempArray[counter] = atoi(token);
            //printf("Temp Array Indeks - %d : %d\n", counter, tempArray[counter]);
            counter++;
        }

        token = strtok(NULL, " ");
    }
}

void hitungDerajat(int matrix[dimensi][dimensi]){
    for (int i = 0; i < dimensi; i++){
        int tempCounter = 0; 
        for (int j = 0; j < dimensi; j++){
            if (matrix[i][j] == 1){
                tempCounter++;
            }
        }
        //printf("DEGREE %d %d\n", i, tempCounter);
    }
}


int main(){
    readInput();
    int matrix[dimensi-1][dimensi-1];
    counter = 0;

    for (int i = 0; i < dimensi; i++){
        int tempCounter = 0;
        for (int j = 0; j < dimensi; j++){
            matrix[i][j] = tempArray[counter];
            counter++;
            if (matrix[i][j] == 1) {tempCounter++;}

            //printf("Array Sementara %d %d = %d\n", i, j, matrix[i][j]);
        }
        maxVertex[i] = tempCounter;
        printf("DEGREE %d %d\n", i, tempCounter);
    }

    counter = 0;
    for (int i = 0; i < dimensi; i++){
        //printf("MAX VERTEX %d %d\n", i, maxVertex[i]);
        if (maxVertex [i] > temp){
           // printf("IDX MAX %d %d\n", i, idxMax);
            temp = maxVertex[i];
            idxMax = i;
        }
        if (maxVertex[i] == 0) {
            listKosong[counter] = i;
            kosong = 1;
            counter++;
        }
        
    }

    printf("MAX_VERTEX %d\n", idxMax);
    if (kosong == 100){
        printf("ISOLATED NONE");
    } 
    else{
        if (counter == 1){
            printf("ISOLATED %d", listKosong[0]);
        }
        else{
            for (int i = 0; i < counter; i++){
                if (i == 0){
                    printf("ISOLATED %d", listKosong[i]);
                }
                else if (i == counter - 1){
                    printf(" %d\n", listKosong[i]);
                }
                else{
                    printf(" %d", listKosong[i]);
                }
            }
        }
        
        
    }
    //hitungDerajat(matrix);

    return 0;
}
