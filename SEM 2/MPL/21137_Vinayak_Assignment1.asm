;Name: Vinayak Jamadar
;Roll No: 21137
;Batch: F1
;Class: SE1

;This is .data section
section .data
	
	;Declaration and Defination of String str
	str: db "Enter 5 Names : ", 0xA
	
	;This will calculate the length of String str in len
	len: equ $-str
	
	;Declaration and Defination of String str1
	str1: db "5 Names are as follows : ", 0xA
	
	;This will calculate the length of String str1 in len1
	len1: equ $-str1
	
	cnt: db 0
	
	;This is Defination of Macro
	%macro print 2
		mov rax,1
		mov rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	
;This is .bss section	
section .bss

	name: resb 20
	
;This is .text section
section .text

	global _start
	
_start:
	
	;calling print Macro for string str and length len
	print str, len
	
	
	;loop for reading Names
	mov rbx, name
	mov byte[cnt], 0x5
	loop_for_reading:
		mov rax, 0
		mov rdi, 0
		mov rsi, rbx
		mov rdx, 17
		syscall
		add rbx, 17
		dec byte[cnt]
		jnz loop_for_reading
	
	
	;calling print Macro for string str1 and length len1
	print str1, len1
	
	
	;loop for printing Names
	mov rbx, name
	mov byte[cnt], 0x5
	loop_for_printing:
		mov rax, 1
		mov rdi, 1
		mov rsi, rbx
		mov rdx, 17
		syscall
		add rbx, 17
		dec byte[cnt]
		jnz loop_for_printing
	
	
	; System call to Exit Program
	mov rax,60
	mov rdi,60
	syscall