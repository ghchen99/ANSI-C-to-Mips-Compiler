

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-220
sw	$31,	216($sp)
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
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	20($sp)
li	$t1,	100
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
add	$t1,	$t0,	$t1
sw	$t1,	4($sp)
_L_1:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is220
lw	$31,	216($sp)
addiu	$sp,	$sp,	220
j	$ra
nop
#finishing a function


.end	f
#finishing

