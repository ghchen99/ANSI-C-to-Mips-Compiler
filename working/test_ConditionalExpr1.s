

#start declaring a function
.global	notmain
.ent	notmain
.type	notmain,  @function
#finishing declaring a function

#start a function
notmain:
addiu	$sp,	$sp,	-312
sw	$31,	308($sp)
sw	$zero,	4($sp)
li	$t1,	1
sw	$t1,	4($sp)
sw	$zero,	8($sp)
li	$t1,	2
sw	$t1,	8($sp)
sw	$zero,	12($sp)
lw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	16($sp)
lw	$t1,	8($sp)
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_0
nop
lw	$t1,	8($sp)
b	_L_1
nop
_L_0:
lw	$t1,	4($sp)
_L_1:
sw	$t1,	4($sp)
lw	$t1,	12($sp)
lw	$t1,	4($sp)
sw	$t1,	24($sp)
lw	$t1,	8($sp)
sw	$t1,	28($sp)
lw	$t0,	24($sp)
lw	$t1,	28($sp)
slt	$t1,	$t1,	$t0
addiu	$t2,	$zero,	1
beq	$t1,	$t2,	_L_4
nop
lw	$t1,	8($sp)
b	_L_5
nop
_L_4:
lw	$t1,	4($sp)
_L_5:
sw	$t1,	12($sp)
lw	$t1,	4($sp)
sw	$t1,	32($sp)
lw	$t1,	12($sp)
sw	$t1,	36($sp)
lw	$t0,	32($sp)
lw	$t1,	36($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is312
lw	$31,	308($sp)
addiu	$sp,	$sp,	312
j	$ra
nop
#finishing a function


.end	notmain
#finishing

