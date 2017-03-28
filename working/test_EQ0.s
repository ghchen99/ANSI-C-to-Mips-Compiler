

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-212
sw	$31,	208($sp)
sw	$zero,	4($sp)
li	$t1,	8
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	8
sw	$t1,	8($sp)
sw	$zero,	12($sp)
li	$t1,	1
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t1,	4($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
sw	$t1,	24($sp)
lw	$t1,	12($sp)
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
move	$t0,	$t1
move	$2,	$t0


#stacksize is212
lw	$31,	208($sp)
addiu	$sp,	$sp,	212
j	$ra
nop
#finishing a function


.end	f
#finishing

