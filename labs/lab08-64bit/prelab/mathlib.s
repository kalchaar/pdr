	;; Keenan Alchaar | ka5nt | 04/13/2021 | mathlib.s

	global product
	global power

	section .text

product:
	;; body | long x -> rdi | long y -> rsi
	xor	rax, rax
	xor	r10, r10
prd_start:
	cmp 	r10, rsi
	je 	prd_done
	add 	rax, rdi
	inc 	r10
	jmp 	prd_start
prd_done:
	ret

power:
	;; body | long x (base) -> rdi | long y (exp) ->  rsi
	xor	rax, rax
	mov	rax, 1
	cmp	rsi, 0		; if (exp == 0)
	je 	pw_done		; return 1;
	dec 	rsi		; else
	call	power		; return base*power(base, exp-1)
	mov	rsi, rax	; pow result -> rsi (param 2)
	call 	product 	; product(base, result of power)

pw_done:
	ret
