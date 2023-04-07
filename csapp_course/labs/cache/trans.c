/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes
 * s = 5, E = 1, b = 5
 * 32个set 每个set只有一个line 每个line存8个int.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]){
    if (M == 64) { // 64 * 64
       for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                for (int r = 0; r < 4; ++r) {
                    int tmp[4];
                    for (int l = 0; l < 4; ++l) {
                        tmp[l] = A[4 * i + r][4 * j + l];
                    }                   
                    for (int c = 0; c < 4; ++c) {
                        B[4 * j + c][4 * i + r] = tmp[c];
                    }
                }
            }
        } 
    }
    else if (M == 32) { // 32 * 32
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int r = 0; r < 8; ++r) {
                    int tmp[8];
                    for (int l = 0; l < 8; ++l) {
                        tmp[l] = A[8 * i + r][8 * j + l];
                    }
                    for (int c = 0; c < 8; ++c) {
                        B[8 * j + c][8 * i + r] = tmp[c];
                    }
                }
            }
        }
    }
    else { // 61 * 67
       for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 8; ++j) {
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        if (8 * i + r < N  && 8 * j + c < M)
                            B[8 * i + r][8 * j + c] = A[8 * j + c][8 * i + r]; 
                    }
                }
            }
        } 
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

