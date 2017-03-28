

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-184
sw	$31,	180($sp)
sw	$zero,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	9
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
addiu	$t0,	$zero,	99
move	$2,	$t0


#stacksize is184
lw	$31,	180($sp)
addiu	$sp,	$sp,	184
j	$ra
nop
#finishing a function


b	_L_1
nop
_L_0:
addiu	$t0,	$zero,	100
move	$2,	$t0


#stacksize is184
lw	$31,	180($sp)
addiu	$sp,	$sp,	184
j	$ra
nop
#finishing a function


_L_1:
.end	f
#finishing

