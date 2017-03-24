

#start declaring a function
.global	ffff
.ent	ffff
.type	ffff,  @function
#finishing declaring a function

#start a function
ffff:
addiu	$sp,	$sp,	-10000
sw	$zero,	4($sp)
lw	$t1,	4($sp)
addi	$t1,	$zero,	10
sw	$t1,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0
addiu	$sp,	$sp,	+10000
j	$ra
nop
#finishing a function


#finishing

