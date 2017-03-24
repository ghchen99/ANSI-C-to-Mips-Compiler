#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-10000
sw	$zero,	4($sp)
addi	$t1,	$zero,	10
sw	$t1,	4($sp)
sw	$zero,	8($sp)
addi	$t1,	$zero,	30
sw	$t1,	8($sp)
sw	$zero,	12($sp)
lw	$t1,	4($sp)
sw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	16($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
add	$t1,	$t0,	$t1
sw	$t1,	24($sp)
lw	$t1,	12($sp)
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0
addiu	$sp,	$sp,	+10000
j	$ra
nop
#finishing a function


#finishing
