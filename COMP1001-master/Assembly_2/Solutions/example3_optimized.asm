; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

COMMENT!
Note. 
Here we need to rearrange the formula. This is because integer division 
in the current form would lead to wrong results. 
Rearranging the formula becomes:
(50xd + 50yc)/cd.
!
;try to apply integer division in x/c and y/d, the result will be zero as the quotient's value range is within 0<quotent<1. 
;however, using the above formula this problem is eliminated as the quotent's value ranges within 0-100, not 0-1

;THIS PROGRAM IS AN OPTIMIZED VERSION OF EXAMPLE #3 (it uses fewer instructions)

.data ; data segment
	; define your variables here
	x DWORD 35 ; this is x
	my_c DWORD 60 ; this is c. 'c' is a reserved word and thus I am not allowed to use it. Thus, I used my_c instead
	y DWORD 45 ; this is y
	d DWORD 55 ; this is d

	sum_term1 DWORD 0 ; variable to hold 50xd
	sum_term2 DWORD 0 ; varible to hold 50yc
	divisor DWORD 0 ; variable to hold cd
	quotient DWORD 0 ; division result
	remainder DWORD 0; division result
.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	; compute 50xd
	mov eax, 50
	mul x ; 50x the result is small enough to fit in eax only
	mul d ; 50xd 
	mov sum_term1, eax	; save 50xd
	; compute 50yc
	mov eax, 50
	mul y
	mul my_c
	mov sum_term2, eax ; save 50yc
	; compute divisor cd
	mov eax, d
	mul my_c
	mov divisor, eax
	; add sum_term1 with sum_term2
	mov eax, sum_term1
	add eax, sum_term2 ; eax has the total sum
	; compute division
	mov edx, 0 ; clear high part of divident
	div divisor
	mov quotient, eax
	mov remainder, edx

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling
