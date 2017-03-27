

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-140
sw	$zero,	4($sp)
addi	$t1,	$zero,	10
sw	$t1,	4($sp)
sw	$zero,	8($sp)
addi	$t1,	$zero,	245
sw	$t1,	8($sp)
addiu	$t0,	$zero,	255
move	$2,	$t0


#stacksize is140
addiu	$sp,	$sp,	140
j	$ra
nop
#finishing a function


.end	f
#finishing

