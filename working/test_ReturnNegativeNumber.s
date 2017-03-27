

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-172
sw	$31,	168($sp)
sw	$zero,	4($sp)
li	$t1,	234
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	1234
sw	$t1,	8($sp)
sw	$zero,	12($sp)
li	$t1,	5647
sw	$t1,	12($sp)
li	$t0,	-33
move	$2,	$t0


#stacksize is172
lw	$31,	168($sp)
addiu	$sp,	$sp,	172
j	$ra
nop
#finishing a function


.end	f
#finishing

