

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-108
sw	$31,	104($sp)
sw	$zero,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is108
lw	$31,	104($sp)
addiu	$sp,	$sp,	108
j	$ra
nop
#finishing a function


.end	f
#finishing

