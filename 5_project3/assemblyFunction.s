	.arch msp430g2553
	.p2align 1,0
	.text


	.global buzz

jmp_table:
	.word case_0
	.word case_1
	.word case_2
	.word case_3
	.word case_5
	.word case_5
	.word case_6
	.word case_7
	.word case_8
	.word case_9
	.word case_10
	.word case_11

buzz:	add r12, r12
	mov jump_table(r12), pc

case_1:	
off:
	pop r0
