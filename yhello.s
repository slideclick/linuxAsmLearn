	#This will wrong. Use strace to see where wrong
    
    #PURPOSE:  Simple program that exits and returns a
	#          status code back to the Linux kernel
	#

	#INPUT:    none
	#

	#OUTPUT:   returns a status code.  This can be viewed
	#          by typing
	#
	#          echo $?
	#
	#          after running the program
	#

	#VARIABLES:
	#          %eax holds the system call number 
	#          (this is always the case)
	#
	#          %ebx holds the return status 
	#
	.section .data
HelloMsg:
    .ascii "hwllo\n\0"
	.section .text
	.globl _start
_start:

    nop
    movl $4, %eax
    movl $1, %ebx
    movl HelloMsg, %ecx
    movl $6, %edx
    int $0x80
    
	movl $1, %eax      # this is the linux kernel command  
	                   # number (system call) for exiting 
	                   # a program

	movl $2, %ebx      # this is the status number we will
	                   # return to the operating system.
	                   # Change this around and it will
	                   # return different things to 
	                   # echo $?

	int $0x80          # this wakes up the kernel to run
	                   # the exit command

