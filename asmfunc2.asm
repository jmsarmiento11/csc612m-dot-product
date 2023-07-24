;Mark Jimbo Sarmiento, MSCS
section .text
bits 64
default rel	; []
global x86dotProduct

x86dotProduct:
; rcx = ARRAY_SIZE, rdx = A, r8 = B, r9 = sdot

L1:
	vmovss xmm1, [r8]		; ymm1 <-- scalar memory element, load 1 float
	vmovss xmm2, [rdx]		; ymm2 <-- scalar memory element, load 1 float
	vmulss xmm3, xmm1, xmm2
	vmovss [r9],xmm3
	add r8, 4
	add rdx, 4
	add r9, 4
	loop L1
ret

