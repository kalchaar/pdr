	;; Keenan Alchaar | ka5nt | 04/16/2021 | linearSearch.s

	global linearSearch
	
	section .text
	
	;; Param 1 -> pointer to the array | rdi
	;; Param 2 -> size of the array    | rsi
	;; Param 3 -> search target        | rdx
	;; other variables: int counter    | r10
linearSearch:
	xor	r10, r10 	; zero the counter
searchLoop:
	cmp	rsi, r10	; compare the counter to the size of the array
	je 	search_notFound	; if counter == size, the target is not in the array
	
	cmp	edx, [edi + 4*r10d] ; iterate through the array in intervals of 4 bytes 
	je 	search_Found	    ; if arr[i] = target, the target has been found
	
	inc 	r10		    ; counter++
	jmp 	searchLoop	    ; continue searching
search_notFound:
	mov 	rax, -1		; -1 for no target
	ret 			; return -1
search_Found:
	mov	rax, r10 	; index held in the counter, r10
	ret 			; return index
