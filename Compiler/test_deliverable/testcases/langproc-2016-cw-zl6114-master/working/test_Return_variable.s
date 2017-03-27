

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-172
sw	$zero,	4($sp)
addi	$t1,	$zero,	10
sw	$t1,	4($sp)
sw	$zero,	8($sp)
addi	$t1,	$zero,	245
sw	$t1,	8($sp)
sw	$zero,	12($sp)
addi	$t1,	$zero,	1221
sw	$t1,	12($sp)
lw	$t0,	12($sp)
move	$2,	$t0


#stacksize is172
addiu	$sp,	$sp,	172
j	$ra
nop
#finishing a function


.end	f
#finishing

