	.file	"q1.c"
	.text
	.globl	func
	.type	func, @function
func:
	movl	$42, -12(%rsp)
	movl	$0, -4(%rsp)
	movl	$0, -8(%rsp)
	jmp	.L2
.L3:
	movl	-8(%rsp), %eax
	addl	%eax, -4(%rsp)
	addl	$1, -8(%rsp)
.L2:
	movl	-8(%rsp), %eax
	cmpl	-12(%rsp), %eax
	jl	.L3
	movl	-4(%rsp), %eax
	ret
	.size	func, .-func
	.globl	main
	.type	main, @function
main:
	movl	$0, %eax
	call	func
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
