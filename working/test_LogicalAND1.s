

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-308
sw	$31,	304($sp)
sw	$zero,	4($sp)
li	$t1,	1
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	1
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
li	$t1,	1
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
sw	$t1,	20($sp)
lw	$t1,	8($sp)
sw	$t1,	24($sp)
li	$t1,	0
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
slt	$t1,	$t0,	$t1
xori	$t1,	$t1,	1
sw	$t1,	32($sp)
lw	$t0,	20($sp)
andi	$t0,	$t0,	1
lw	$t1,	32($sp)
andi	$t1,	$t1,	1
and	$t1,	$t0,	$t1
sw	$t1,	36($sp)
lw	$t1,	4($sp)
sw	$t1,	40($sp)
li	$t1,	1
sw	$t1,	44($sp)
lw	$t0,	40($sp)
lw	$t1,	44($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
sw	$t1,	48($sp)
lw	$t1,	8($sp)
sw	$t1,	52($sp)
li	$t1,	0
sw	$t1,	56($sp)
lw	$t0,	52($sp)
lw	$t1,	56($sp)
slt	$t1,	$t1,	$t0
sw	$t1,	60($sp)
lw	$t0,	48($sp)
andi	$t0,	$t0,	1
lw	$t1,	60($sp)
andi	$t1,	$t1,	1
and	$t1,	$t0,	$t1
sw	$t1,	64($sp)
lw	$t0,	36($sp)
andi	$t0,	$t0,	1
lw	$t1,	64($sp)
andi	$t1,	$t1,	1
and	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
b	_L_1
nop
_L_0:
addiu	$t0,	$zero,	100
move	$2,	$t0


#stacksize is308
lw	$31,	304($sp)
addiu	$sp,	$sp,	308
j	$ra
nop
#finishing a function


_L_1:
addiu	$t0,	$zero,	0
move	$2,	$t0


#stacksize is308
lw	$31,	304($sp)
addiu	$sp,	$sp,	308
j	$ra
nop
#finishing a function


.end	f
#finishing

