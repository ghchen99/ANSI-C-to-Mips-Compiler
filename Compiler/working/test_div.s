

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
li	$t1,	100
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	99
sw	$t1,	8($sp)
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
div	$zero,	$t0,	$t1
mflo	$t1
sw	$t1,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is184
lw	$31,	180($sp)
addiu	$sp,	$sp,	184
j	$ra
nop
#finishing a function


.end	f
#finishing

