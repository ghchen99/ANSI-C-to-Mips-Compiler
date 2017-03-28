

#start declaring a function
.global	x
.ent	x
.type	x,  @function
#finishing declaring a function

#start a function
x:
addiu	$sp,	$sp,	-328
sw	$31,	324($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
sw	$5,	8($sp)
sw	$6,	12($sp)
sw	$7,	16($sp)
lw	$t1,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
li	$t1,	2
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
b	_L_1
nop
_L_0:
lw	$t1,	8($sp)
li	$t1,	10
sw	$t1,	8($sp)
_L_1:
lw	$t1,	4($sp)
sw	$t1,	28($sp)
lw	$t1,	8($sp)
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
add	$t1,	$t0,	$t1
sw	$t1,	36($sp)
lw	$t1,	12($sp)
sw	$t1,	40($sp)
lw	$t0,	36($sp)
lw	$t1,	40($sp)
add	$t1,	$t0,	$t1
sw	$t1,	44($sp)
lw	$t1,	16($sp)
sw	$t1,	48($sp)
lw	$t0,	44($sp)
lw	$t1,	48($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is328
lw	$31,	324($sp)
addiu	$sp,	$sp,	328
j	$ra
nop
#finishing a function




#stacksize is328
addiu	$sp,	$sp,	328
j	$ra
nop
.end	x
#finishing a function


#finishing

