//Mark Jimbo Sarmiento, MSCS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
            printf("Verification failed at index %d\n", i);
            return;
        }
    }
    printf("Verification successful\n");
}

int main()
{
    float* A = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* B = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* sdot = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* expected = (float*)malloc(ARRAY_SIZE * sizeof(float));

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

    // free memory
    free(A);
    free(B);
    free(sdot);
    free(expected);

    return 0;
}
