	.file	"q2.c"
	.text
	.globl	add
	.type	add, @function
add:
	movl	%edi, -20(%rsp)
	movl	%esi, -24(%rsp)
	movl	-20(%rsp), %edx
	movl	-24(%rsp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rsp)
	movl	-4(%rsp), %eax
	ret
	.size	add, .-add
	.section	.rodata
	.align 8
.LC0:
	.string	"Result of adding %ld and %d is %d.\n"
	.text
	.globl	main
	.type	main, @function
main:
	subq	$24, %rsp
	movq	$7, 8(%rsp)
	movw	$12, 6(%rsp)
	movswl	6(%rsp), %eax
	movq	8(%rsp), %rdx
	movl	%eax, %esi
	movl	%edx, %edi
	call	add
	movl	%eax, (%rsp)
	movswl	6(%rsp), %edx
	movl	(%rsp), %ecx
	movq	8(%rsp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$24, %rsp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
