#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-10000
sw	$zero,	4($sp)
addi	$t1,	$zero,	100
sw	$t1,	4($sp)
sw	$zero,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
addi	$t1,	$zero,	10
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
mult	$t1,	$t0
mflo	$t1
sw	$t1,	20($sp)
addi	$t1,	$zero,	3
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
div	$t1,	$t0
mfhi	$t1
sw	$t1,	28($sp)
addi	$t1,	$zero,	5
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
div	$t1,	$t0
mfhi	$t1
sw	$t1,	8($sp)
lw	$t0,	8($sp)
move	$2,	$t0
addiu	$sp,	$sp,	+10000
j	$ra
nop
#finishing a function


#finishing
