

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-132
sw	$zero,	4($sp)
addi	$t1,	$zero,	234
sw	$t1,	4($sp)
sw	$zero,	8($sp)
lw	$t0,	8($sp)
move	$2,	$t0


#stacksize is132
addiu	$sp,	$sp,	132
j	$ra
nop
#finishing a function


#finishing

