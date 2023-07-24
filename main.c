//Mark Jimbo Sarmiento, MSCS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void SIMDdotProduct(size_t ARRAY_SIZE, float* A, float* B,float* sdot);
<<<<<<< HEAD
extern void x86dotProduct(size_t ARRAY_SIZE, float* A, float* B, float* sdot);
=======
>>>>>>> f35bcde2a6039e6a935b8c2f556fd38623ff0f03

const int ARRAY_SIZE = 1<<20;

void dotProduct(const float* A, const float* B, float* sdot)
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sdot[i] = A[i] * B[i];
    }

    // add up the elements of the sdot array
    float sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += sdot[i];
    }

    //printf("Dot product result: %f\n", sum);
    //return 0;
}

void verifyDotProduct(const float* sdot, const float* expected)
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (fabs(sdot[i] - expected[i]) > 1e-5) {
            printf("Error found at index %d\n", i);
            return;
        }
    }
    printf("No error.\n");
}

int main()
{
    float* A = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* B = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* sdot = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* expected = (float*)malloc(ARRAY_SIZE * sizeof(float));

    // --------------------- C++ version ----------------------------------

    
    //flush out cache
    dotProduct(A, B, sdot);
    
    // fill in the host memory with data
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = i;
        B[i] = i;
        expected[i] = A[i] * B[i]; // compute the expected result on the CPU
    }

    // Measure execution time
    clock_t start = clock();

    dotProduct(A, B, sdot);

    // verify the correctness of the dot product
    verifyDotProduct(sdot, expected);

    // finish up on the CPU side
    float sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += sdot[i];
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    printf("Dot product result: %f\n", sum);
    printf("C function took %f microseconds for array size %d \n", time_taken, ARRAY_SIZE);

    // --------------------- x86-64 SIMD YMM register ----------------------------------

        // initialize  back sdot[i] to 0
    for (int i = 0; i<ARRAY_SIZE; i++)
        sdot[i] = 0.0f;

    //flush out cache
    SIMDdotProduct(ARRAY_SIZE, A, B, sdot);
    
    // fill in the host memory with data
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = i;
        B[i] = i;
        expected[i] = A[i] * B[i]; // compute the expected result on the CPU
    }

    // Measure execution time
    start = clock();

    SIMDdotProduct(ARRAY_SIZE, A, B, sdot);

    // verify the correctness of the dot product
    verifyDotProduct(sdot, expected);

    // finish up on the CPU side
    sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += sdot[i];
    }

    end = clock();
    time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    printf("Dot product result: %f\n", sum);
    printf("SIMD function took %f microseconds for array size %d \n", time_taken, ARRAY_SIZE);
<<<<<<< HEAD


    // --------------------- x86-64 version ----------------------------------

        // initialize  back sdot[i] to 0
    for (int i = 0; i < ARRAY_SIZE; i++)
        sdot[i] = 0.0f;

    //flush out cache
    x86dotProduct(ARRAY_SIZE, A, B, sdot);

    // fill in the host memory with data
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = i;
        B[i] = i;
        expected[i] = A[i] * B[i]; // compute the expected result on the CPU
    }

    // Measure execution time
    start = clock();

    x86dotProduct(ARRAY_SIZE, A, B, sdot);

    // verify the correctness of the dot product
    verifyDotProduct(sdot, expected);

    // finish up on the CPU side
    sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += sdot[i];
    }

    end = clock();
    time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    printf("Dot product result: %f\n", sum);
    printf("x86-64 function took %f microseconds for array size %d \n", time_taken, ARRAY_SIZE);
=======
    
>>>>>>> f35bcde2a6039e6a935b8c2f556fd38623ff0f03
    
    
    
    // free memory
    free(A);
    free(B);
    free(sdot);
    free(expected);

    return 0;
}
