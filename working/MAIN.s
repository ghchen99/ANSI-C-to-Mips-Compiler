

#start declaring a function
.global	x
.ent	x
.type	x,  @function
#finishing declaring a function

#start a function
x:
addiu	$sp,	$sp,	-180
sw	$31,	176($sp)
addiu	$t0,	$zero,	100
move	$2,	$t0


#stacksize is180
lw	$31,	176($sp)
addiu	$sp,	$sp,	180
j	$ra
nop
#finishing a function


.end	x


#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-180
sw	$31,	176($sp)
li	$t1,	110
sw	$t1,	8($sp)
lw	$t5,	%got(x)($28)
nop
move	$25,	$t5
jalr	$25
nop
move	$t1,	$2
sw	$t1,	12($sp)
lw	$t0,	8($sp)
lw	$t1,	12($sp)
xor	$t1,	$t0,	$t1
sltu	$t1,	$t1,	1
move	$t0,	$t1
move	$2,	$t0


#stacksize is180
lw	$31,	176($sp)
addiu	$sp,	$sp,	180
j	$ra
nop
#finishing a function


.end	main
#finishing

