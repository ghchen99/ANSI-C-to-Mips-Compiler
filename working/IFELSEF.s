

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-204
sw	$31,	200($sp)
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
lw	$t0,	8($sp)
move	$2,	$t0


#stacksize is204
lw	$31,	200($sp)
addiu	$sp,	$sp,	204
j	$ra
nop
#finishing a function


b	_L_1
nop
_L_0:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is204
lw	$31,	200($sp)
addiu	$sp,	$sp,	204
j	$ra
nop
#finishing a function


_L_1:


#stacksize is204
addiu	$sp,	$sp,	204
j	$ra
nop
.end	f
#finishing a function


#finishing

