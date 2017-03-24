

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-10000
sw	$zero,	4($sp)
addi	$t1,	$zero,	100
sw	$t1,	4($sp)
sw	$zero,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	8($sp)
sw	$zero,	12($sp)
addi	$t1,	$zero,	1
sw	$t1,	16($sp)
addi	$t1,	$zero,	1
sw	$t1,	20($sp)
lw	$t0,	16($sp)
lw	$t1,	20($sp)
mult	$t1,	$t0
mflo	$t1
sw	$t1,	12($sp)
sw	$zero,	24($sp)
addi	$t1,	$zero,	7
sw	$t1,	28($sp)
addi	$t1,	$zero,	3
sw	$t1,	32($sp)
lw	$t0,	28($sp)
lw	$t1,	32($sp)
div	$t1,	$t0
mflo	$t1
sw	$t1,	24($sp)
sw	$zero,	36($sp)
li	$t0,	1231231
sw	$t1,	36($sp)
sw	$zero,	40($sp)
li	$t0,	78987
sw	$t1,	40($sp)
sw	$zero,	44($sp)
li	$t0,	12344312
sw	$t1,	44($sp)
sw	$zero,	48($sp)
sw	$zero,	52($sp)
sw	$zero,	56($sp)
sw	$zero,	60($sp)
sw	$zero,	64($sp)
lw	$t1,	4($sp)
lw	$t1,	8($sp)
lw	$t1,	12($sp)
lw	$t1,	24($sp)
lw	$t1,	36($sp)
lw	$t1,	40($sp)
lw	$t1,	44($sp)
lw	$t1,	48($sp)
lw	$t1,	52($sp)
lw	$t1,	56($sp)
lw	$t1,	60($sp)
lw	$t1,	64($sp)
addi	$t1,	$zero,	1
sw	$t1,	64($sp)
sw	$t1,	60($sp)
sw	$t1,	56($sp)
sw	$t1,	52($sp)
sw	$t1,	48($sp)
sw	$t1,	44($sp)
sw	$t1,	40($sp)
sw	$t1,	36($sp)
sw	$t1,	24($sp)
sw	$t1,	12($sp)
sw	$t1,	8($sp)
sw	$t1,	4($sp)
lw	$t1,	4($sp)
sw	$t1,	68($sp)
lw	$t1,	8($sp)
sw	$t1,	72($sp)
lw	$t0,	68($sp)
lw	$t1,	72($sp)
add	$t1,	$t0,	$t1
sw	$t1,	76($sp)
lw	$t1,	12($sp)
sw	$t1,	80($sp)
lw	$t0,	76($sp)
lw	$t1,	80($sp)
add	$t1,	$t0,	$t1
sw	$t1,	84($sp)
lw	$t1,	24($sp)
sw	$t1,	88($sp)
lw	$t0,	84($sp)
lw	$t1,	88($sp)
add	$t1,	$t0,	$t1
sw	$t1,	92($sp)
lw	$t1,	36($sp)
sw	$t1,	96($sp)
lw	$t0,	92($sp)
lw	$t1,	96($sp)
add	$t1,	$t0,	$t1
sw	$t1,	100($sp)
lw	$t1,	40($sp)
sw	$t1,	104($sp)
lw	$t0,	100($sp)
lw	$t1,	104($sp)
add	$t1,	$t0,	$t1
sw	$t1,	108($sp)
lw	$t1,	44($sp)
sw	$t1,	112($sp)
lw	$t0,	108($sp)
lw	$t1,	112($sp)
add	$t1,	$t0,	$t1
sw	$t1,	116($sp)
lw	$t1,	48($sp)
sw	$t1,	120($sp)
lw	$t0,	116($sp)
lw	$t1,	120($sp)
add	$t1,	$t0,	$t1
sw	$t1,	124($sp)
lw	$t1,	52($sp)
sw	$t1,	128($sp)
lw	$t0,	124($sp)
lw	$t1,	128($sp)
add	$t1,	$t0,	$t1
sw	$t1,	132($sp)
lw	$t1,	56($sp)
sw	$t1,	136($sp)
lw	$t0,	132($sp)
lw	$t1,	136($sp)
add	$t1,	$t0,	$t1
sw	$t1,	140($sp)
lw	$t1,	60($sp)
sw	$t1,	144($sp)
lw	$t0,	140($sp)
lw	$t1,	144($sp)
add	$t1,	$t0,	$t1
sw	$t1,	148($sp)
lw	$t1,	64($sp)
sw	$t1,	152($sp)
lw	$t0,	148($sp)
lw	$t1,	152($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0
addiu	$sp,	$sp,	+10000
j	$ra
nop
#finishing a function


#finishing

