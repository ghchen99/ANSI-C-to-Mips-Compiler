

#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-140
sw	$31,	136($sp)
sw	$zero,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
lw	$t1,	4($sp)
lw	$t1,	4($sp)
addi	$t1,$t1,-1
sw	$t1,	4($sp)
lw	$t0,	4($sp)
addiu	$t0,$t0,1
move	$2,	$t0


#stacksize is140
lw	$31,	136($sp)
addiu	$sp,	$sp,	140
j	$ra
nop
#finishing a function


.end	main
#finishing

