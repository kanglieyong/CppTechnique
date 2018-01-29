# %edi - save the checking item index
# %ebx - current finding max item
# %eax - current item

# use the memory position
#
# data_items
#

.section .data

data_items:
 .long 3,67,34,222,45,75,54,34,44,33,33,11,66,0

 .section .text

 .globl _start
_start:
 movl $0, %edi                  # move 0 to index 
 movl data_items(,%edi,4), %eax # load the first byte of the data_item
 movl %eax, %ebx                # because this is the first item, %eax is the max item

start_loop:                     # begin loop
 cmpl $0, %eax                  # check if the position is the end of the data
 je loop_exit
 incl %edi                      # load next value
 movl data_items(,%edi,4), %eax
 cmpl %ebx, %eax
 jle start_loop

 movl %eax, %ebx

 jmp start_loop

loop_exit:
  movl $1, %eax
  int $0x80
