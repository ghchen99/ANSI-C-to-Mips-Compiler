

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-388
sw	$31,	384($sp)
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
sw	$t1,	36($sp)
lw	$t1,	8($sp)
sw	$t1,	40($sp)
li	$t1,	199
sw	$t1,	44($sp)
lw	$t0,	40($sp)
lw	$t1,	44($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$zero,	$t1
sw	$t1,	48($sp)
lw	$t0,	36($sp)
andi	$t0,	$t0,	1
lw	$t1,	48($sp)
andi	$t1,	$t1,	1
and	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_8
nop
b	_L_9
nop
_L_8:
lw	$t0,	8($sp)
move	$2,	$t0


#stacksize is388
lw	$31,	384($sp)
addiu	$sp,	$sp,	388
j	$ra
nop
#finishing a function


_L_9:
_L_5:
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
sw	$t1,	52($sp)
li	$t1,	0
sw	$t1,	56($sp)
lw	$t0,	52($sp)
lw	$t1,	56($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_16
nop
b	_L_17
nop
_L_16:
lw	$t1,	8($sp)
sw	$t1,	60($sp)
li	$t1,	0
sw	$t1,	64($sp)
lw	$t0,	60($sp)
lw	$t1,	64($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_20
nop
b	_L_21
nop
_L_20:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is388
lw	$31,	384($sp)
addiu	$sp,	$sp,	388
j	$ra
nop
#finishing a function


_L_21:
_L_17:
_L_1:


#stacksize is388
addiu	$sp,	$sp,	388
j	$ra
nop
.end	f
#finishing a function


#finishing

