

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-348
sw	$31,	344($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
sw	$5,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
slt	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
lw	$t1,	8($sp)
sw	$t1,	20($sp)
li	$t1,	0
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_4
nop
b	_L_5
nop
_L_4:
lw	$t1,	8($sp)
sw	$t1,	28($sp)
li	$t1,	0
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
slt	$t1,	$t0,	$t1
xori	$t1,	$t1,	1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_8
nop
b	_L_9
nop
_L_8:
lw	$t0,	8($sp)
move	$2,	$t0


#stacksize is348
lw	$31,	344($sp)
addiu	$sp,	$sp,	348
j	$ra
nop
#finishing a function


_L_9:
_L_5:
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
sw	$t1,	36($sp)
li	$t1,	0
sw	$t1,	40($sp)
lw	$t0,	36($sp)
lw	$t1,	40($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_12
nop
b	_L_13
nop
_L_12:
lw	$t1,	8($sp)
sw	$t1,	44($sp)
li	$t1,	0
sw	$t1,	48($sp)
lw	$t0,	44($sp)
lw	$t1,	48($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_16
nop
b	_L_17
nop
_L_16:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is348
lw	$31,	344($sp)
addiu	$sp,	$sp,	348
j	$ra
nop
#finishing a function


_L_17:
_L_13:
_L_1:


#stacksize is348
addiu	$sp,	$sp,	348
j	$ra
nop
.end	f
#finishing a function


#finishing

