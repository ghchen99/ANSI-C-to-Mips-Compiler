

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-268
sw	$31,	264($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	8($sp)
li	$t1,	10
sw	$t1,	12($sp)
lw	$t0,	8($sp)
lw	$t1,	12($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
move	$t3,	$t1
li	$t1,	10
mult	$t1,	$t3
mflo	$t1
sw	$t1,	4($sp)
lw	$t1,	4($sp)
move	$t3,	$t1
li	$t1,	10
sub	$t1,	$t3,	$t1
sw	$t1,	4($sp)
lw	$t1,	4($sp)
move	$t3,	$t1
li	$t1,	10
add	$t1,	$t3,	$t1
sw	$t1,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is268
lw	$31,	264($sp)
addiu	$sp,	$sp,	268
j	$ra
nop
#finishing a function


_L_1:
addiu	$t0,	$zero,	10
move	$2,	$t0


#stacksize is268
lw	$31,	264($sp)
addiu	$sp,	$sp,	268
j	$ra
nop
#finishing a function




#stacksize is268
addiu	$sp,	$sp,	268
j	$ra
nop
.end	f
#finishing a function


#finishing

