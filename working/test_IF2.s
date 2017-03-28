

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-404
sw	$31,	400($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
sw	$5,	8($sp)
sw	$6,	12($sp)
sw	$7,	16($sp)
lw	$t1,	4($sp)
sw	$t1,	20($sp)
li	$t1,	0
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
li	$t1,	1
sw	$t1,	4($sp)
_L_1:
lw	$t1,	8($sp)
sw	$t1,	28($sp)
li	$t1,	0
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_4
nop
b	_L_5
nop
_L_4:
lw	$t1,	8($sp)
li	$t1,	2
sw	$t1,	8($sp)
_L_5:
lw	$t1,	12($sp)
sw	$t1,	36($sp)
li	$t1,	0
sw	$t1,	40($sp)
lw	$t0,	36($sp)
lw	$t1,	40($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_8
nop
b	_L_9
nop
_L_8:
lw	$t1,	12($sp)
li	$t1,	2
sw	$t1,	12($sp)
_L_9:
lw	$t1,	4($sp)
sw	$t1,	44($sp)
lw	$t1,	8($sp)
sw	$t1,	48($sp)
lw	$t0,	44($sp)
lw	$t1,	48($sp)
add	$t1,	$t0,	$t1
sw	$t1,	52($sp)
lw	$t1,	12($sp)
sw	$t1,	56($sp)
lw	$t0,	52($sp)
lw	$t1,	56($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is404
lw	$31,	400($sp)
addiu	$sp,	$sp,	404
j	$ra
nop
#finishing a function




#stacksize is404
addiu	$sp,	$sp,	404
j	$ra
nop
.end	f
#finishing a function


#finishing

