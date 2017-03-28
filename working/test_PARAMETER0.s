

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-244
sw	$31,	240($sp)
#printing out ParameterDeclare
sw	$4,	4($sp)
sw	$5,	8($sp)
sw	$6,	12($sp)
sw	$7,	16($sp)
lw	$t1,	4($sp)
sw	$t1,	20($sp)
lw	$t1,	8($sp)
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
add	$t1,	$t0,	$t1
sw	$t1,	28($sp)
lw	$t1,	12($sp)
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
add	$t1,	$t0,	$t1
sw	$t1,	36($sp)
lw	$t1,	16($sp)
sw	$t1,	40($sp)
lw	$t0,	36($sp)
lw	$t1,	40($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is244
lw	$31,	240($sp)
addiu	$sp,	$sp,	244
j	$ra
nop
#finishing a function




#stacksize is244
addiu	$sp,	$sp,	244
j	$ra
nop
.end	f
#finishing a function


#finishing

