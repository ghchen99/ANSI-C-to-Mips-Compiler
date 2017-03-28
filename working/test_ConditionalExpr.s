

#start declaring a function
.global	notmain
.ent	notmain
.type	notmain,  @function
#finishing declaring a function

#start a function
notmain:
addiu	$sp,	$sp,	-180
sw	$31,	176($sp)
sw	$zero,	4($sp)
li	$t1,	1
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	2
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t1,	8($sp)
sw	$t1,	16($sp)
lw	$t0,	12($sp)
lw	$t1,	16($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
lw	$t0,	8($sp)
b	_L_1
nop
_L_0:
lw	$t0,	4($sp)
_L_1:
move	$2,	$t0


#stacksize is180
lw	$31,	176($sp)
addiu	$sp,	$sp,	180
j	$ra
nop
#finishing a function


.end	notmain
#finishing

