	;; Keenan Alchaar | ka5nt | 04/19/2021 | threexplusone.s

	global threexplusone

	section .text
	
threexplusone:
	;; long x -> rdi | number of steps -> rax (return)
	xor	rax, rax 	; zero rax on successive calls
threexplusone_check:	
	cmp 	rdi, 1		; check if x = 1, ret if true
	je 	collatz_end
	test	rdi, 1		; check if even/odd parity
	jz	collatz_even
	
collatz_odd:
	lea	rdi, [2*rdi+rdi+1] ; 2*rdi + rdi should be faster than 3*rdi; "lea" instruction condenses the operations nicely
	inc	rax		   ; + 1 step
	call 	threexplusone_check
	ret
	
collatz_even:
	shr	rdi, 1 		; divide by 2 with a single right shift
	inc 	rax 		; + 1 step
	call 	threexplusone_check
	
collatz_end:
	ret
