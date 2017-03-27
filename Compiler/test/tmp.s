

#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-160
sw	$31,	156($sp)
sw	$zero,	4($sp)
li	$t1,	8
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	3
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
div	$zero,	$t0,	$t1
mfhi	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is160
lw	$31,	156($sp)
addiu	$sp,	$sp,	160
j	$ra
nop
#finishing a function


.end	main
#finishing

