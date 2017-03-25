

#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-188
sw	$zero,	4($sp)
addi	$t1,	$zero,	10
sw	$t1,	4($sp)
sw	$zero,	8($sp)
addi	$t1,	$zero,	10
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
b	_L_1
nop
_L_0:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is188
addiu	$sp,	$sp,	188
j	$ra
nop
#finishing a function


_L_1:
addiu	$t0,	$zero,	11
move	$2,	$t0


#stacksize is188
addiu	$sp,	$sp,	188
j	$ra
nop
#finishing a function


.end	main
#finishing

