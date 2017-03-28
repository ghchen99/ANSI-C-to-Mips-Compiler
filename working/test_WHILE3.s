

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-188
sw	$31,	184($sp)
sw	$zero,	4($sp)
li	$t1,	1
sw	$t1,	4($sp)
_L_0:
lw	$t1,	4($sp)
sw	$t1,	8($sp)
li	$t1,	3
sw	$t1,	12($sp)
lw	$t0,	8($sp)
lw	$t1,	12($sp)
slt	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
bne	$t1,	$t2,	_L_2
nop
_L_1:
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	16($sp)
li	$t1,	1
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
add	$t1,	$t0,	$t1
sw	$t1,	4($sp)
b	_L_0
_L_2:
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is188
lw	$31,	184($sp)
addiu	$sp,	$sp,	188
j	$ra
nop
#finishing a function


.end	f
#finishing

