

#start declaring a function
.global	ff
.ent	ff
.type	ff,  @function
#finishing declaring a function

#start a function
ff:
addiu	$sp,	$sp,	-284
sw	$31,	280($sp)
sw	$zero,	4($sp)
sw	$zero,	8($sp)
li	$t1,	2
sw	$t1,	8($sp)
sw	$zero,	12($sp)
li	$t1,	0
sw	$t1,	12($sp)
lw	$t1,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
_L_0:
lw	$t1,	4($sp)
sw	$t1,	16($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
bne	$t1,	$t2,	_L_2
nop
_L_1:
lw	$t1,	4($sp)
move	$t3,	$t1
li	$t1,	1
sub	$t1,	$t3,	$t1
sw	$t1,	4($sp)
lw	$t1,	12($sp)
lw	$t1,	12($sp)
sw	$t1,	24($sp)
li	$t1,	1
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
add	$t1,	$t0,	$t1
sw	$t1,	12($sp)
b	_L_0
_L_2:
lw	$t0,	12($sp)
move	$2,	$t0


#stacksize is284
lw	$31,	280($sp)
addiu	$sp,	$sp,	284
j	$ra
nop
#finishing a function


.end	ff
#finishing

