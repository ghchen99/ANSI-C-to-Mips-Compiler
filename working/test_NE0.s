

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-192
sw	$31,	188($sp)
sw	$zero,	4($sp)
li	$t1,	8
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	7
sw	$t1,	8($sp)
sw	$zero,	12($sp)
li	$t1,	8
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t1,	4($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$zero,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is192
lw	$31,	188($sp)
addiu	$sp,	$sp,	192
j	$ra
nop
#finishing a function


.end	f
#finishing

