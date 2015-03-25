	#PURPOSE:  Program to illustrate how functions work
	#          This program will compute the value of
	#          2^3 + 5^2
	#

	#Everything in the main program is stored in registers,
	#so the data section doesn't have anything.
	.section .data 

	.section .text

	.globl print
	.type print, @function
print:

    nop

    movl $4, %eax
    movl $1, %ebx
	movl 4(%esp), %ecx  #put first argument in %ebx
    movl $12, %edx
    int $0x80
	ret
