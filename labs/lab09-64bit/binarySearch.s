	;; Keenan Alchaar | ka5nt | 04/23/2021 | binarySearch.s (postlab 09)

	global binarySearch

	section .text

	;; Parameter 1 (rdi): int* arr 
	;; Parameter 2 (rsi): int left
	;; Parameter 3 (rdx): int right
	;; Parameter 4 (rcx): int target
	;; Variable 1 (r10): int mid
	;; 32-bit registers used extensively since all params and vars are ints
binarySearch:
	xor	rax, rax
	xor	r10, r10

binarySearch_start:
	;; while (low <= high)
	cmp	esi, edx
	jg	notFound
	;; int mid = (low + high) / 2
	mov	r10d, esi
	add	r10d, edx
	shr	r10d, 1
	;; if (a[mid] < key)
	cmp	[edi + 4*r10d], ecx
	jl	searchRight
	;; if (a[mid] > key)
	cmp	[edi + 4*r10d], ecx
	jg	searchLeft
	;; else
	jmp	found
	
searchRight:
	;; low = mid + 1
	mov	esi, r10d
	inc	esi
	jmp	binarySearch_start
	
searchLeft:
	;; high = mid - 1
	mov	edx, r10d
	dec	edx
	jmp	binarySearch_start

found:
	mov	eax, r10d
	ret

notFound:
	mov	eax, -1
	ret
