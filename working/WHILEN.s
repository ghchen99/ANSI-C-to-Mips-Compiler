

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-364
sw	$31,	360($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
sw	$5,	8($sp)
sw	$zero,	12($sp)
li	$t1,	0
sw	$t1,	12($sp)
_L_0:
lw	$t1,	4($sp)
sw	$t1,	16($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$zero,	$t1
addiu	$t2,	$zero,	1
bne	$t1,	$t2,	_L_2
nop
_L_1:
lw	$t1,	12($sp)
sw	$t1,	24($sp)
li	$t1,	0
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
slt	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_5
nop
b	_L_6
nop
_L_5:
addiu	$t0,	$zero,	0
move	$2,	$t0


#stacksize is364
lw	$31,	360($sp)
addiu	$sp,	$sp,	364
j	$ra
nop
#finishing a function


_L_6:
lw	$t1,	12($sp)
lw	$t1,	12($sp)
sw	$t1,	32($sp)
li	$t1,	1
sw	$t1,	36($sp)
lw	$t0,	32($sp)
lw	$t1,	36($sp)
add	$t1,	$t0,	$t1
sw	$t1,	12($sp)
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	40($sp)
li	$t1,	1
sw	$t1,	44($sp)
lw	$t0,	40($sp)
lw	$t1,	44($sp)
add	$t1,	$t0,	$t1
sw	$t1,	4($sp)
b	_L_0
_L_2:
lw	$t0,	12($sp)
move	$2,	$t0


#stacksize is364
lw	$31,	360($sp)
addiu	$sp,	$sp,	364
j	$ra
nop
#finishing a function




#stacksize is364
addiu	$sp,	$sp,	364
j	$ra
nop
.end	f
#finishing a function


#finishing

