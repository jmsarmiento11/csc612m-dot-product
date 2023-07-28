# dotProduct

## A. Comparative execution time and analysis of the performance of the different kernels
The dot product program was implemented in four different approaches: C++, CUDA, x86-64, and SIMD YMM. Each approach was evaluated for its execution time and performance to compare their efficiency and identify the reasons for their differences.

In terms of execution time, as expected, the GPU Parallelized implementations (CUDA and SIMD) outperformed the other two sequential approaches (C++ and x86) significantly. CUDA and SIMD leverage the parallel processing capabilities of GPUs, which are designed for handling massive parallel tasks. By distributing the workload across numerous threads, these implementations exploit the full potential of the GPU, resulting in faster execution times compared to the other CPU-based approaches. The x86-64 implementation also showed decent performance but couldn't match the speed of CUDA. The C++ implementation without any optimization demonstrated the slowest execution time, as it utilizes a single CPU thread to compute the dot product sequentially.


### Comparative analysis of the execution times for each implementation for array size 2<<28
1. C++: Execution time = 58120164 microseconds (μs)
2. CUDA: Execution time = 2.12906 seconds = 2129060 microseconds (μs)
3. SIMD: Execution time = 57651444 microseconds (μs)
4. x86: Execution time = 51708873 microseconds (μs)

### Let's calculate the percentage differences:

For CUDA:
Percentage Difference = ((CUDA Execution Time - C++ Execution Time) / C++ Execution Time) * 100 = ((2129060 μs - 58120164 μs) / 58120164 μs) * 100 = -96.34%

For SIMD:
Percentage Difference = ((SIMD Execution Time - C++ Execution Time) / C++ Execution Time) * 100 = ((57651444 μs - 58120164 μs) / 58120164 μs) * 100 = -0.81%

For x86:
Percentage Difference = ((x86 Execution Time - C++ Execution Time) / C++ Execution Time) * 100 = ((51708873 μs - 58120164 μs) / 58120164 μs) * 100 = -10.99%

### Analysis:

1. The CUDA implementation shows a significant speedup of approximately 96.34% compared to the C++ implementation.
2. The SIMD implementation has a negligible speedup of approximately 0.81%. This result indicates that SIMD's parallel processing capabilities do not provide a significant advantage over the sequential C++ implementation for the particular problem or data size considered.
3. The x86 implementation shows a moderate speedup of approximately 10.99% compared to the C++ implementation. However, it is still less efficient than CUDA's massive parallelism.

The performance analysis reveals that CUDA's superiority is due to its massive parallelism. While the CPU-based approaches execute the dot product sequentially, CUDA's GPU parallelism allows it to perform simultaneous calculations on multiple elements of the arrays.

One overhead worth mentioning is the kernel invocation in the CUDA approach. When calling the CUDA kernel, there is an inherent overhead associated with launching threads and initializing the GPU computation environment. This overhead is relatively small for large data sets but can become significant for smaller data sizes. Additionally, data transfer between the host (CPU) and the device (GPU) incurs some overhead, especially when dealing with large arrays. 

Overall, the CUDA approach emerged as the clear winner in terms of execution time and performance, offering unparalleled speed and efficiency for the dot product computation.

## B. Screenshot of the program output with correctness check (C)
### For array size = 1<<20
![Colab C++ Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/03f139ce23d51edd731313e049b28522e46df035/Screenshot%202023-07-28%20211522.png)
### For array size = 2<<20
![Colab C++ Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/bc361940b29a41edd6a84560a7487d7545336341/C220.png)
### For array size = 2<<24
![Colab C++ Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/ee4ea04266261826c8cd28b5d1ebdff5148f933e/C224.png)
### For array size = 2<<28
![Colab C++ Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/7d8775604fb46d53d4c0d6700c8fb26a33f28e9b/C228.png)


## C. Screenshot of the program output with correctness check (C, x86-64, SIMD YMM register )
### For array size = 1<<20
![MVS Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/03f139ce23d51edd731313e049b28522e46df035/Screenshot%202023-07-28%20211705.png)
### For array size = 2<<20
![MVS Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/bc361940b29a41edd6a84560a7487d7545336341/MVS220.png)
### For array size = 2<<24
![MVS Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/ee4ea04266261826c8cd28b5d1ebdff5148f933e/MVS224.png)
### For array size = 2<<28
![MVS Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/9d017aa3ad862c94a728ce5d4d94243c751d78bb/MVS228.png)

## D. Screenshot of the program output with correctness check (CUDA)
### For array size = 1<<20
![Colab CUDA Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/03f139ce23d51edd731313e049b28522e46df035/Screenshot%202023-07-28%20211619.png)
### For array size = 2<<20
![Colab CUDA Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/bc361940b29a41edd6a84560a7487d7545336341/CUDA220.png)
### For array size = 2<<24
![Colab CUDA Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/ee4ea04266261826c8cd28b5d1ebdff5148f933e/CUDA224.png)
### For array size = 2<<28
![Colab CUDA Screenshot](https://github.com/jmsarmiento11/csc612m-dot-product/blob/7d8775604fb46d53d4c0d6700c8fb26a33f28e9b/CUDA228.png)

Link to Colab: https://colab.research.google.com/drive/1Gf16H5EYcCD5NkFDrtffc6wbc-MUppHT?usp=sharing
