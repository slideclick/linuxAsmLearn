	#PURPOSE:  Program to illustrate how functions work
	#          This program will compute the value of
	#          2^3 + 5^2
	#

	#Everything in the main program is stored in registers,
	#so the data section doesn't have anything.
	.section .data 

	.section .text

	.globl exit
	.type exit, @function
exit:

    nop

    movl $1, %eax

	movl 4(%esp), %ebx  #put first argument in %ebx

    int $0x80
	ret
