

#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-272
sw	$zero,	4($sp)
sw	$zero,	8($sp)
lw	$t1,	4($sp)
addi	$t1,	$zero,	0
sw	$t1,	4($sp)
_L_0:
lw	$t1,	4($sp)
sw	$t1,	12($sp)
addi	$t1,	$zero,	5
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
slt	$t1,	$t0,	$t1
addiu	$t2,	$zero,	1
bne	$t1,	$t2,	_L_2
nop
_L_1:
lw	$t1,	8($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
addi	$t1,	$zero,	1
sw	$t1,	24($sp)
lw	$t0,	20($sp)
lw	$t1,	24($sp)
add	$t1,	$t0,	$t1
sw	$t1,	8($sp)
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	28($sp)
addi	$t1,	$zero,	1
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
add	$t1,	$t0,	$t1
sw	$t1,	4($sp)
b	_L_0
_L_2:
lw	$t0,	8($sp)
move	$2,	$t0


#stacksize is272
addiu	$sp,	$sp,	272
j	$ra
nop
#finishing a function


.end	main
#finishing

