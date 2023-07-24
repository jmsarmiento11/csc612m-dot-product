;Mark Jimbo Sarmiento, MSCS
section .text
bits 64
default rel	; []
global SIMDdotProduct

SIMDdotProduct:
; rcx = ARRAY_SIZE, rdx = A, r8 = B, r9 = sdot
	shr rcx,3
L1:
	vmovdqu ymm1, [r8]		; ymm1 <-- 256-bits from memory pointed r8, float 32-bit  256/32=8 elements, load 8 floats
	vmovdqu ymm2, [rdx]		; ymm2 <-- 256-bits from memory pointed rdx, float 32-bit  256/32=8 elements, load 8 floats
	vmulps ymm3, ymm1, ymm2
	vmovdqu [r9],ymm3
	add r8, 32
	add rdx, 32
	add r9, 32
	loop L1
ret

